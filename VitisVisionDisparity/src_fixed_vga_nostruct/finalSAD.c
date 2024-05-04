#include <stdio.h>
#include <stdlib.h>
#include "disparity.h"
void finalSAD(/*F2D *integralImg,*/ int *integralImg_w, int *integralImg_h, int *integralImg_data,
              int win_sz,
              /*F2D *retSAD*/ int *retSAD_w, int *retSAD_h, int *retSAD_data)
{
    int endR;
    int endC;
    int i;
    int j;
    int k;
    endR = (*integralImg_h);
    endC = (*integralImg_w);
    k = 0;

    printf("finalSAD: endR = %d, endC = %d\n", endR - win_sz, endC - win_sz);
    for (j = 0; j < (endC - win_sz); j++)
    {
#pragma HLS loop_tripcount min = 587 max = 587
        for (i = 0; i < (endR - win_sz); i++)
        {
#pragma HLS loop_tripcount min = 480 max = 480
            retSAD_data[(i) * (*retSAD_w) + (j)] = integralImg_data[((win_sz + i)) * (*integralImg_w) + ((j + win_sz))] + integralImg_data[((i + 1)) * (*integralImg_w) + ((j + 1))] - integralImg_data[((i + 1)) * (*integralImg_w) + ((j + win_sz))] - integralImg_data[((win_sz + i)) * (*integralImg_w) + ((j + 1))];
        }
    }

    return;
}
