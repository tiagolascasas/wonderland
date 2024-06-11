#include "sdvbs_common.h"
F2D *fDeepCopy(F2D *in)
{
    int i, j;
    F2D *out;
    int rows, cols;
    rows = in->height;
    cols = in->width;
    fMallocHandle(rows, cols, &out);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            out->data[(i)*out->width + (j)] = in->data[(i)*in->width + (j)];
        }
    }

    return out;
}
