#include <stdio.h>
#include <stdlib.h>
#include "disparity.h"
void outlined_fun_18(/*I2D *range,*/ int *range_w, int *range_h, int *range_data,
                     int *disparity, int *rows,
                     /*I2D *Iright_moved,*/ int *Iright_moved_w, int *Iright_moved_h, int *Iright_moved_data,
                     int *cols, int *i)
{
    printf("outlined_fun_18: %d %d\n", (*rows), (*cols));
    range_data[(0) * (*range_w) + (0)] = 0;
    range_data[(0) * (*range_w) + (1)] = (*disparity);
    (*rows) = (*Iright_moved_h);
    (*cols) = (*Iright_moved_w);
    for ((*i) = 0; (*i) < (*rows) * (*cols); (*i)++)
    {
#pragma HLS loop_tripcount min = 462949720 max = 462949720
        Iright_moved_data[(*i)] = 0;
    }
}

void correlateSAD_2D(int *Ileft_w, int *Ileft_h, int *Ileft_data,
                     int *Iright_w, int *Iright_h, int *Iright_data,
                     int *Iright_moved_w, int *Iright_moved_h, int *Iright_moved_data,
                     int win_sz, int disparity,
                     int *SAD_w, int *SAD_h, int *SAD_data,
                     int *integralImg_w, int *integralImg_h, int *integralImg_data,
                     int *retSAD_w, int *retSAD_h, int *retSAD_data)
{
    int rows;
    int cols;
    int i;
    int j;
    int endRM;
    // I2D *range;
    int *range_w;
    int *range_h;
    int *range_data;

    // iMallocHandle_rep1(1, 2, &range);
    int init_range_w = 1;
    int init_range_h = 2;
    int init_range_data[2] = {0, 0};
    range_w = &init_range_w;
    range_h = &init_range_h;
    range_data = init_range_data;

    outlined_fun_18(range_w, range_h, range_data, &disparity, &rows, Iright_w, Iright_h, Iright_data, &cols, &i);
    padarray4(Iright_w, Iright_h, Iright_data, range_w, range_h, range_data, -1, Iright_moved_w, Iright_moved_h, Iright_moved_data);
    computeSAD(Ileft_w, Ileft_h, Ileft_data, Iright_moved_w, Iright_moved_h, Iright_moved_data, SAD_w, SAD_h, SAD_data);
    integralImage2D2D(SAD_w, SAD_h, SAD_data, integralImg_w, integralImg_h, integralImg_data);
    finalSAD(integralImg_w, integralImg_h, integralImg_data, win_sz, retSAD_w, retSAD_h, retSAD_data);
    // iFreeHandle_rep4(range);

    return;
}