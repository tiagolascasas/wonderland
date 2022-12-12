#include <cmath>
#include "kernel.h"

template<unsigned int t_size>
void kernel_foo(int X[t_size], int *res)
{
	//input independent busy work
    int c = 0;
    for (int i = 0; i < 5000; i++)
        c += pow(i * 2, 2);
    *res = c;
}
