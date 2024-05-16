#include <stdio.h>
#include <stdlib.h>
#include "sdvbs_common.h"
void outlined_fun_7(I2D *out, int *rows, int *cols, I2D **rtr_val)
{
    out->height = (*rows);
    out->width = (*cols);
    *rtr_val = out;

    return;
}

void iMallocHandle(int rows, int cols, I2D **rtr_val)
{
    int i;
    int j;
    I2D *out;
    out = (I2D *)malloc(sizeof(I2D) + sizeof(int) * rows * cols);
    outlined_fun_7(out, &rows, &cols, rtr_val);
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
