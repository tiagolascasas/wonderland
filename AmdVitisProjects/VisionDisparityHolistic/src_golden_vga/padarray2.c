#include <stdio.h>
#include <stdlib.h>
#include "disparity.h"
void padarray2(I2D *inMat, I2D *borderMat, I2D **rtr_val)
{
    int rows;
    int cols;
    int bRows;
    int bCols;
    int newRows;
    int newCols;
    I2D *paddedArray;
    int i;
    int j;
    rows = inMat->height;
    cols = inMat->width;
    bRows = borderMat->data[0];
    bCols = borderMat->data[1];
    newRows = rows + bRows * 2;
    newCols = cols + bCols * 2;
    iSetArray_rep3(newRows, newCols, 0, &paddedArray);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            paddedArray->data[((bRows + i)) * paddedArray->width + ((bCols + j))] = inMat->data[(i)*inMat->width + (j)];
        }
    }
    *rtr_val = paddedArray;

    return;
}

void outlined_fun_12(int *rows, I2D *inMat, int *cols, int *bRows, I2D *borderMat, int *bCols, int *newRows, int *newCols)
{
    (*rows) = inMat->height;
    (*cols) = inMat->width;
    (*bRows) = borderMat->data[0];
    (*bCols) = borderMat->data[1];
    (*newRows) = (*rows) + (*bRows) * 2;
    (*newCols) = (*cols) + (*bCols) * 2;
}

void outlined_fun_13(int *i, int *rows, int *j, int *cols, I2D *paddedArray, int *bRows, int *bCols, I2D *inMat, I2D **rtr_val)
{
    for ((*i) = 0; (*i) < (*rows); (*i)++)
    {
        for ((*j) = 0; (*j) < (*cols); (*j)++)
        {
            paddedArray->data[(((*bRows) + (*i))) * paddedArray->width + (((*bCols) + (*j)))] = inMat->data[((*i)) * inMat->width + ((*j))];
        }
    }
    *rtr_val = paddedArray;

    return;
}

void padarray2_rep1(I2D *inMat, I2D *borderMat, I2D **rtr_val)
{
    int j;
    int i;
    I2D *paddedArray;
    int newCols;
    int newRows;
    int bCols;
    int bRows;
    int cols;
    int rows;
    outlined_fun_12(&rows, inMat, &cols, &bRows, borderMat, &bCols, &newRows, &newCols);
    iSetArray_rep3(newRows, newCols, 0, &paddedArray);
    outlined_fun_13(&i, &rows, &j, &cols, paddedArray, &bRows, &bCols, inMat, rtr_val);
}

void outlined_fun_9(int *rows, I2D *inMat, int *cols, int *bRows, I2D *borderMat, int *bCols, int *newRows, int *newCols)
{
    (*rows) = inMat->height;
    (*cols) = inMat->width;
    (*bRows) = borderMat->data[0];
    (*bCols) = borderMat->data[1];
    (*newRows) = (*rows) + (*bRows) * 2;
    (*newCols) = (*cols) + (*bCols) * 2;
}

void outlined_fun_10(int *i, int *rows, int *j, int *cols, I2D *paddedArray, int *bRows, int *bCols, I2D *inMat, I2D **rtr_val)
{
    for ((*i) = 0; (*i) < (*rows); (*i)++)
    {
        for ((*j) = 0; (*j) < (*cols); (*j)++)
        {
            paddedArray->data[(((*bRows) + (*i))) * paddedArray->width + (((*bCols) + (*j)))] = inMat->data[((*i)) * inMat->width + ((*j))];
        }
    }
    *rtr_val = paddedArray;

    return;
}

void padarray2_rep0(I2D *inMat, I2D *borderMat, I2D **rtr_val)
{
    int j;
    int i;
    I2D *paddedArray;
    int newCols;
    int newRows;
    int bCols;
    int bRows;
    int cols;
    int rows;
    outlined_fun_9(&rows, inMat, &cols, &bRows, borderMat, &bCols, &newRows, &newCols);
    iSetArray_rep3(newRows, newCols, 0, &paddedArray);
    outlined_fun_10(&i, &rows, &j, &cols, paddedArray, &bRows, &bCols, inMat, rtr_val);
}
