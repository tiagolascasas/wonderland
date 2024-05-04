#ifndef _DISPARITY_H_
#define _DISPARITY_H_

#include "sdvbs_common.h"
void computeSAD(/*I2D Ileft,*/ int *Ileft_w, int *Ileft_h, int *Ileft_data,
                /*I2D *Iright_moved,*/ int *Iright_moved_w, int *Iright_moved_h, int *Iright_moved_data,
                /*F2D *SAD*/ int *SAD_w, int *SAD_h, int *SAD_data);

void finalSAD(/*F2D *integralImg,*/ int *integralImg_w, int *integralImg_h, int *integralImg_data,
              int win_sz,
              /*F2D *retSAD*/ int *retSAD_w, int *retSAD_h, int *retSAD_data);

void integralImage2D2D(/*F2D *SAD,*/ int *SAD_w, int *SAD_h, int *SAD_data,
                       /*F2D *integralImg*/ int *integralImg_w, int *integralImg_h, int *integralImg_data);

void correlateSAD_2D(int *Ileft_w, int *Ileft_h, int *Ileft_data,
                     int *Iright_w, int *Iright_h, int *Iright_data,
                     int *Iright_moved_w, int *Iright_moved_h, int *Iright_moved_data,
                     int win_sz, int disparity,
                     int *SAD_w, int *SAD_h, int *SAD_data,
                     int *integralImg_w, int *integralImg_h, int *integralImg_data,
                     int *retSAD_w, int *retSAD_h, int *retSAD_data);

void padarray4(/*I2D *inMat,*/ int *inMat_w, int *inMat_h, int *inMat_data,
               /*I2D *borderMat,*/ int *borderMat_w, int *borderMat_h, int *borderMat_data,
               int dir,
               /*I2D *paddedArray*/ int *paddedArray_w, int *paddedArray_h, int *paddedArray_data);

void findDisparity(F2D *retSAD, F2D *minSAD, I2D *retDisp, int level, int nr, int nc);
void getDisparity(I2D *Ileft, I2D *Iright, int win_sz, int max_shift, I2D **rtr_val);
void padarray2(I2D *inMat, I2D *borderMat, I2D **rtr_val);
void padarray2_rep1(I2D *inMat, I2D *borderMat, I2D **rtr_val);
void padarray2_rep0(I2D *inMat, I2D *borderMat, I2D **rtr_val);
#endif
