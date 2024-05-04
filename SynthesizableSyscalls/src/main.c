#include "synthcalls.h"

void kernel_A()
{
    printf("Hello, world!\n");
    printf("This is a number: %d\n", 42);
}

int main()
{
    synth_host_prekernel(1024, 1024);
    kernel_A();
    synth_host_postkernel();
    return 0;
}