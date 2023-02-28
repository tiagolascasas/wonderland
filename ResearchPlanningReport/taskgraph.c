void F1(int *A, int *B)
{
    B[0] = A[0];
}

void F2(int *B, int *C)
{
    int foo = C[0] + C[1] + C[2];
    int D[100] = {4444};
    F5(D);
    B[0] = D[0] + foo;
}

void F3(int *A, int *C)
{
    int bar = A[1] * C[1];
    int E[100] = {5555};
    int fizz = F6(E);
    F7(E);
    A[0] = bar + fizz + E[1];
}

int F4(int *A, int *B)
{
    return A[0] + B[1];
}

void F5(int *D)
{
    D[0] = D[1] * D[2];
}

int F6(int *E)
{
    return E[0] + E[1];
}

int F7(int *E)
{
    E[0] = E[1] * E[4] * 42;
}

int main()
{
    int A[100] = {1111};
    int B[100] = {2222};
    int C[100] = {3333};

    F1(A, B);
    F2(B, C);
    F3(A, C);
    int res = F4(A, B);
    res += res + 15;
    return res;
}