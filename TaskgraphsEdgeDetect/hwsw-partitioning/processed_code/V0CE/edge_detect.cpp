#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <iostream>
#include "config.h"
#include "util.h"

using namespace std;
using namespace std::chrono;

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

void convolve2d_smooth(int input_image[H * W], int output_image[H * W])
{
    int i;
    int j;
    int c;
    int r;
    int normal_factor;
    int sum;
    int dead_rows;
    int dead_cols;

    int filter[K * K];
    filter[0] = 1;
    filter[1] = 2;
    filter[2] = 1;
    filter[3] = 2;
    filter[4] = 4;
    filter[5] = 2;
    filter[6] = 1;
    filter[7] = 2;
    filter[8] = 1;

    dead_rows = K / 2;
    dead_cols = K / 2;

    normal_factor = 0;
    for (r = 0; r < K; r++)
    {
#pragma HLS unroll
        for (c = 0; c < K; c++)
        {
            normal_factor += abs(filter[r * K + c]);
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
                    sum += input_image[(r + i) * W + (c + j)] * filter[i * K + j];
                }
            }
            output_image[(r + dead_rows) * W + (c + dead_cols)] = (sum / normal_factor);
        }
    }
}

void convolve2d_vertical( int input_image[H * W], int output_image[H * W])
{
    int i;
    int j;
    int c;
    int r;
    int normal_factor;
    int sum;
    int dead_rows;
    int dead_cols;

    int filter[K * K];
    filter[0] = 1;
    filter[1] = 0;
    filter[2] = -1;
    filter[3] = 2;
    filter[4] = 0;
    filter[5] = -2;
    filter[6] = 1;
    filter[7] = 0;
    filter[8] = -1;

    dead_rows = K / 2;
    dead_cols = K / 2;

    normal_factor = 0;
    for (r = 0; r < K; r++)
    {
#pragma HLS unroll
        for (c = 0; c < K; c++)
        {
            normal_factor += abs(filter[r * K + c]);
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
                    sum += input_image[(r + i) * W + (c + j)] * filter[i * K + j];
                }
            }
            output_image[(r + dead_rows) * W + (c + dead_cols)] = (sum / normal_factor);
        }
    }
}

void convolve2d_horizontal( int input_image[H * W], int output_image[H * W])
{
    int i;
    int j;
    int c;
    int r;
    int normal_factor;
    int sum;
    int dead_rows;
    int dead_cols;

    int filter[K * K];
    filter[0] = 1;
    filter[1] = 2;
    filter[2] = 1;
    filter[3] = 0;
    filter[4] = 0;
    filter[5] = 0;
    filter[6] = -1;
    filter[7] = -2;
    filter[8] = -1;

    dead_rows = K / 2;
    dead_cols = K / 2;

    normal_factor = 0;
    for (r = 0; r < K; r++)
    {
#pragma HLS unroll
        for (c = 0; c < K; c++)
        {
            normal_factor += abs(filter[r * K + c]);
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
                    sum += input_image[(r + i) * W + (c + j)] * filter[i * K + j];
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

void edge_detect(int image_rgb[H * W * 3],
                 int output[H * W])
{
    int image_gray[H * W] = {0};
    int temp_buf[H * W] = {0};

    rgbToGrayscale(image_rgb, image_gray);

    convolve2d_smooth(image_gray, output);

    convolve2d_vertical(output, image_gray);

    convolve2d_horizontal(output, temp_buf);

    combthreshold(image_gray, temp_buf, output);
}

int main()
{
    int image_rgb[H * W * 3] = {
//#include "img_512_512.dat"
0
    };
    int output[H * W] = {0};

    auto start = high_resolution_clock::now();
    
#if ITER > 0
    int i;
    for (i = 0; i < ITER; i++)
    {
#endif
    edge_detect(image_rgb, output);
#if ITER > 0
    }
#endif

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Duration: " << duration.count() << endl;

    int actual = 0;
    int real = 2455650;
    for (int i = 0; i < 262144; i++)
    {
        actual += output[i];
    }
    cout << "Checksum: real = " << real << ", actual = " << actual << (real == actual ? " (VERIFIED)" : " (ERROR)") << endl;

    return 0;
}