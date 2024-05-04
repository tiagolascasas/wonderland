#include <stdio.h>
#include <stdlib.h>
#include "disparity.h"
void integralImage2D2D(F2D *SAD, F2D *integralImg)
{
    int nr;
    int nc;
    int i;
    int j;
    nr = SAD->height;
    nc = SAD->width;
    printf("integralImage2D2D: nr = %d, nc = %d\n", nr, nc);
    for (i = 0; i < nc; i++)
    {
        #pragma HLS loop_tripcount min=595 max=595
        integralImg->data[(0) * integralImg->width + (i)] = SAD->data[(0) * SAD->width + (i)];
    }
    for (i = 1; i < nr; i++)
    {
        #pragma HLS loop_tripcount min=488 max=488
        for (j = 0; j < nc; j++)
        {
            #pragma HLS loop_tripcount min=595 max=595
            integralImg->data[(i)*integralImg->width + (j)] = integralImg->data[((i - 1)) * integralImg->width + (j)] + SAD->data[(i)*SAD->width + (j)];
        }
    }
    for (i = 0; i < nr; i++)
    {
        #pragma HLS loop_tripcount min=488 max=488
        for (j = 1; j < nc; j++)
        {
            #pragma HLS loop_tripcount min=595 max=595
            integralImg->data[(i)*integralImg->width + (j)] = integralImg->data[(i)*integralImg->width + ((j - 1))] + integralImg->data[(i)*integralImg->width + (j)];
        }
    }

    return;
}
