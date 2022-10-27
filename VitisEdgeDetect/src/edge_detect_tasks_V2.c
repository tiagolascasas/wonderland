/* This program detects the edges in a 256 gray-level 128 x 128 pixel image.
   The program relies on a 2D-convolution routine to convolve the image with
   kernels (Sobel operators) that expose horizontal and vertical edge
   information.

   The following is a block diagram of the steps performed in edge detection,


            +---------+       +----------+
   Input    |Smoothing|       |Horizontal|-------+
   Image -->| Filter  |---+-->| Gradient |       |
            +---------+   |   +----------+  +----x-----+   +---------+  Binary
                          |                 | Gradient |   |  Apply  |  Edge
                          |                 | Combining|-->|Threshold|->Detected
                          |   +----------+  +----x-----+   +----x----+  Output
                          |   | Vertical |       |              |
                          +-->| Gradient |-------+              |
                              +----------+                   Threshold
                                                               Value


    This program is based on the routines and algorithms found in the book
    "C Language Algorithms for Digital Signal Processing" by P.M. Embree
    and B. Kimble.

    Copyright (c) 1992 -- Mazen A.R. Saghir -- University of Toronto */
/* Modified to use arrays - SMP */

#include <stdlib.h>
#include <stdio.h>

#define ITER 1000

#define K 3
#define N 512 // 128
#define T 127

int image_buffer1[N][N];
int image_buffer2[N][N];
int image_buffer3[N][N];
int filter[K][K];
int filter_aux[K][K];

void convolve2d(int input_image[N][N], int kernel[K][K], int output_image[N][N]);

void convolve2d_parallel(int input_image[N][N], int vertical_filter[K][K], int horizontal_filter[K][K],
                         int output_vertical[N][N], int output_horizontal[N][N]);

void initialize(int image_buffer2[N][N], int image_buffer3[N][N]);

void combthreshold(int image_buffer1[N][N], int image_buffer2[N][N], int image_buffer3[N][N]);

void input_dsp(int height, int width, int buf[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i > 5 && i < height - 5)
            {
                if (j == 5 || j == width - 5)
                {
                    buf[i][j] = 5;
                }
            }
            else if (i == 5 || i == height - 5)
            {
                if (j >= 5 && j <= width - 5)
                {
                    buf[i][j] = 5;
                }
            }
            else
            {
                buf[i][j] = 0;
            }
        }
    }
}

void output_dsp(int height, int width, int buf[height][width])
{
    for (int i = 0; i <= width + 1; i++)
        printf("_");
    printf("\n");

    for (int i = 0; i < height; i++)
    {
        printf("|");
        for (int j = 0; j < width; j++)
        {
            char c = buf[i][j] == 0 ? ' ' : (buf[i][j] > 0 ? 'X' : 'O');
            printf("%c", c);
        }
        printf("|\n");
    }
    for (int i = 0; i <= width + 1; i++)
        printf("_");
    printf("\n\n");
}

void main()
{

    /* Read input image. */
    input_dsp(N, N, image_buffer1);
    // output_dsp(N, N, image_buffer1);

#if ITER > 0
    int i;
    for (i = 0; i < ITER; i++)
    {
#endif
        // NOP
        /* Initialize image_buffer2 and image_buffer3 */
        initialize(image_buffer2, image_buffer3);

        /* Set the values of the filter matrix to a Gaussian kernel.
           This is used as a low-pass filter which blurs the image so as to
           de-emphasize the response of some isolated points to the edge
           detection (Sobel) kernels. */

        filter[0][0] = 1;
        filter[0][1] = 2;
        filter[0][2] = 1;
        filter[1][0] = 2;
        filter[1][1] = 4;
        filter[1][2] = 2;
        filter[2][0] = 1;
        filter[2][1] = 2;
        filter[2][2] = 1;

        /* Perform the Gaussian convolution. */

        convolve2d(image_buffer1, filter, image_buffer3);

        /* Set the values of the filter matrix to the vertical Sobel operator. */
        filter[0][0] = 1;
        filter[0][1] = 0;
        filter[0][2] = -1;
        filter[1][0] = 2;
        filter[1][1] = 0;
        filter[1][2] = -2;
        filter[2][0] = 1;
        filter[2][1] = 0;
        filter[2][2] = -1;

        /* Set the values of the aux filter matrix to the horizontal Sobel operator. */
        filter_aux[0][0] = 1;
        filter_aux[0][1] = 2;
        filter_aux[0][2] = 1;
        filter_aux[1][0] = 0;
        filter_aux[1][1] = 0;
        filter_aux[1][2] = 0;
        filter_aux[2][0] = -1;
        filter_aux[2][1] = -2;
        filter_aux[2][2] = -1;

        // buf3: input (smoothed mage)
        // filter: vertical filter
        // filter_aux: horizontal filter
        // buf1: output (vertical edges)
        // buf2: output (horizontal edges)
        convolve2d_parallel(image_buffer3, filter, filter_aux, image_buffer1, image_buffer2);

        /* Take the larger of the magnitudes of the horizontal and vertical
           matrices. Form a binary image by comparing to a threshold and
           storing one of two values. */

        combthreshold(image_buffer1, image_buffer2, image_buffer3);

#if ITER > 0
    }
#endif

    /* Store binary image. */
    // output_dsp(N, N, image_buffer1);
    // output_dsp(N, N, image_buffer2);
    // output_dsp(N, N, image_buffer3);
    // output_dsp(N, N, filter);
}

void initialize(int image_buffer2[N][N], int image_buffer3[N][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            image_buffer2[i][j] = 0;
            // printf("address: %d\n", &image_buffer2[i][j]);
            image_buffer3[i][j] = 0;
        }
    }
}

void combthreshold(int image_buffer1[N][N], int image_buffer2[N][N], int image_buffer3[N][N])
{

    int i, j;

    int temp1;
    int temp2;
    int temp3;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; ++j)
        {
            temp1 = abs(image_buffer1[i][j]);
            temp2 = abs(image_buffer2[i][j]);
            temp3 = (temp1 > temp2) ? temp1 : temp2;
            image_buffer3[i][j] = (temp3 > T) ? 255 : 0;
        }
    }
}

void convolve2d_parallel(int input_image[N][N], int vertical_filter[K][K], int horizontal_filter[K][K],
                         int output_vertical[N][N], int output_horizontal[N][N])
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
    for (r = 0; r < N - K + 1; r++)
    {
        // NOP
        for (c = 0; c < N - K + 1; c++)
        {
            sum_v = 0;
            sum_h = 0;
            for (i = 0; i < K; i++)
            {
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

/* This function convolves the input image by the kernel and stores the result
   in the output image. */

void convolve2d(int input_image[N][N], int kernel[K][K], int output_image[N][N])
{
    int i;
    int j;
    int c;
    int r;
    int normal_factor;
    int sum;
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

    /* Convolve the input image with the kernel. */
    for (r = 0; r < N - K + 1; r++)
    {
        // NOP
        for (c = 0; c < N - K + 1; c++)
        {
            sum = 0;
            for (i = 0; i < K; i++)
            {
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
