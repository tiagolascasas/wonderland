#include <stdio.h>

#define N 4096

int main(int argc, char **argv)
{
    int A[N] = {[0 ... N - 1] = 10};
    int B[N] = {[0 ... N - 1] = 20};
    int C[N] = {[0 ... N - 1] = 30};
    int D[N] = {[0 ... N - 1] = 40};
    int E[N] = {[0 ... N - 1] = 1};

    for (int i = 0; i < N; i++)
    {
        A[i] = i * 2;
    }

    // Scenario A: extract a set of statements with no function calls
    // into their own function
#pragma clava begin_outline

    for (int i = 0; i < N; i++)
    {
        A[i] += B[i] + C[i];
    }

    int sth = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            C[i] += B[i] + C[j];
        sth += B[i];
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += E[i];
    }

    int prod = 0;
    for (int i = 0; i < N; i++)
    {
        prod *= E[i];
    }
#pragma clava end_outline

    // force a use of the "sum" and "sth" variable
    printf("%d\n", sum);
    printf("%d\n", sth);

    int sA = 0;
    int sB = 0;
    int sC = 0;
    int sD = 0;
    int sE = 0;

    for (int i = 0; i < N; i++)
    {
        sA += A[i];
        sB += B[i];
        sC += C[i];
        sD += D[i];
        sE += E[i];
    }
    printf("A - Ex: %d, Ac: %d (%s)\n", 16977920, sA, 16977920 == sA ? "SUCCESS" : "FAILURE");
    printf("B - Ex: %d, Ac: %d (%s)\n", 81920, sB, 81920 == sB ? "SUCCESS" : "FAILURE");
    printf("C - Ex: %d, Ac: %d (%s)\n", 503246848, sC, 503246848 == sC ? "SUCCESS" : "FAILURE");
    printf("D - Ex: %d, Ac: %d (%s)\n", 163840, sD, 163840 == sD ? "SUCCESS" : "FAILURE");
    printf("E - Ex: %d, Ac: %d (%s)\n", 4096, sE, 4096 == sE ? "SUCCESS" : "FAILURE");
    return 0;
}