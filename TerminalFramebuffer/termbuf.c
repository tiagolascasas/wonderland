#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "termbuf.h"

static void termbuf_render_pixel(TerminalBuffer *buf, int r, int g, int b)
{
    char pixelStr[26] = {0};
    sprintf(pixelStr, "\033[48;2;%d;%d;%dm  \033[0m", r, g, b);

    char *charBuf = (char *)buf->buffer;
    strncat(charBuf, pixelStr, sizeof(pixelStr));
}

static void termbuf_render_newline(TerminalBuffer *buf)
{
    char *charBuf = (char *)buf->buffer;
    char *newline = "\n";
    strncat(charBuf, newline, sizeof(newline));
}

static void termbuf_draw(TerminalBuffer *buf)
{
    printf(buf->buffer);
}

TerminalBuffer *termbuf_create(int width, int height, int pixelByteSize, char isGrayscale)
{
    TerminalBuffer *buf = (TerminalBuffer *)malloc(sizeof(TerminalBuffer));

    buf->width = width;
    buf->height = height;
    buf->pixelByteSize = pixelByteSize;
    buf->isGrayscale = isGrayscale;
    buf->buffer = calloc(width * height * 26, sizeof(char));

    return buf;
}

void termbuf_clear(TerminalBuffer *buf)
{
    system("clear");
    memset(buf->buffer, 0, buf->width * buf->height * 26);
}

void termbuf_render(TerminalBuffer *buf, void *data)
{
    int cursor = 0;

    for (int i = 0; i < buf->height; i++)
    {
        for (int j = 0; j < buf->width; j++)
        {
            int pixelByteSize = buf->pixelByteSize;
            char isGrayscale = buf->isGrayscale;
            int idx = buf->width * i + j;

            if (pixelByteSize == 1 && isGrayscale)
            {
                unsigned char *byteData = (unsigned char *)data;
                unsigned char pixel = byteData[idx];
                termbuf_render_pixel(buf, pixel, pixel, pixel);
            }
            if (pixelByteSize ==)
            // TODO: RGB cases
        }
        termbuf_render_newline(buf);
    }
    termbuf_draw(buf);
}