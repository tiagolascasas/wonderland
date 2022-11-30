#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "config.h"
#include "util.h"

void rgbToGrayscale(int input_image[H * W * 3], int output_image[H * W]);

void convolve2d(int input_image[H * W], int kernel[K * K], int output_image[H * W]);

void combthreshold(int image_gray[H * W], int temp_buf[H * W], int output[H * W]);

void edge_detect(int image_rgb[H * W * 3],
#ifdef MAIN_ALL
                 int image_gray[H * W],
                 int temp_buf[H * W],
                 int filter[K * K],
#endif
                 int output[H * W])
{
    rgbToGrayscale(image_rgb, image_gray);

    output_dsp(image_gray, "grayscale.dat");

#ifdef SET_FILTER
    filter[0] = 1;
    filter[1] = 2;
    filter[2] = 1;
    filter[3] = 2;
    filter[4] = 4;
    filter[5] = 2;
    filter[6] = 1;
    filter[7] = 2;
    filter[8] = 1;

    convolve2d(image_gray, filter, output);

    output_dsp(output, "conv1.dat");
#endif

#ifdef SET_FILTER
    filter[0] = 1;
    filter[1] = 0;
    filter[2] = -1;
    filter[3] = 2;
    filter[4] = 0;
    filter[5] = -2;
    filter[6] = 1;
    filter[7] = 0;
    filter[8] = -1;

    convolve2d(output, filter, image_gray);

    output_dsp(image_gray, "conv2.dat");
#endif

#ifdef SET_FILTER
    filter[0] = 1;
    filter[1] = 2;
    filter[2] = 1;
    filter[3] = 0;
    filter[4] = 0;
    filter[5] = 0;
    filter[6] = -1;
    filter[7] = -2;
    filter[8] = -1;

    convolve2d(output, filter, temp_buf);

    output_dsp(temp_buf, "conv3.dat");
#endif

    combthreshold(image_gray, temp_buf, output);
}

int main()
{
    int image_rgb[H * W * 3] = {
#include "img_512_512.h"
    };
    int image_gray[H * W] = {0};
    int temp_buf[H * W] = {0};
    int filter[K * K] = {0};
    int output[H * W] = {0};

    output_dsp_rgb(image_rgb, "input.dat");

#if ITER > 0
    int i;
    for (i = 0; i < ITER; i++)
    {
#endif
        edge_detect(image_rgb, image_gray, temp_buf, filter, output);
#if ITER > 0
    }
#endif
    // print image
    output_dsp(output, "output.dat");

    return 0;
}

void rgbToGrayscale(int input_image[H * W * 3], int output_image[H * W])
{
    // #pragma HLS interface
    for (int i = 0; i < H; i++)
    {
        int jj = 0;
        for (int j = 0; j < W; j++)
        {
#pragma HLS pipeline
            int r = input_image[i * W * 3 + jj];
            int g = input_image[i * W * 3 + jj + 1];
            int b = input_image[i * W * 3 + jj + 2];
            jj += 3;

            float gray = 0.299 * r + 0.587 * g + 0.114 * b;
            output_image[i * W + j] = (int)floor(gray);
        }
    }
}

void convolve2d(int input_image[H * W], int kernel[K * K], int output_image[H * W])
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
#pragma HLS unroll
        for (c = 0; c < K; c++)
        {
            normal_factor += abs(kernel[r * K + c]);
        }
    }

    if (normal_factor == 0)
        normal_factor = 1;

    for (r = 0; r < H - K + 1; r++)
    {
        for (c = 0; c < W - K + 1; c++)
        {
#pragma HLS pipeline
            sum = 0;
            for (i = 0; i < K; i++)
            {
#pragma HLS unroll
                for (j = 0; j < K; j++)
                {
                    sum += input_image[(r + i) * W + (c + j)] * kernel[i * K + j];
                }
            }
            output_image[(r + dead_rows) * W + (c + dead_cols)] = (sum / normal_factor);
        }
    }
}

void combthreshold(int image_gray[H * W], int temp_buf[H * W], int output[H * W])
{
    int i, j;
    int temp1;
    int temp2;
    int temp3;

    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; ++j)
        {
#pragma HLS pipeline
            temp1 = abs(image_gray[i * W + j]);
            temp2 = abs(temp_buf[i * W + j]);
            temp3 = (temp1 > temp2) ? temp1 : temp2;
            output[i * W + j] = (temp3 > T) ? 255 : 0;
        }
    }
}
