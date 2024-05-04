#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "vadd.h"

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {5, 4, 3, 2, 1};
    int dest[5];

    vadd_small(dest, a, b);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", dest[i]);
    }
    printf("\n");

    int *bigA = (int *)malloc(4096 * sizeof(int));
    int *bigB = (int *)malloc(4096 * sizeof(int));
    int *bigDest = (int *)malloc(4096 * sizeof(int));

    for (int i = 0; i < 4096; i++)
    {
        bigA[i] = i;
        bigB[i] = 4096 - i;
    }

    vadd_big(bigDest, bigA, bigB);

    assert(bigDest[0] == 4096);
    assert(bigDest[4095] == 4096);

    return 0;
}