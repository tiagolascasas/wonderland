#include <stdio.h>
#include <stdlib.h>
#include "disparity.h"
void findDisparity(F2D *retSAD, F2D *minSAD, I2D *retDisp, int level, int nr, int nc)
{
    int i;
    int j;
    int a;
    int b;
    printf("findDisparity: nr = %d, nc = %d\n", nr, nc);
    for (i = 0; i < nr; i++)
    {
        #pragma HLS loop_tripcount min=480 max=480
        for (j = 0; j < nc; j++)
        {
            #pragma HLS loop_tripcount min=587 max=587
            a = retSAD->data[(i)*retSAD->width + (j)];
            b = minSAD->data[(i)*minSAD->width + (j)];
            int decomp_0;
            decomp_0 = a < b;
            if (decomp_0)
            {
                minSAD->data[(i)*minSAD->width + (j)] = a;
                retDisp->data[(i)*retDisp->width + (j)] = level;
            }
        }
    }

    return;
}
