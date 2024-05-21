#include <stdio.h>
#include <stdlib.h>
#include "sdvbs_common.h"
void iFreeHandle(I2D *out)
{
    int decomp_0;
    decomp_0 = out != ((void *)0);
    if (decomp_0)
    {
        free(out);
    }

    return;
}

void outlined_fun_20(int *decomp_0, I2D *out)
{
    (*decomp_0) = out != ((void *)0);
}

void iFreeHandle_rep4(I2D *out)
{
    int decomp_0;
    outlined_fun_20(&decomp_0, out);
    if (decomp_0)
    {
        free(out);
    }

    return;
}

void outlined_fun_28(int *decomp_0, I2D *out)
{
    (*decomp_0) = out != ((void *)0);
}

void iFreeHandle_rep3(I2D *out)
{
    int decomp_0;
    outlined_fun_28(&decomp_0, out);
    if (decomp_0)
    {
        free(out);
    }

    return;
}

void outlined_fun_27(int *decomp_0, I2D *out)
{
    (*decomp_0) = out != ((void *)0);
}

void iFreeHandle_rep2(I2D *out)
{
    int decomp_0;
    outlined_fun_27(&decomp_0, out);
    if (decomp_0)
    {
        free(out);
    }

    return;
}

void outlined_fun_26(int *decomp_0, I2D *out)
{
    (*decomp_0) = out != ((void *)0);
}

void iFreeHandle_rep1(I2D *out)
{
    int decomp_0;
    outlined_fun_26(&decomp_0, out);
    if (decomp_0)
    {
        free(out);
    }

    return;
}

void outlined_fun_25(int *decomp_0, I2D *out)
{
    (*decomp_0) = out != ((void *)0);
}

void iFreeHandle_rep0(I2D *out)
{
    int decomp_0;
    outlined_fun_25(&decomp_0, out);
    if (decomp_0)
    {
        free(out);
    }

    return;
}
