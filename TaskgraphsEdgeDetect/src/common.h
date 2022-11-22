#pragma once

#include "config.h"

void initialize(int temp_buf[H][W], int output[H][W]);

void convolve2d(int input_image[H][W], int kernel[K][K], int output_image[H][W]);

void combthreshold(int image_gray[H][W], int temp_buf[H][W], int output[H][W]);

void rgbToGrayscale(int input_image[H][W * 3], int output_image[H][W]);

void input_dsp(int buf[H][W * 3]);

int checksum(int buf[H][W]);

void output_dsp(int buf[H][W]);

void convolve2d_smooth(int input_image[H][W], int output_image[H][W]);

void convolve2d_vert(int input_image[H][W], int output_image[H][W]);

void convolve2d_horiz(int input_image[H][W], int output_image[H][W]);