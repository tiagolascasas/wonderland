#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <iostream>

#define K 3
#define T 50

#define H 1280
#define W 720

#define CONV_SMOOTH 0
#define CONV_VERT 1
#define CONV_HORIZ 2

#define CHECKSUM 259845

using namespace std;
using namespace std::chrono;

void rgbToGrayscale(int input_image[H * W * 3], int output_image[H * W])
{
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

void convolve2d(
    int input_image[H * W],
#ifdef SET_FILTER
    int filter[K * K],
#endif
#ifndef SET_FILTER
    int version,
#endif
    int output_image[H * W])
{
    int i;
    int j;
    int c;
    int r;
    int normal_factor;
    int sum;
    int dead_rows;
    int dead_cols;

#ifndef SET_FILTER
    int filter[K * K];
    if (version == CONV_SMOOTH)
    {
        filter[0] = 1;
        filter[1] = 2;
        filter[2] = 1;
        filter[3] = 2;
        filter[4] = 4;
        filter[5] = 2;
        filter[6] = 1;
        filter[7] = 2;
        filter[8] = 1;
    }
    if (version == CONV_VERT)
    {
        filter[0] = 1;
        filter[1] = 0;
        filter[2] = -1;
        filter[3] = 2;
        filter[4] = 0;
        filter[5] = -2;
        filter[6] = 1;
        filter[7] = 0;
        filter[8] = -1;
    }
    if (version == CONV_HORIZ)
    {
        filter[0] = 1;
        filter[1] = 2;
        filter[2] = 1;
        filter[3] = 0;
        filter[4] = 0;
        filter[5] = 0;
        filter[6] = -1;
        filter[7] = -2;
        filter[8] = -1;
    }
#endif

    dead_rows = K / 2;
    dead_cols = K / 2;

    normal_factor = 0;
    for (r = 0; r < K; r++)
    {
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
            sum = 0;
            for (i = 0; i < K; i++)
            {
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
            temp1 = abs(image_gray[i * W + j]);
            temp2 = abs(temp_buf[i * W + j]);
            temp3 = (temp1 > temp2) ? temp1 : temp2;
            output[i * W + j] = (temp3 > T) ? 255 : 0;
        }
    }
}

void edge_detect(int image_rgb[H * W * 3],
#ifdef MAIN_ALL
                 int image_gray[H * W],
                 int temp_buf[H * W],
                 int filter[K * K],
#endif
                 int output[H * W])
{
#ifndef MAIN_ALL
    int image_gray[H * W] = {0};
    int temp_buf[H * W] = {0};
    int filter[K * K] = {0};
#endif

    rgbToGrayscale(image_rgb, image_gray);

#ifdef OUTS
    output_dsp(image_gray, "grayscale.dat");
#endif

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
#else
    convolve2d(image_gray, CONV_SMOOTH, output);
#endif

#ifdef OUTS
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
#else
    convolve2d(output, CONV_VERT, image_gray);
#endif

#ifdef OUTS
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
#else
    convolve2d(output, CONV_HORIZ, temp_buf);
#endif

#ifdef OUTS
    output_dsp(temp_buf, "conv3.dat");
#endif

    combthreshold(image_gray, temp_buf, output);
}

int main()
{
    int image_rgb[H * W * 3] = {
        #include "img_1280_720.dat"
    };
#ifdef MAIN_ALL
    int image_gray[H * W] = {0};
    int temp_buf[H * W] = {0};
    int filter[K * K] = {0};
#endif
    int output[H * W] = {0};

    auto start = high_resolution_clock::now();

        edge_detect(
            image_rgb,
#ifdef MAIN_ALL
            image_gray,
            temp_buf,
            filter,
#endif
            output);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Duration: " << duration.count() << std::endl;

// save image
#ifdef OUTS
    output_dsp(output, "output.dat");
#endif

    int actual = 0;
    int expected = CHECKSUM;
    for (int i = 0; i < H * W; i++)
    {
        actual += output[i];
    }
    cout << "Checksum: real = " << expected << ", actual = " << actual 
            << (expected == actual ? " (VERIFIED)" : " (ERROR)") << endl;

    return 0;
}