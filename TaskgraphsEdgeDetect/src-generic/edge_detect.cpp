#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <chrono>
#include <iostream>
#include "config.h"
#include "util.h"

using namespace std;
using namespace std::chrono;

void rgbToGrayscale(int *image_rgb, int *image_gray, int width, int height)
{
    int size = width * height;

    for (int i = 0, j = 0; i < size; i++, j += 3)
    {
#pragma HLS pipeline
            int r = image_rgb[j];
            int g = image_rgb[j + 1];
            int b = image_rgb[j + 2];

            float gray = 0.299 * r + 0.587 * g + 0.114 * b;
            image_gray[i] = (int)floor(gray);
    }
}

void convolve2d(
    int *input_image,
#ifdef SET_FILTER
    int filter[K * K],
#endif
#ifndef SET_FILTER
    int version,
#endif
    int *output_image,
    int width,
    int height)
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
#pragma HLS unroll
        for (c = 0; c < K; c++)
        {
            normal_factor += abs(filter[r * K + c]);
        }
    }

    if (normal_factor == 0)
        normal_factor = 1;

    for (r = 0; r < height - K + 1; r++)
    {
        for (c = 0; c < width - K + 1; c++)
        {
#pragma HLS pipeline
            sum = 0;
            for (i = 0; i < K; i++)
            {
#pragma HLS unroll
                for (j = 0; j < K; j++)
                {
                    sum += input_image[(r + i) * width + (c + j)] * filter[i * K + j];
                }
            }
            output_image[(r + dead_rows) * width + (c + dead_cols)] = (sum / normal_factor);
        }
    }
}

void combthreshold(int *image_gray, int *temp_buf, int *output, int width, int height)
{
    int i, j;
    int temp1;
    int temp2;
    int temp3;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; ++j)
        {
#pragma HLS pipeline
            temp1 = abs(image_gray[i * width + j]);
            temp2 = abs(temp_buf[i * width + j]);
            temp3 = (temp1 > temp2) ? temp1 : temp2;
            output[i * width + j] = (temp3 > T) ? 255 : 0;
        }
    }
}

#pragma clava kernel
#pragma clava data kernel : [{                            \
    auto : "auto" },                                      \
    {auto : "auto" }, {auto : "auto" }, {auto : "auto" }, \
                                         {auto : "auto" }, {auto : "auto" }]
void edge_detect(int *image_rgb,
#ifdef MAIN_ALL
                 int *image_gray,
                 int *temp_buf,
                 int filter[K * K],
#endif
                 int *output,
                 int width,
                 int height)
{
#ifndef MAIN_ALL
    int image_gray[MAXBUF] = {0};
    int temp_buf[MAXBUF] = {0};
    int filter[K * K] = {0};
#endif

    rgbToGrayscale(image_rgb, image_gray, width, height);

#ifdef OUTS
    output_dsp(image_gray, "output_grayscale.dat", width, height);
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

    convolve2d(image_gray, filter, output, width, height);
#else
    convolve2d(image_gray, CONV_SMOOTH, output, width, height);
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

    convolve2d(output, filter, image_gray, width, height);
#else
    convolve2d(output, CONV_VERT, image_gray, width, height);
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

    convolve2d(output, filter, temp_buf, width, height);
#else
    convolve2d(output, CONV_HORIZ, temp_buf, width, height);
#endif

#ifdef OUTS
    output_dsp(temp_buf, "conv3.dat");
#endif

    combthreshold(image_gray, temp_buf, output, width, height);
}

int main()
{
int image_rgb[H * W * 3] = {
#include IMAGE
    };
#ifdef MAIN_ALL
    int image_gray[H * W] = {0};
    int temp_buf[H * W] = {0};
    int filter[K * K] = {0};
#endif
    int output[H * W] = {0};

#ifdef OUTS
    output_dsp_rgb(image_rgb, "input.dat");
#endif

    auto start = high_resolution_clock::now();
#if ITER > 0
    int i;
    for (i = 0; i < ITER; i++)
    {
#endif
        edge_detect(
            image_rgb,
#ifdef MAIN_ALL
            image_gray,
            temp_buf,
            filter,
#endif
            output, W, H);
#if ITER > 0
    }
#endif
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Duration: " << duration.count() << std::endl;

// print image
    char buf[256];
    strcpy(buf, IMAGE);

    char outname[256];
    sprintf(outname, "output_%s.dat", strtok(buf, "."));
    output_dsp(output, outname, W, H);

    int actual = 0;
    int real = CHECKSUM;
    for (int i = 0; i < H * W; i++)
    {
        actual += output[i];
    }
    cout << endl << "Edge detect for " << W << "x" << H << " image finished" << endl;
    cout << "Checksum: expected = " << real << ", actual = " << actual << (real == actual ? " (VERIFIED)" : " (ERROR)") << endl;

    return 0;
}