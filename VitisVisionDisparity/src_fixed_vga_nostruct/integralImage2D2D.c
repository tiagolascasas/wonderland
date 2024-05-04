#include <stdio.h>
#include <stdlib.h>
#include "disparity.h"
void integralImage2D2D(/*F2D *SAD,*/ int *SAD_w, int *SAD_h, int *SAD_data,
                       /*F2D *integralImg*/ int *integralImg_w, int *integralImg_h, int *integralImg_data)
{
    int nr;
    int nc;
    int i;
    int j;
    nr = (*SAD_h);
    nc = (*SAD_w);
    printf("integralImage2D2D: nr = %d, nc = %d\n", nr, nc);
    for (i = 0; i < nc; i++)
    {
#pragma HLS loop_tripcount min = 595 max = 595
        integralImg_data[(0) * (*integralImg_w) + (i)] = SAD_data[(0) * (*SAD_w) + (i)];
    }
    for (i = 1; i < nr; i++)
    {
#pragma HLS loop_tripcount min = 488 max = 488
        for (j = 0; j < nc; j++)
        {
#pragma HLS loop_tripcount min = 595 max = 595
            integralImg_data[(i) * (*integralImg_w) + (j)] = integralImg_data[((i - 1)) * (*integralImg_w) + (j)] + SAD_data[(i) * (*SAD_w) + (j)];
        }
    }
    for (i = 0; i < nr; i++)
    {
#pragma HLS loop_tripcount min = 488 max = 488
        for (j = 1; j < nc; j++)
        {
#pragma HLS loop_tripcount min = 595 max = 595
            integralImg_data[(i) * (*integralImg_w) + (j)] = integralImg_data[(i) * (*integralImg_w) + ((j - 1))] + integralImg_data[(i) * (*integralImg_w) + (j)];
        }
    }

    return;
}
