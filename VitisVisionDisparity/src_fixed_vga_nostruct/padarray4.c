#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "disparity.h"
void padarray4(/*I2D *inMat,*/ int *inMat_w, int *inMat_h, int *inMat_data,
               /*I2D *borderMat,*/ int *borderMat_w, int *borderMat_h, int *borderMat_data,
               int dir,
               /*I2D *paddedArray*/ int *paddedArray_w, int *paddedArray_h, int *paddedArray_data)
{
    int rows;
    int cols;
    int bRows;
    int bCols;
    int newRows;
    int newCols;
    int i;
    int j;
    int adir;
    adir = abs(dir);
    rows = (*inMat_h);
    cols = (*inMat_w);
    bRows = borderMat_data[0];
    bCols = borderMat_data[1];
    newRows = rows + bRows;
    newCols = cols + bCols;
    int decomp_0;
    decomp_0 = dir == 1;

    printf("padarray4: rows = %d, cols = %d, bRows = %d, bCols = %d, newRows = %d, newCols = %d, dir = %d\n", rows, cols, bRows, bCols, newRows, newCols, dir);

    if (decomp_0)
    {
        for (i = 0; i < rows; i++)
        {
#pragma HLS loop_tripcount min = 488 max = 488
            for (j = 0; j < cols; j++)
            {
#pragma HLS loop_tripcount min = 595 max = 595
                paddedArray_data[(i) * (*paddedArray_w) + (j)] = inMat_data[(i) * (*inMat_w) + (j)];
            }
        }
    }
    else
    {
        for (i = 0; i < rows - bRows; i++)
        {
#pragma HLS loop_tripcount min = 488 max = 488
            for (j = 0; j < cols - bCols; j++)
            {
#pragma HLS loop_tripcount min = 595 max = 595
                paddedArray_data[((bRows + i)) * (*paddedArray_w) + ((bCols + j))] = inMat_data[(i) * (*inMat_w) + (j)];
            }
        }
    }

    return;
}
