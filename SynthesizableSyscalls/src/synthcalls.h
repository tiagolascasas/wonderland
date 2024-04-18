#pragma once

#include <stdarg.h>
#include <stddef.h>

// Non-synthesizable API structs and functions

typedef struct
{
    char *buffer;
    size_t length;
    size_t position;
} print_buffer_t;

int nosynth_flush_print(print_buffer_t *buf);

print_buffer_t *nosynth_make_print_buffer(size_t length);

// Synthesizable printf-like functions

void synth_putchar(char character);

int synth_printf(print_buffer_t *buf, const char *format, ...);

int synth_sprintf(char *buffer, const char *format, ...);

int synth_snprintf(char *buffer, size_t count, const char *format, ...);

int synth_vsnprintf(char *buffer, size_t count, const char *format, va_list va);

int synth_vprintf(print_buffer_t *buf, const char *format, va_list va);

int synth_fctprintf(void (*out)(char character, void *arg), void *arg, const char *format, ...);

// Synthesizable malloc-like functions

void *synth_malloc(size_t size);
