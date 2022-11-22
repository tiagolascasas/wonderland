#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "config.h"
#include "common.h"

void edge_detect(int image_rgb[H][W * 3], int image_gray[H][W], int temp_buf[H][W], int filter[K][K], int output[H][W])
{
    rgbToGrayscale(image_rgb, image_gray);

    filter[0][0] = 1;
    filter[0][1] = 2;
    filter[0][2] = 1;
    filter[1][0] = 2;
    filter[1][1] = 4;
    filter[1][2] = 2;
    filter[2][0] = 1;
    filter[2][1] = 2;
    filter[2][2] = 1;

    convolve2d(image_gray, filter, output);

    filter[0][0] = 1;
    filter[0][1] = 0;
    filter[0][2] = -1;
    filter[1][0] = 2;
    filter[1][1] = 0;
    filter[1][2] = -2;
    filter[2][0] = 1;
    filter[2][1] = 0;
    filter[2][2] = -1;

    convolve2d(output, filter, image_gray);

    filter[0][0] = 1;
    filter[0][1] = 2;
    filter[0][2] = 1;
    filter[1][0] = 0;
    filter[1][1] = 0;
    filter[1][2] = 0;
    filter[2][0] = -1;
    filter[2][1] = -2;
    filter[2][2] = -1;

    convolve2d(output, filter, temp_buf);

    combthreshold(image_gray, temp_buf, output);
}

int main()
{
    int image_rgb[H][W * 3] = {0};
    int image_gray[H][W] = {0};
    int temp_buf[H][W] = {0};
    int filter[K][K] = {0};
    int output[H][W] = {0};

    input_dsp(image_rgb);

#if ITER > 0
    int i;
    for (i = 0; i < ITER; i++)
    {
#endif
        edge_detect(image_rgb, image_gray, temp_buf, filter, output);
        if (i == 0)
        {
            checksum(output);
        }
#if ITER > 0
    }
#endif
    /* Store binary image. */
    // output_dsp(output);

    return 0;
}
