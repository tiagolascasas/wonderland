#include <stdlib.h>
#include <stdio.h>

#include "synthcalls.h"

void synth_host_prekernel(size_t print_buf_size, size_t heap_buf_size)
{
    char *print_buffer = (char *)calloc(print_buf_size, sizeof(char));
    synth_set_buffer(print_buffer, print_buf_size);
}

static void synth_postkernel_printf()
{
    size_t print_size;
    char *print_buffer = synth_get_buffer(&print_size);
    for (size_t i = 0; i < print_size; i++)
    {
        putchar(print_buffer[i]);
    }
    free(print_buffer);
}

void synth_host_postkernel()
{
    synth_postkernel_printf();
}