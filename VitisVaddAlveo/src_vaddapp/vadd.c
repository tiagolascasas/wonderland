void vadd_small(int dest[5], int a[5], int b[5])
{
    for (int i = 0; i < 5; i++)
    {
        dest[i] = a[i] + b[i];
    }
}

void vadd_big(int dest[4096], int a[4096], int b[4096])
{
    for (int i = 0; i < 4096; i++)
    {
        dest[i] = a[i] + b[i];
    }
}