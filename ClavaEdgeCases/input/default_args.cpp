void foo(int a, int b, int c = 0, int d = 0)
{
    // ...
}

int main()
{
    foo(1, 2);
    foo(1, 2, 3);
    foo(1, 2, 3, 4);

    return 0;
}