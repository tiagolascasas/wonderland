#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "config.h"
#include "common.h"

void edge_detect(int image_rgb[H][W * 3], int output[H][W])
{
    int image_gray[H][W] = {0};
    int temp_buf[H][W] = {0};

    rgbToGrayscale(image_rgb, image_gray);

    convolve2d_smooth(image_gray, output);

    convolve2d_vert(output, image_gray);

    convolve2d_horiz(output, temp_buf);

    combthreshold(image_gray, temp_buf, output);
}

int main()
{
    int image_rgb[H][W * 3] = {0};

    int output[H][W] = {0};

    input_dsp(image_rgb);

#if ITER > 0
    int i;
    for (i = 0; i < ITER; i++)
    {
#endif
        edge_detect(image_rgb, output);
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
