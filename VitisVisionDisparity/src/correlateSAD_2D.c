#include "disparity.h"
#include <stdio.h>
#include <stdlib.h>
void outlined_fun_18(I2D *range, int *disparity, int *rows, I2D *Iright_moved,
                     int *cols, int *i) {
  range->data[(0) * range->width + (0)] = 0;
  range->data[(0) * range->width + (1)] = (*disparity);
  (*rows) = Iright_moved->height;
  (*cols) = Iright_moved->width;
  for ((*i) = 0; (*i) < (*rows) * (*cols); (*i)++) {
    Iright_moved->data[(*i)] = 0;
  }
}

void inline specialized_iMallocHandle_rep1(I2D **ptr) {
    char buf[64] = {0};
    *ptr = (I2D*)buf;
}

void correlateSAD_2D(I2D *Ileft, I2D *Iright, I2D *Iright_moved, int win_sz,
                     int disparity, F2D *SAD, F2D *integralImg, F2D *retSAD) {
  int rows;
  int cols;
  int i;
  int j;
  int endRM;
  I2D *range;
  //iMallocHandle_rep1(1, 2, &range);
  specialized_iMallocHandle_rep1(&range);

  outlined_fun_18(range, &disparity, &rows, Iright_moved, &cols, &i);
  padarray4(Iright, range, -1, Iright_moved);
  computeSAD(Ileft, Iright_moved, SAD);
  integralImage2D2D(SAD, integralImg);
  finalSAD(integralImg, win_sz, retSAD);
  // iFreeHandle_rep4(range);

  return;
}
