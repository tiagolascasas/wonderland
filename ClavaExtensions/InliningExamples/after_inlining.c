#include <stdio.h>

int main()
{
    int A[100] = {1};
    int B[100] = {2};
    int C[100] = {3};

    for (int i = 0; i < 100; i++)
    {
        A[i] = B[i] * 500;
    }

    int x;
    for (int i = 0; i < 100; i++)
    {
        B[i] = B[i] * C[i];
    }

    for (int i = 0; i < 100; i++)
    {
        C[i] = B[i] + C[i];
        C[i] = C[i] * C[i] * C[i];
    }

    for (int i = 0; i < 100; i++)
    {
        C[i] = B[i] * C[i];
        C[i] = C[i] * C[i] * C[i];
    }
    x = B[0] + C[0];

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            int y = x + A[0];

            for (int i = 0; i < 100; i++)
            {
                C[i] = C[i] * C[i];
            }

            for (int i = 0; i < 100; i++)
            {
                C[i] = C[i] + C[i];
                C[i] = C[i] * C[i] * C[i];
            }

            for (int i = 0; i < 100; i++)
            {
                C[i] = C[i] * C[i];
                C[i] = C[i] * C[i] * C[i];
            }

            for (int i = 0; i < 100; i++)
            {
                C[i] = C[i] * C[i];
            }

            for (int i = 0; i < 100; i++)
            {
                C[i] = C[i] + C[i];
                C[i] = C[i] * C[i] * C[i];
            }

            for (int i = 0; i < 100; i++)
            {
                C[i] = C[i] * C[i];
                C[i] = C[i] * C[i] * C[i];
            }
        }
    }

    int sumA = 0;
    int sumB = 0;
    int sumC = 0;
    for (int i = 0; i < 100; i++)
    {
        sumA += A[i];
        sumB += B[i];
        sumC += C[i];
    }
    printf("A: %d, B: %d, C: %d, x: %d\n", sumA, sumB, sumC, x);

    return A[2];
}