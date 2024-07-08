#include <iostream>
#include <chrono>

#include "config.h"
#include "edgedetect.h"
#include "util.h"

#define ITER 1
#define USE_REAL_IMAGE

int main()
{
    unsigned char *image_rgb = readBMP("input.bmp", W, H, 8);

    unsigned char image_gray[H * W] = {0};
    unsigned char temp_buf[H * W] = {0};
    unsigned char filter[K * K] = {0};
    unsigned char output[H * W] = {0};

    auto start = std::chrono::high_resolution_clock::now();

    int i;
    for (i = 0; i < ITER; i++)
    {
        edge_detect(image_rgb, image_gray, temp_buf, filter, output);
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Duration: " << duration.count() << "us" << std::endl;

    writeBMPGrayscale("output.bmp", output, W, H);

    return 0;
}