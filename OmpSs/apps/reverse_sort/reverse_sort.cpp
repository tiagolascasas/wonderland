#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SAMPLES 64
#define VEC_SIZE 1024

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void qsort_task(int *res)
{
    qsort(res, 2048, sizeof(int), compare);
}

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
}

int main()
{
    int a[SAMPLES * VEC_SIZE];
    int b[SAMPLES * VEC_SIZE];
    int c[SAMPLES];
    int d[SAMPLES];

    srand(42);
    for (int i = 0; i < SAMPLES * VEC_SIZE; i++)
    {
        a[i] = rand() % 10;
        b[i] = rand() % 10;
    }
    memset(res, 0, SAMPLES * sizeof(int));

    dotprod_task(a, b, c, d);

    for (int i = 0; i < SAMPLES; i++)
    {
        printf("res[%d] = %d\n", i, res[i]);
    }

    return 0;
}