#define N 4096

int foo(int A[N], int B[N])
{
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum += A[i] + B[i];
    }
    return sum;
}

void bar(int A[N], int B[N])
{
    for (int i = 0; i < N; i++)
    {
        A[i] += A[i] * B[i];
    }
}