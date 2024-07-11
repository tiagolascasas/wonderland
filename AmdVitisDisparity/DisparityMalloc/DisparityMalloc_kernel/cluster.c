#include <stdlib.h>

void padarray4(int inMat_w, int inMat_h, int *inMat_data, int borderMat_w,
               int borderMat_h, int *borderMat_data, int dir,
               int paddedArray_w, int paddedArray_h, int *paddedArray_data)
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
    rows = (inMat_h);
    cols = (inMat_w);
    bRows = borderMat_data[0];
    bCols = borderMat_data[1];
    newRows = rows + bRows;
    newCols = cols + bCols;
    int decomp_0;
    decomp_0 = dir == 1;

    if (decomp_0)
    {
        for (i = 0; i < rows; i++)
        {
#pragma HLS loop_tripcount min = 488 max = 488
            for (j = 0; j < cols; j++)
            {
#pragma HLS loop_tripcount min = 595 max = 595
                paddedArray_data[(i) * (paddedArray_w) + (j)] =
                    inMat_data[(i) * (inMat_w) + (j)];
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
                paddedArray_data[((bRows + i)) * (paddedArray_w) + ((bCols + j))] =
                    inMat_data[(i) * (inMat_w) + (j)];
            }
        }
    }

    return;
}

void computeSAD(int Ileft_w, int Ileft_h, int *Ileft_data,
                int Iright_moved_w, int Iright_moved_h, int *Iright_moved_data,
                int SAD_w, int SAD_h, float *SAD_data)
{
    int rows;
    int cols;
    int i;
    int j;
    int diff;
    rows = Ileft_h;
    cols = Ileft_w;

    for (i = 0; i < rows; i++)
    {
#pragma HLS loop_tripcount min = 488 max = 488
        for (j = 0; j < cols; j++)
        {
#pragma HLS loop_tripcount min = 595 max = 595
            diff = Ileft_data[(i) * (Ileft_w) + (j)] -
                   Iright_moved_data[(i) * (Iright_moved_w) + (j)];
            SAD_data[(i) * (SAD_w) + (j)] = diff * diff;
        }
    }
    return;
}

void integralImage2D2D(int SAD_w, int SAD_h, float *SAD_data,
                       int integralImg_w, int integralImg_h, float *integralImg_data)
{
    int nr;
    int nc;
    int i;
    int j;
    nr = (SAD_h);
    nc = (SAD_w);

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

void finalSAD(int integralImg_w, int integralImg_h, float *integralImg_data,
              int win_sz,
              int retSAD_w, int retSAD_h, float *retSAD_data)
{
    int endR;
    int endC;
    int i;
    int j;
    int k;
    endR = (integralImg_h);
    endC = (integralImg_w);
    k = 0;

    for (j = 0; j < (endC - win_sz); j++)
    {
#pragma HLS loop_tripcount min = 587 max = 587
        for (i = 0; i < (endR - win_sz); i++)
        {
#pragma HLS loop_tripcount min = 480 max = 480
            retSAD_data[(i) * (retSAD_w) + (j)] =
                integralImg_data[((win_sz + i)) * (integralImg_w) + ((j + win_sz))] +
                integralImg_data[((i + 1)) * (integralImg_w) + ((j + 1))] -
                integralImg_data[((i + 1)) * (integralImg_w) + ((j + win_sz))] -
                integralImg_data[((win_sz + i)) * (integralImg_w) + ((j + 1))];
        }
    }

    return;
}

void outlined_fun_18(int range_w, int range_h, int *range_data,
                     int disparity, int *rows, int Iright_moved_w,
                     int Iright_moved_h, int *Iright_moved_data,
                     int *cols, int *i)
{
    range_data[(0) * (range_w) + (0)] = 0;
    range_data[(0) * (range_w) + (1)] = (disparity);
    (*rows) = (Iright_moved_h);
    (*cols) = (Iright_moved_w);
    for ((*i) = 0; (*i) < (*rows) * (*cols); (*i)++)
    {
#pragma HLS loop_tripcount min = 290360 max = 290360
        Iright_moved_data[(*i)] = 0;
    }
}

void cluster(int Ileft_w, int Ileft_h, int *Ileft_data,
                     int Iright_w, int Iright_h, int *Iright_data,
                     int Iright_moved_w, int Iright_moved_h, int *Iright_moved_data,
                     int win_sz,
                     int disparity,
                     int SAD_w, int SAD_h, float *SAD_data,
                     int integralImg_w, int integralImg_h, float *integralImg_data,
                     int retSAD_w, int retSAD_h, float *retSAD_data,
                     int range_w, int range_h, int* range_data) {
    int rows;
    int cols;
    int i;
    int j;
    int endRM;

    outlined_fun_18(range_w, range_h, range_data,
                    disparity, &rows,
                    Iright_moved_w, Iright_moved_h, Iright_moved_data,
                    &cols, &i);

    padarray4(Iright_w, Iright_h, Iright_data,
              range_w, range_h, range_data,
              -1,
              Iright_moved_w, Iright_moved_h, Iright_moved_data);

    computeSAD(Ileft_w, Ileft_h, Ileft_data,
               Iright_moved_w, Iright_moved_h, Iright_moved_data,
               SAD_w, SAD_h, SAD_data);

    integralImage2D2D(SAD_w, SAD_h, SAD_data,
                      integralImg_w, integralImg_h, integralImg_data);

    finalSAD(integralImg_w, integralImg_h, integralImg_data,
             win_sz,
             retSAD_w, retSAD_h, retSAD_data);
}