#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SAMPLES 64
#define VEC_SIZE 1024
#define DATASET SAMPLES *VEC_SIZE

// int compare(const void *a, const void *b)
// {
//     return (*(int *)a - *(int *)b);
// }

#pragma oss task device(smp) inout([SAMPLES] arr)
void qsort_task(int *arr)
{
    // qsort(c, SAMPLES, sizeof(int), compare);
    for (int i = 0; i < SAMPLES - 1; i++)
    {
        for (int j = 0; j < SAMPLES - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

#pragma oss task device(fpga) in([DATASET] a, [DATASET] b)inout([SAMPLES] c, [SAMPLES] d)
void dotprod_task(int *a, int *b, int *c, int *d)
{
    for (int i = 0; i < SAMPLES; i++)
    {
        for (int j = 0; j < VEC_SIZE; j++)
        {
            c[i] += a[i * VEC_SIZE + j] * b[i * VEC_SIZE + j];
        }
    }

    qsort_task(c);
#pragma oss taskwait

    for (int i = 0; i < SAMPLES; i++)
    {
        d[i] = c[i] - d[i];
    }
}

int main()
{
    int a[DATASET];
    int b[DATASET];
    int c[SAMPLES];
    int d[SAMPLES];

    srand(42);
    for (int i = 0; i < DATASET; i++)
    {
        a[i] = rand() % 16;
        b[i] = rand() % 16;
    }
    for (int i = 0; i < SAMPLES; i++)
    {
        c[i] = 0;
        d[i] = 54415;
    }

    dotprod_task(a, b, c, d);
#pragma oss taskwait

    for (int i = 0; i < SAMPLES; i++)
    {
        printf("c[%d] = %d, d[%d] = %d\n", i, c[i], i, d[i]);
    }

    return 0;
}