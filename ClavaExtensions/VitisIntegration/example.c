#include <stdio.h>

#define N 4096

void maddc(int B[N], int A[N], int C)
{
    for (int i = 0; i < N; i++)
    {
#pragma HLS unroll factor = 32
        B[i] = A[i] + C;
    }
}

void maddv(int C[N], int A[N], int B[N])
{
    for (int i = 0; i < N; i++)
    {
#pragma HLS unroll factor = 32
        C[i] = A[i] + B[i];
    }
}

int main()
{
    int A[N] = {0};
    int B[N] = {0};
    maddc(A, B, 42);

    int C[N] = {0};
    maddv(C, A, B);

    printf("Example code finished\n");

    return 0;
}
