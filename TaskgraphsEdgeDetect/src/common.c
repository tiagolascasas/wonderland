#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "config.h"

void rgbToGrayscale(int input_image[H][W * 3], int output_image[H][W])
{
    // #pragma HLS interface
    int i, j, jj;

    for (i = 0; i < H; i++)
    {
        for (j = 0, jj = 0; j < W; j++, jj += 3)
        {
#pragma HLS pipeline
            int r = input_image[i][jj];
            int g = input_image[i][jj + 1];
            int b = input_image[i][jj + 2];

            float gray = 0.299 * r + 0.587 * g + 0.114 * b;
            output_image[i][j] = (int)floor(gray);
        }
    }
}

void initialize(int temp_buf[H][W], int output[H][W])
{
    int i, j;

    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; j++)
        {
            temp_buf[i][j] = 0;
            output[i][j] = 0;
        }
    }
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
#pragma HLS unroll
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
#pragma HLS pipeline
            sum = 0;
            for (i = 0; i < K; i++)
            {
#pragma HLS unroll
                for (j = 0; j < K; j++)
                {
                    sum += input_image[r + i][c + j] * kernel[i][j];
                }
            }
            output_image[r + dead_rows][c + dead_cols] = (sum / normal_factor);
        }
    }
}

void combthreshold(int image_gray[H][W], int temp_buf[H][W], int output[H][W])
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
            temp1 = abs(image_gray[i][j]);
            temp2 = abs(temp_buf[i][j]);
            temp3 = (temp1 > temp2) ? temp1 : temp2;
            output[i][j] = (temp3 > T) ? 255 : 0;
        }
    }
}

void input_dsp(int buf[H][W * 3])
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W * 3; j++)
        {
            if (i > 5 && i < H - 5)
            {
                if (j == 5 || j == W * 3 - 5)
                {
                    buf[i][j] = 200;
                    buf[i][j - 1] = 200;
                    buf[i][j - 2] = 200;
                    buf[i][j - 3] = 200;
                    buf[i][j - 4] = 200;
                }
            }
            else if (i == 5 || i == H - 5)
            {
                if (j >= 5 && j <= W * 3 - 5)
                {
                    buf[i][j] = 200;
                    buf[i - 1][j] = 200;
                    buf[i - 2][j] = 200;
                    buf[i - 3][j] = 200;
                    buf[i - 4][j] = 200;
                }
            }
            else
            {
                buf[i][j] = 0;
            }
        }
    }
}

int checksum(int buf[H][W])
{
    int n = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            n += buf[i][j];
        }
    }
    printf("Checksum %s", n == CHECKSUM ? "SUCCESS" : "FAILURE");
    printf(" (actual: %d, expected: %d)\n", n, CHECKSUM);
    return n;
}

void output_dsp(int buf[H][W])
{
    for (int i = 0; i <= W + 1; i++)
        printf("_");
    printf("\n");

    for (int i = 0; i < H; i++)
    {
        printf("|");
        for (int j = 0; j < W; j++)
        {
            char c = buf[i][j] == 0 ? ' ' : (buf[i][j] > 0 ? 'X' : 'O');
            printf("%c", c);
        }
        printf("|\n");
    }
    for (int i = 0; i <= W + 1; i++)
        printf("_");
    printf("\n\n");
}

void convolve2d_smooth(int input_image[H][W], int output_image[H][W])
{
    int i;
    int j;
    int c;
    int r;
    int normal_factor;
    int sum;
    int dead_rows;
    int dead_cols;
    int kernel[K][K] = {
        {1, 2, 1},
        {2, 4, 2},
        {1, 2, 1}};

    dead_rows = K / 2;
    dead_cols = K / 2;

    normal_factor = 0;
    for (r = 0; r < K; r++)
    {
#pragma HLS unroll
        for (c = 0; c < K; c++)
        {
            normal_factor += abs(kernel[r][c]);
        }
    }

    if (normal_factor == 0)
        normal_factor = 1;

    /* Convolve the input image with the kernel. */
    for (r = 0; r < H - K + 1; r++)
    {
        // NOP
        for (c = 0; c < W - K + 1; c++)
        {
#pragma HLS pipeline
            sum = 0;
            for (i = 0; i < K; i++)
            {
#pragma HLS unroll
                // NOP
                for (j = 0; j < K; j++)
                {
                    sum += input_image[r + i][c + j] * kernel[i][j];
                }
            }
            output_image[r + dead_rows][c + dead_cols] = (sum / normal_factor);
        }
    }
}

void convolve2d_vert(int input_image[H][W], int output_image[H][W])
{
    int i;
    int j;
    int c;
    int r;
    int normal_factor;
    int sum;
    int dead_rows;
    int dead_cols;
    int kernel[K][K] = {
        {1, 0, -1},
        {2, 0, -2},
        {1, 0, -1}};

    dead_rows = K / 2;
    dead_cols = K / 2;

    normal_factor = 0;
    for (r = 0; r < K; r++)
    {
#pragma HLS unroll
        for (c = 0; c < K; c++)
        {
            normal_factor += abs(kernel[r][c]);
        }
    }

    if (normal_factor == 0)
        normal_factor = 1;

    /* Convolve the input image with the kernel. */
    for (r = 0; r < H - K + 1; r++)
    {
        // NOP
        for (c = 0; c < W - K + 1; c++)
        {
#pragma HLS pipeline
            sum = 0;
            for (i = 0; i < K; i++)
            {
#pragma HLS unroll
                // NOP
                for (j = 0; j < K; j++)
                {
                    sum += input_image[r + i][c + j] * kernel[i][j];
                }
            }
            output_image[r + dead_rows][c + dead_cols] = (sum / normal_factor);
        }
    }
}

void convolve2d_horiz(int input_image[H][W], int output_image[H][W])
{
    int i;
    int j;
    int c;
    int r;
    int normal_factor;
    int sum;
    int dead_rows;
    int dead_cols;
    int kernel[K][K] = {
        {1, 2, 1},
        {0, 0, 0},
        {-1, -2, -1}};

    dead_rows = K / 2;
    dead_cols = K / 2;

    normal_factor = 0;
    for (r = 0; r < K; r++)
    {
#pragma HLS unroll
        for (c = 0; c < K; c++)
        {
            normal_factor += abs(kernel[r][c]);
        }
    }

    if (normal_factor == 0)
        normal_factor = 1;

    /* Convolve the input image with the kernel. */
    for (r = 0; r < H - K + 1; r++)
    {
        // NOP
        for (c = 0; c < W - K + 1; c++)
        {
#pragma HLS pipeline
            sum = 0;
            for (i = 0; i < K; i++)
            {
#pragma HLS unroll
                // NOP
                for (j = 0; j < K; j++)
                {
                    sum += input_image[r + i][c + j] * kernel[i][j];
                }
            }
            output_image[r + dead_rows][c + dead_cols] = (sum / normal_factor);
        }
    }
}
