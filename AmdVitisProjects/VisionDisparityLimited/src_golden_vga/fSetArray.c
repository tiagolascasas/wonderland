#include <stdio.h>
#include <stdlib.h>
#include "sdvbs_common.h"
void fSetArray(int rows, int cols, float val, F2D **rtr_val)
{
    int i;
    int j;
    F2D *out;
    fMallocHandle_rep1(rows, cols, &out);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            out->data[(i)*out->width + (j)] = val;
        }
    }
    *rtr_val = out;

    return;
}

void outlined_fun_15(int *i, int *rows, int *j, int *cols, F2D *out, float *val, F2D **rtr_val)
{
    for ((*i) = 0; (*i) < (*rows); (*i)++)
    {
        for ((*j) = 0; (*j) < (*cols); (*j)++)
        {
            out->data[((*i)) * out->width + ((*j))] = (*val);
        }
    }
    *rtr_val = out;

    return;
}

void fSetArray_rep2(int rows, int cols, float val, F2D **rtr_val)
{
    int i;
    int j;
    F2D *out;
    fMallocHandle(rows, cols, &out);
    outlined_fun_15(&i, &rows, &j, &cols, out, &val, rtr_val);
}

void outlined_fun_14(int *i, int *rows, int *j, int *cols, F2D *out, float *val, F2D **rtr_val)
{
    for ((*i) = 0; (*i) < (*rows); (*i)++)
    {
        for ((*j) = 0; (*j) < (*cols); (*j)++)
        {
            out->data[((*i)) * out->width + ((*j))] = (*val);
        }
    }
    *rtr_val = out;

    return;
}

void fSetArray_rep1(int rows, int cols, float val, F2D **rtr_val)
{
    int i;
    int j;
    F2D *out;
    fMallocHandle(rows, cols, &out);
    outlined_fun_14(&i, &rows, &j, &cols, out, &val, rtr_val);
}

void outlined_fun_4(int *i, int *rows, int *j, int *cols, F2D *out, float *val, F2D **rtr_val)
{
    for ((*i) = 0; (*i) < (*rows); (*i)++)
    {
        for ((*j) = 0; (*j) < (*cols); (*j)++)
        {
            out->data[((*i)) * out->width + ((*j))] = (*val);
        }
    }
    *rtr_val = out;

    return;
}

void fSetArray_rep0(int rows, int cols, float val, F2D **rtr_val)
{
    int i;
    int j;
    F2D *out;
    fMallocHandle(rows, cols, &out);
    outlined_fun_4(&i, &rows, &j, &cols, out, &val, rtr_val);
}
