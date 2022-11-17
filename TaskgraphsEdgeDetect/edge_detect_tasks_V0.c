#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define ITER 1000

#define K 3
#define N 512 // 128
#define T 80  // 127

int image_buffer0[N][N * 3];
int image_buffer1[N][N];
int image_buffer2[N][N];
int image_buffer3[N][N];
int filter[K][K];

void rgbToGrayscale(int input_image[N][N * 3], int output_image[N][N]);

void convolve2d(int input_image[N][N], int kernel[K][K], int output_image[N][N]);

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
                    buf[i][j] = 200;
                    buf[i][j - 1] = 200;
                    buf[i][j - 2] = 200;
                    buf[i][j - 3] = 200;
                    buf[i][j - 4] = 200;
                }
            }
            else if (i == 5 || i == height - 5)
            {
                if (j >= 5 && j <= width - 5)
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

int checksum(int buf[N][N])
{
    int n = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            n += buf[i][j];
        }
    }
    printf("Checksum: %d\n", n);
    return n;
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

int main()
{
    input_dsp(N, N * 3, image_buffer0);

#if ITER > 0
    int i;
    for (i = 0; i < ITER; i++)
    {
#endif
        initialize(image_buffer2, image_buffer3);

        rgbToGrayscale(image_buffer0, image_buffer1);

        filter[0][0] = 1;
        filter[0][1] = 2;
        filter[0][2] = 1;
        filter[1][0] = 2;
        filter[1][1] = 4;
        filter[1][2] = 2;
        filter[2][0] = 1;
        filter[2][1] = 2;
        filter[2][2] = 1;

        convolve2d(image_buffer1, filter, image_buffer3);

        filter[0][0] = 1;
        filter[0][1] = 0;
        filter[0][2] = -1;
        filter[1][0] = 2;
        filter[1][1] = 0;
        filter[1][2] = -2;
        filter[2][0] = 1;
        filter[2][1] = 0;
        filter[2][2] = -1;

        convolve2d(image_buffer3, filter, image_buffer1);

        filter[0][0] = 1;
        filter[0][1] = 2;
        filter[0][2] = 1;
        filter[1][0] = 0;
        filter[1][1] = 0;
        filter[1][2] = 0;
        filter[2][0] = -1;
        filter[2][1] = -2;
        filter[2][2] = -1;

        convolve2d(image_buffer3, filter, image_buffer2);

        combthreshold(image_buffer1, image_buffer2, image_buffer3);
        if (i == 0)
        {
            checksum(image_buffer1);
            checksum(image_buffer2);
            checksum(image_buffer3);
        }
#if ITER > 0
    }
#endif
    /* Store binary image. */
    // output_dsp(N, N, image_buffer3);

    return 0;
}

void rgbToGrayscale(int input_image[N][N * 3], int output_image[N][N])
{
    int i, j, jj;

    for (i = 0; i < N; i++)
    {
        for (j = 0, jj = 0; j < N; j++, jj += 3)
        {
            int r = input_image[i][jj];
            int g = input_image[i][jj + 1];
            int b = input_image[i][jj + 2];

            float gray = 0.299 * r + 0.587 * g + 0.114 * b;
            output_image[i][j] = (int)floor(gray);
        }
    }
}

void initialize(int image_buffer2[N][N], int image_buffer3[N][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            image_buffer2[i][j] = 0;
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
