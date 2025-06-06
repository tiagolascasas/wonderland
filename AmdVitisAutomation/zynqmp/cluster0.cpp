#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <iostream>
#include <fstream>

void cluster0_combthreshold(int image_gray[262144], int temp_buf[262144], int output[262144]);
void cluster0_convolve2d_rep2(int input_image[262144], int filter[9], int output_image[262144]);
void cluster0(int output[262144], int filter[9], int temp_buf[262144], int image_gray[262144])
{
    cluster0_convolve2d_rep2(output, filter, temp_buf);
    cluster0_combthreshold(image_gray, temp_buf, output);
}

void cluster0_convolve2d_rep2(int input_image[262144], int filter[9], int output_image[262144])
{
    int i;
    int j;
    int c;
    int r;
    int normal_factor;
    int sum;
    int dead_rows;
    int dead_cols;
    dead_rows = 1;
    dead_cols = 1;
    normal_factor = 0;
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            int decomp_0;
            decomp_0 = abs(filter[r * 3 + c]);
            int decomp_1;
            decomp_1 = normal_factor + decomp_0;
            normal_factor = decomp_1;
        }
    }
    bool decomp_0;
    decomp_0 = 0;
    if (decomp_0)
    {
        normal_factor = 1;
    }
    for (r = 0; r < 510; r++)
    {
        for (c = 0; c < 510; c++)
        {
            sum = 0;
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    sum = sum + input_image[((r + i)) * 512 + ((c + j))] * filter[i * 3 + j];
                }
            }
            output_image[((r + dead_rows)) * 512 + ((c + dead_cols))] = (sum / normal_factor);
        }
    }
}

void cluster0_combthreshold(int image_gray[262144], int temp_buf[262144], int output[262144])
{
    int i;
    int j;
    int temp1;
    int temp2;
    int temp3;
    for (i = 0; i < 512; i++)
    {
        for (j = 0; j < 512; ++j)
        {
            temp1 = abs(image_gray[i * 512 + j]);
            temp2 = abs(temp_buf[i * 512 + j]);
            temp3 = (temp1 > temp2) ? temp1 : temp2;
            output[i * 512 + j] = (temp3 > 50) ? 255 : 0;
        }
    }
}
