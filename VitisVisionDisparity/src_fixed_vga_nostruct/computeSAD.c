#include <stdio.h>
#include <stdlib.h>
#include "disparity.h"

void computeSAD(/*I2D Ileft,*/ int *Ileft_w, int *Ileft_h, int *Ileft_data,
                /*I2D *Iright_moved,*/ int *Iright_moved_w, int *Iright_moved_h, int *Iright_moved_data,
                /*F2D *SAD*/ int *SAD_w, int *SAD_h, int *SAD_data)
{
    int rows;
    int cols;
    int i;
    int j;
    int diff;
    rows = *Ileft_h;
    cols = *Ileft_w;

    printf("computeSAD: rows = %d, cols = %d\n", rows, cols);

    for (i = 0; i < rows; i++)
    {
#pragma HLS loop_tripcount min = 488 max = 488
        for (j = 0; j < cols; j++)
        {
#pragma HLS loop_tripcount min = 595 max = 595
            diff = Ileft_data[(i) * (*Ileft_w) + (j)] - Iright_moved_data[(i) * (*Iright_moved_w) + (j)];
            SAD_data[(i) * (*SAD_w) + (j)] = diff * diff;
        }
    }
    return;
}
