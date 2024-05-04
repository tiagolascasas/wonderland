#include <stdio.h>
#include <stdlib.h>
#include "sdvbs_common.h"
void outlined_fun_7(I2D *out, int *rows, int *cols, int **rtr_val_w, int **rtr_val_h, int **rtr_val_data)
{
    out->height = (*rows);
    out->width = (*cols);
    *rtr_val_w = &(out->width);
    *rtr_val_h = &(out->height);
    *rtr_val_data = out->data;

    return;
}

void iMallocHandle(int rows, int cols, int **rtr_val_w, int **rtr_val_h, int **rtr_val_data)
{
    int i;
    int j;
    int *out;
    out = (int *)malloc(sizeof(int) * rows * cols);
    outlined_fun_7(out, &rows, &cols, rtr_val_w, rtr_val_h, rtr_val_data);
}

void outlined_fun_19(I2D *out, int *rows, int *cols, I2D **rtr_val)
{
    out->height = (*rows);
    out->width = (*cols);
    *rtr_val = out;

    return;
}

void iMallocHandle_rep1(int rows, int cols, I2D **rtr_val)
{
    int i;
    int j;
    I2D *out;
    out = (I2D *)malloc(sizeof(I2D) + sizeof(int) * rows * cols);
    outlined_fun_19(out, &rows, &cols, rtr_val);
}

void iMallocHandle_rep0(int rows, int cols, I2D **rtr_val)
{
    int i;
    int j;
    I2D *out;
    out = (I2D *)malloc(sizeof(I2D) + sizeof(int) * rows * cols);
    out->height = rows;
    out->width = cols;
    *rtr_val = out;

    return;
}
