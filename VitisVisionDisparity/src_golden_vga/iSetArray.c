#include <stdio.h>
#include <stdlib.h>
#include "sdvbs_common.h"
void iSetArray(int rows, int cols, int val, I2D **rtr_val)
{
    int i;
    int j;
    I2D *out;
    iMallocHandle_rep0(rows, cols, &out);
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

void outlined_fun_11(int *i, int *rows, int *j, int *cols, I2D *out, int *val, I2D **rtr_val)
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

void iSetArray_rep3(int rows, int cols, int val, I2D **rtr_val)
{
    int i;
    int j;
    I2D *out;
    iMallocHandle(rows, cols, &out);
    outlined_fun_11(&i, &rows, &j, &cols, out, &val, rtr_val);
}

void outlined_fun_17(int *i, int *rows, int *j, int *cols, I2D *out, int *val, I2D **rtr_val)
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

void iSetArray_rep2(int rows, int cols, int val, I2D **rtr_val)
{
    int i;
    int j;
    I2D *out;
    iMallocHandle(rows, cols, &out);
    outlined_fun_17(&i, &rows, &j, &cols, out, &val, rtr_val);
}

void outlined_fun_8(int *i, int *rows, int *j, int *cols, I2D *out, int *val, I2D **rtr_val)
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

void iSetArray_rep1(int rows, int cols, int val, I2D **rtr_val)
{
    int i;
    int j;
    I2D *out;
    iMallocHandle(rows, cols, &out);
    outlined_fun_8(&i, &rows, &j, &cols, out, &val, rtr_val);
}

void outlined_fun_6(int *i, int *rows, int *j, int *cols, I2D *out, int *val, I2D **rtr_val)
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

void iSetArray_rep0(int rows, int cols, int val, I2D **rtr_val)
{
    int i;
    int j;
    I2D *out;
    iMallocHandle(rows, cols, &out);
    outlined_fun_6(&i, &rows, &j, &cols, out, &val, rtr_val);
}
