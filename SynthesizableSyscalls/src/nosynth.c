#include <stdio.h>
#include <stdlib.h>
#include "synthcalls.h"

int nosynth_flush_print(print_buffer_t *buf)
{
    int size = buf->position;
    for (int i = 0; i < size; i++)
    {
        putchar(buf->buffer[i]);
        buf->buffer[i] = 0;
    }
    buf->position = 0;
    return size;
}

print_buffer_t *nosynth_make_print_buffer(size_t length)
{
    print_buffer_t *buf = (print_buffer_t *)malloc(sizeof(print_buffer_t));
    buf->buffer = (char *)calloc(length, sizeof(char));
    buf->length = length;
    buf->position = 0;
    return buf;
}