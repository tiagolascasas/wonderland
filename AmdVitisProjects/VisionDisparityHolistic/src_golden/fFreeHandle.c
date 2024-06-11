#include <stdio.h>
#include <stdlib.h>
#include "sdvbs_common.h"
void fFreeHandle(F2D *out)
{
    int decomp_0;
    decomp_0 = out != ((void *)0);
    if (decomp_0)
    {
        free(out);
    }

    return;
}

void outlined_fun_24(int *decomp_0, F2D *out)
{
    (*decomp_0) = out != ((void *)0);
}

void fFreeHandle_rep3(F2D *out)
{
    int decomp_0;
    outlined_fun_24(&decomp_0, out);
    if (decomp_0)
    {
        free(out);
    }

    return;
}

void outlined_fun_23(int *decomp_0, F2D *out)
{
    (*decomp_0) = out != ((void *)0);
}

void fFreeHandle_rep2(F2D *out)
{
    int decomp_0;
    outlined_fun_23(&decomp_0, out);
    if (decomp_0)
    {
        free(out);
    }

    return;
}

void outlined_fun_22(int *decomp_0, F2D *out)
{
    (*decomp_0) = out != ((void *)0);
}

void fFreeHandle_rep1(F2D *out)
{
    int decomp_0;
    outlined_fun_22(&decomp_0, out);
    if (decomp_0)
    {
        free(out);
    }

    return;
}

void outlined_fun_21(int *decomp_0, F2D *out)
{
    (*decomp_0) = out != ((void *)0);
}

void fFreeHandle_rep0(F2D *out)
{
    int decomp_0;
    outlined_fun_21(&decomp_0, out);
    if (decomp_0)
    {
        free(out);
    }

    return;
}
