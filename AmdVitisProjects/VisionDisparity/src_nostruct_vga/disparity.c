#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 595
#define HEIGHT 488
#define IMG_SIZE ((WIDTH + 10) * HEIGHT)
#define BUF_SIZE IMG_SIZE * sizeof(int)

// void integralImage2D2D(int SAD_w, int SAD_h, int *SAD_data,
//                        int integralImg_w, int integralImg_h,
//                        int *integralImg_data)
void integralImage2D2D(int SAD_w, int SAD_h, int* SAD_data,
                        int integralImg_w, int integralImg_h, int* integralImg_data
                        )
{
    int nr;
    int nc;
    int i;
    int j;
    nr = (SAD_h);
    nc = (SAD_w);
    //printf("integralImage2D2D: nr = %d, nc = %d\n", nr, nc);
    for (i = 0; i < nc; i++)
    {
#pragma HLS loop_tripcount min = 595 max = 595
        integralImg_data[(0) * (integralImg_w) + (i)] =
            SAD_data[(0) * (SAD_w) + (i)];
    }
    for (i = 1; i < nr; i++)
    {
#pragma HLS loop_tripcount min = 488 max = 488
        for (j = 0; j < nc; j++)
        {
#pragma HLS loop_tripcount min = 595 max = 595
            integralImg_data[(i) * (integralImg_w) + (j)] =
                integralImg_data[((i - 1)) * (integralImg_w) + (j)] +
                SAD_data[(i) * (SAD_w) + (j)];
        }
    }
    for (i = 0; i < nr; i++)
    {
#pragma HLS loop_tripcount min = 488 max = 488
        for (j = 1; j < nc; j++)
        {
#pragma HLS loop_tripcount min = 595 max = 595
            integralImg_data[(i) * (integralImg_w) + (j)] =
                integralImg_data[(i) * (integralImg_w) + ((j - 1))] +
                integralImg_data[(i) * (integralImg_w) + (j)];
        }
    }

    return;
}
