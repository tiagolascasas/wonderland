#include <stdio.h>
#include <stdlib.h>
#include "disparity.h"
void outlined_fun_0(int *nr, I2D *Ileft, int *nc, int *half_win_sz, int *win_sz)
{
    (*nr) = Ileft->height;
    (*nc) = Ileft->width;
    (*half_win_sz) = (*win_sz) / 2;
}

void outlined_fun_1(int *decomp_0, int *win_sz)
{
    (*decomp_0) = (*win_sz) > 1;
}

void outlined_fun_2(int *rows, I2D *IleftPadded, int *cols)
{
    (*rows) = IleftPadded->height;
    (*cols) = IleftPadded->width;
}

void outlined_fun_3(I2D *IleftPadded, I2D *Ileft, I2D *IrightPadded, I2D *Iright)
{
    IleftPadded = Ileft;
    IrightPadded = Iright;
}

void outlined_loop_0(I2D *IleftPadded, I2D *IrightPadded, I2D *Iright_moved, int *win_sz, int *k, F2D *SAD, F2D *integralImg, F2D *retSAD, F2D *minSAD, I2D *retDisp, int *nr, int *nc)
{
    correlateSAD_2D(IleftPadded, IrightPadded, Iright_moved, (*win_sz), (*k), SAD, integralImg, retSAD);
    findDisparity(retSAD, minSAD, retDisp, (*k), (*nr), (*nc));
}

void getDisparity(I2D *Ileft, I2D *Iright, int win_sz, int max_shift, I2D **rtr_val)
{
    I2D *Iright_moved;
    I2D *IleftPadded;
    I2D *IrightPadded;
    F2D *integralImg;
    F2D *SAD;
    F2D *minSAD;
    F2D *retSAD;
    int cols;
    int rows;
    int half_win_sz;
    I2D *halfWin;
    int k;
    int nc;
    int nr;
    I2D *retDisp;
    outlined_fun_0(&nr, Ileft, &nc, &half_win_sz, &win_sz);
    fSetArray_rep0(nr, nc, 65025.0, &minSAD);
    iSetArray_rep0(nr, nc, max_shift, &retDisp);
    iSetArray_rep1(1, 2, half_win_sz, &halfWin);
    int decomp_0;
    outlined_fun_1(&decomp_0, &win_sz);
    if (decomp_0)
    {
        padarray2_rep0(Ileft, halfWin, &IleftPadded);
        padarray2_rep1(Iright, halfWin, &IrightPadded);
    }
    else
    {
        outlined_fun_3(IleftPadded, Ileft, IrightPadded, Iright);
    }
    outlined_fun_2(&rows, IleftPadded, &cols);
    fSetArray_rep1(rows, cols, 255, &SAD);
    fSetArray_rep2(rows, cols, 0, &integralImg);
    fMallocHandle_rep0(rows - win_sz, cols - win_sz, &retSAD);
    iSetArray_rep2(rows, cols, 0, &Iright_moved);
    for (k = 0; k < max_shift; k++)
    {
        outlined_loop_0(IleftPadded, IrightPadded, Iright_moved, &win_sz, &k, SAD, integralImg, retSAD, minSAD, retDisp, &nr, &nc);
    }
    fFreeHandle_rep0(retSAD);
    fFreeHandle_rep1(minSAD);
    fFreeHandle_rep2(SAD);
    fFreeHandle_rep3(integralImg);
    iFreeHandle_rep0(halfWin);
    iFreeHandle_rep1(IrightPadded);
    iFreeHandle_rep2(IleftPadded);
    iFreeHandle_rep3(Iright_moved);
    *rtr_val = retDisp;

    return;
}
