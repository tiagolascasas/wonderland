void f1(int A[100], int B[100], int C[100])
{
    f2(A, B);
    for (int i = 0; i < 100; i++)
    {
        f3(A, C[i]);
    }
    f4(C);
}