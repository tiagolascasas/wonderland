#include "synthcalls.h"

int main()
{
    print_buffer_t *buffer = nosynth_make_print_buffer(1024);

    synth_printf(&buffer, "Hello, world!\n");
    synth_printf(&buffer, "This is a number: %d\n", 42);
    nosynth_flush_print(&buffer);
    return 0;
}