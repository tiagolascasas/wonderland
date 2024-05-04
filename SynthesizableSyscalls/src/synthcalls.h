#pragma once

#include <stdarg.h>
#include <stddef.h>

#define OVERRIDE_STDIO

// Host functions
void synth_host_prekernel(size_t print_buf_size, size_t heap_buf_size);

void synth_host_postkernel();

// Synthesizable printf-like functions
char *synth_get_buffer();

void synth_set_buffer(char *buffer, size_t size);

void synth_putchar(char character);

int synth_printf(const char *format, ...);

int synth_sprintf(char *buffer, const char *format, ...);

int synth_snprintf(char *buffer, size_t count, const char *format, ...);

int synth_vsnprintf(char *buffer, size_t count, const char *format, va_list va);

int synth_vprintf(const char *format, va_list va);

int synth_fctprintf(void (*out)(char character, void *arg), void *arg, const char *format, ...);

#ifdef OVERRIDE_STDIO
#define printf synth_printf
#define sprintf synth_sprintf
#define snprintf synth_snprintf
#define vsnprintf synth_vsnprintf
#define vprintf synth_vprintf
#define fctprintf synth_fctprintf
#endif

// Synthesizable malloc-like functions

void *synth_malloc(size_t size);
