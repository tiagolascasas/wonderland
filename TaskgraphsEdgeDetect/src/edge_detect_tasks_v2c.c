#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "config.h"
#include "common.h"

void convolve2d_vert_horiz(int input_image[H][W], int output_vertical[H][W], int output_horizontal[H][W]);

void edge_detect(int image_rgb[H][W * 3], int image_gray[H][W], int temp_buf[H][W], int output[H][W])
{
    rgbToGrayscale(image_rgb, image_gray);

    convolve2d_smooth(image_gray, output);

    convolve2d_vert_horiz(output, image_gray, temp_buf);

    combthreshold(image_gray, temp_buf, output);
}

int main()
{
    int image_rgb[H][W * 3] = {0};
    int image_gray[H][W] = {0};
    int temp_buf[H][W] = {0};
    int output[H][W] = {0};

    input_dsp(image_rgb);

#if ITER > 0
    int i;
    for (i = 0; i < ITER; i++)
    {
#endif
        edge_detect(image_rgb, image_gray, temp_buf, output);
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

void convolve2d_vert_horiz(int input_image[H][W], int output_vertical[H][W], int output_horizontal[H][W])
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
    int vertical_filter[K][K] = {
        {1, 0, -1},
        {2, 0, -2},
        {1, 0, -1}};
    int horizontal_filter[K][K] = {
        {1, 2, 1},
        {0, 0, 0},
        {-1, -2, -1}};

    dead_rows = K / 2;
    dead_cols = K / 2;

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

    for (r = 0; r < H - K + 1; r++)
    {
        for (c = 0; c < W - K + 1; c++)
        {
#pragma HLS pipeline
            sum_v = 0;
            sum_h = 0;
            for (i = 0; i < K; i++)
            {
#pragma HLS unroll
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