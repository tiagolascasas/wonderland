#include <stdio.h>

// Universal params
#define ITER 0 // 1000

#define K 3
#define N 512 // 128
#define T 50  // 127

#define H N
#define W N

void edge_detect(int image_rgb[H * W * 3],
                 int image_gray[H * W],
                 int temp_buf[H * W],
                 int filter[K * K],
                 int output[H * W])
{
    // rgbToGrayscale(image_rgb, image_gray);
    for (int i = 0; i < H; i++)
    {
        int jj = 0;
        for (int j = 0; j < W; j++)
        {
            int r = image_rgb[i * W * 3 + jj];
            int g = image_rgb[i * W * 3 + jj + 1];
            int b = image_rgb[i * W * 3 + jj + 2];
            jj += 3;

            float gray = 0.299 * r + 0.587 * g + 0.114 * b;
            image_gray[i * W + j] = (int)gray - (gray < 0 && gray != (int)gray);
        }
    }

    filter[0] = 1;
    filter[1] = 2;
    filter[2] = 1;
    filter[3] = 2;
    filter[4] = 4;
    filter[5] = 2;
    filter[6] = 1;
    filter[7] = 2;
    filter[8] = 1;

    // convolve2d(image_gray, filter, output);
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
            normal_factor += filter[r * K + c] > 0 ? filter[r * K + c] : -filter[r * K + c];
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
                    sum += image_gray[(r + i) * W + (c + j)] * filter[i * K + j];
                }
            }
            output[(r + dead_rows) * W + (c + dead_cols)] = (sum / normal_factor);
        }
    }

    filter[0] = 1;
    filter[1] = 0;
    filter[2] = -1;
    filter[3] = 2;
    filter[4] = 0;
    filter[5] = -2;
    filter[6] = 1;
    filter[7] = 0;
    filter[8] = -1;

    // convolve2d(output, filter, image_gray);
    dead_rows = K / 2;
    dead_cols = K / 2;

    normal_factor = 0;
    for (r = 0; r < K; r++)
    {
        for (c = 0; c < K; c++)
        {
            normal_factor += filter[r * K + c] > 0 ? filter[r * K + c] : -filter[r * K + c];
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
                    sum += output[(r + i) * W + (c + j)] * filter[i * K + j];
                }
            }
            image_gray[(r + dead_rows) * W + (c + dead_cols)] = (sum / normal_factor);
        }
    }

    filter[0] = 1;
    filter[1] = 2;
    filter[2] = 1;
    filter[3] = 0;
    filter[4] = 0;
    filter[5] = 0;
    filter[6] = -1;
    filter[7] = -2;
    filter[8] = -1;

    // convolve2d(output, filter, temp_buf);
    dead_rows = K / 2;
    dead_cols = K / 2;

    normal_factor = 0;
    for (r = 0; r < K; r++)
    {
        for (c = 0; c < K; c++)
        {
            normal_factor += filter[r * K + c] > 0 ? filter[r * K + c] : -filter[r * K + c];
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
                    sum += output[(r + i) * W + (c + j)] * filter[i * K + j];
                }
            }
            temp_buf[(r + dead_rows) * W + (c + dead_cols)] = (sum / normal_factor);
        }
    }

    // combthreshold(image_gray, temp_buf, output);
    int temp1;
    int temp2;
    int temp3;

    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; ++j)
        {
            temp1 = image_gray[i * W + j] > 0 ? image_gray[i * W + j] : -image_gray[i * W + j];
            temp2 = temp_buf[i * W + j] > 0 ? temp_buf[i * W + j] : -temp_buf[i * W + j];
            temp3 = (temp1 > temp2) ? temp1 : temp2;
            output[i * W + j] = (temp3 > T) ? 255 : 0;
        }
    }
}

int main()
{
    int image_rgb[H * W * 3] = {
        // #include "img_512_512.dat"
        0};
    int image_gray[H * W] = {0};
    int temp_buf[H * W] = {0};
    int filter[K * K] = {0};
    int output[H * W] = {0};

#if ITER > 0
    int i;
    for (i = 0; i < ITER; i++)
    {
#endif
        edge_detect(
            image_rgb,
            image_gray,
            temp_buf,
            filter,
            output);
#if ITER > 0
    }
#endif

    int actual = 0;
    int real = 2455650;
    for (int i = 0; i < 262144; i++)
    {
        actual += output[i];
    }
    printf("real: %d, actual: %d\n", real, actual);

    return 0;
}