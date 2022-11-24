#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "config.h"
#include "common.h"

void convolve2d_parallel(int input_image[H][W], int vertical_filter[K][K], int horizontal_filter[K][K],
                         int output_vertical[H][W], int output_horizontal[H][W]);

void edge_detect(int image_rgb[H][W * 3], int output[H][W])
{
    int image_gray[H][W] = {0};
    int temp_buf[H][W] = {0};
    int filter[K][K] = {0};
    int filter_temp[K][K] = {0};

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

    filter_temp[0][0] = 1;
    filter_temp[0][1] = 2;
    filter_temp[0][2] = 1;
    filter_temp[1][0] = 0;
    filter_temp[1][1] = 0;
    filter_temp[1][2] = 0;
    filter_temp[2][0] = -1;
    filter_temp[2][1] = -2;
    filter_temp[2][2] = -1;

    convolve2d_parallel(output, filter, filter_temp, image_gray, temp_buf);

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

void convolve2d_parallel(int input_image[H][W], int vertical_filter[K][K], int horizontal_filter[K][K],
                         int output_vertical[H][W], int output_horizontal[H][W])
{
    int i;
    int j;
    int c;
    int r;
    int normal_factor_v;
    int normal_factor_h;
    int sum_v;
    int sum_h;
    int dead_rows;
    int dead_cols;

    /* Set the number of dead rows and columns. These represent the band of rows
       and columns around the edge of the image whose pixels must be formed from
       less than a full kernel-sized compliment of input image pixels. No output
       values for these dead rows and columns since  they would tend to have less
       than full amplitude values and would exhibit a "washed-out" look known as
       convolution edge effects. */

    dead_rows = K / 2;
    dead_cols = K / 2;

    /* Calculate the normalization factor of the kernel matrix. */

    normal_factor_v = 0;
    normal_factor_h = 0;
    for (r = 0; r < K; r++)
    {
#pragma HLS unroll
        for (c = 0; c < K; c++)
        {
            normal_factor_v += abs(vertical_filter[r][c]);
            normal_factor_h += abs(horizontal_filter[r][c]);
        }
    }

    if (normal_factor_v == 0)
        normal_factor_v = 1;
    if (normal_factor_h == 0)
        normal_factor_h = 1;

    /* Convolve the input image with the kernel. */
    for (r = 0; r < H - K + 1; r++)
    {
        // NOP
        for (c = 0; c < W - K + 1; c++)
        {
#pragma HLS pipeline
            sum_v = 0;
            sum_h = 0;
            for (i = 0; i < K; i++)
            {
#pragma HLS unroll
                // NOP
                for (j = 0; j < K; j++)
                {
                    sum_v += input_image[r + i][c + j] * vertical_filter[i][j];
                    sum_h += input_image[r + i][c + j] * horizontal_filter[i][j];
                }
            }
            output_vertical[r + dead_rows][c + dead_cols] = (sum_v / normal_factor_v);
            output_horizontal[r + dead_rows][c + dead_cols] = (sum_h / normal_factor_h);
        }
    }
}