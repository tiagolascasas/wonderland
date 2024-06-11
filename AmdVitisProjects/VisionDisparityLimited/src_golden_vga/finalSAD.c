#include <stdio.h>
#include <stdlib.h>
#include "disparity.h"
void finalSAD(F2D *integralImg, int win_sz, F2D *retSAD)
{
    int endR;
    int endC;
    int i;
    int j;
    int k;
    endR = integralImg->height;
    endC = integralImg->width;
    k = 0;

    printf("finalSAD: endR = %d, endC = %d\n", endR - win_sz, endC - win_sz);
    for (j = 0; j < (endC - win_sz); j++)
    {
        #pragma HLS loop_tripcount min=587 max=587
        for (i = 0; i < (endR - win_sz); i++)
        {
            #pragma HLS loop_tripcount min=480 max=480
            retSAD->data[(i)*retSAD->width + (j)] = integralImg->data[((win_sz + i)) * integralImg->width + ((j + win_sz))] + integralImg->data[((i + 1)) * integralImg->width + ((j + 1))] - integralImg->data[((i + 1)) * integralImg->width + ((j + win_sz))] - integralImg->data[((win_sz + i)) * integralImg->width + ((j + 1))];
        }
    }

    return;
}
