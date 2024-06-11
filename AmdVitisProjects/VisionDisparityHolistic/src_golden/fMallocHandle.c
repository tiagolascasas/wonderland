#include <stdio.h>
#include <stdlib.h>
#include "sdvbs_common.h"
void outlined_fun_5(F2D *out, int *rows, int *cols, F2D **rtr_val)
{
    out->height = (*rows);
    out->width = (*cols);
    *rtr_val = out;

    return;
}

void fMallocHandle(int rows, int cols, F2D **rtr_val)
{
    int i;
    int j;
    F2D *out;
    out = (F2D *)malloc(sizeof(F2D) + sizeof(float) * rows * cols);
    outlined_fun_5(out, &rows, &cols, rtr_val);
}

void fMallocHandle_rep1(int rows, int cols, F2D **rtr_val)
{
    int i;
    int j;
    F2D *out;
    out = (F2D *)malloc(sizeof(F2D) + sizeof(float) * rows * cols);
    out->height = rows;
    out->width = cols;
    *rtr_val = out;

    return;
}

void outlined_fun_16(F2D *out, int *rows, int *cols, F2D **rtr_val)
{
    out->height = (*rows);
    out->width = (*cols);
    *rtr_val = out;

    return;
}

void fMallocHandle_rep0(int rows, int cols, F2D **rtr_val)
{
    int i;
    int j;
    F2D *out;
    out = (F2D *)malloc(sizeof(F2D) + sizeof(float) * rows * cols);
    outlined_fun_16(out, &rows, &cols, rtr_val);
}
