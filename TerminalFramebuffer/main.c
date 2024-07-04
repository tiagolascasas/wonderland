#include <stdlib.h>
#include <stdio.h>
#include "termbuf.h"

int main()
{
    int height = 52;
    int width = 52;

    char *image = (char *)malloc(height * width);
    for (int i = 0; i < height * width; i++)
    {
        if (i % 2 == 0)
        {
            image[i] = 255;
        }
        else
        {
            image[i] = 0;
        }
    }

    TerminalBuffer *buf = termbuf_create(width, height, sizeof(char), 1);
    termbuf_clear(buf);
    termbuf_render(buf, image);

    return 0;
}