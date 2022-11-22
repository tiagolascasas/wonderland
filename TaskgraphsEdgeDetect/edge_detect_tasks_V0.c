#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "config.h"
#include "common.h"

void convolve2d(int input_image[H][W], int kernel[K][K], int output_image[H][W]);

void edge_detect(int image_rgb[N][N*3], int image_gray[N][N], int temp_buf[N][N], int filter[K][K], int output[N][N]) 
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
    int image_rgb[N][N * 3] = {0};
    int image_gray[N][N] = {0};
    int temp_buf[N][N] = {0};
    int filter[K][K] = {0};
    int output[N][N] = {0};

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

void convolve2d(int input_image[H][W], int kernel[K][K], int output_image[H][W])
{
    int i;
    int j;
    int c;
    int r;
    int normal_factor;
    int sum;
    int dead_rows;
    int dead_cols;

    dead_rows = K / 2;
    dead_cols = K / 2;

    normal_factor = 0;
    for (r = 0; r < K; r++)
    {
        for (c = 0; c < K; c++)
        {
            normal_factor += abs(kernel[r][c]);
        }
    }

    if (normal_factor == 0)
        normal_factor = 1;

    for (r = 0; r < N - K + 1; r++)
    {
        for (c = 0; c < N - K + 1; c++)
        {
            sum = 0;
            for (i = 0; i < K; i++)
            {
                for (j = 0; j < K; j++)
                {
                    sum += input_image[r + i][c + j] * kernel[i][j];
                }
            }
            output_image[r + dead_rows][c + dead_cols] = (sum / normal_factor);
        }
    }
}
