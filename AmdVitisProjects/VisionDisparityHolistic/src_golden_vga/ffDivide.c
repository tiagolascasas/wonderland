#include "sdvbs_common.h"
F2D *ffDivide(F2D *a, F2D *b)
{
    F2D *c;
    int i, j, rows, cols;
    rows = a->height;
    cols = a->width;
    fMallocHandle(rows, cols, &c);
    for (i = 0; i < (rows * cols); i++)
    {
        c->data[i] = a->data[i] / b->data[i];
    }

    return c;
}
