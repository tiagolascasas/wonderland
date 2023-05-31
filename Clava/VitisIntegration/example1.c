int foo()
{
    int c = 0;

    for (int i = 0; i < 1024; i++)
    {
        c += i * 100;
    }

    return 0;
}