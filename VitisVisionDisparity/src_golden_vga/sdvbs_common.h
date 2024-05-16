#ifndef _SDVBS_COMMON_H_
#define _SDVBS_COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_IMG_SIZE 640*480

typedef struct
{
    int width;
    int height;
    int data[MAX_IMG_SIZE];
} I2D;

typedef struct
{
    int width;
    int height;
    unsigned int data[MAX_IMG_SIZE];
} UI2D;

typedef struct
{
    int width;
    int height;
    float data[MAX_IMG_SIZE];
} F2D;

I2D *readImage(char const *pathName);

F2D *readFile(unsigned char *fileName);
void iMallocHandle(int rows, int cols, I2D **rtr_val);
void iMallocHandle_rep1(int rows, int cols, I2D **rtr_val);
void iMallocHandle_rep0(int rows, int cols, I2D **rtr_val);
void fMallocHandle(int rows, int cols, F2D **rtr_val);
void fMallocHandle_rep1(int rows, int cols, F2D **rtr_val);
void fMallocHandle_rep0(int rows, int cols, F2D **rtr_val);
UI2D *uiMallocHandle(int rows, int cols);
void iFreeHandle(I2D *out);
void iFreeHandle_rep4(I2D *out);
void iFreeHandle_rep3(I2D *out);
void iFreeHandle_rep2(I2D *out);
void iFreeHandle_rep1(I2D *out);
void iFreeHandle_rep0(I2D *out);
void fFreeHandle(F2D *out);
void fFreeHandle_rep3(F2D *out);
void fFreeHandle_rep2(F2D *out);
void fFreeHandle_rep1(F2D *out);
void fFreeHandle_rep0(F2D *out);
void uiFreeHandle(UI2D *out);
void iSetArray(int rows, int cols, int val, I2D **rtr_val);
void iSetArray_rep3(int rows, int cols, int val, I2D **rtr_val);
void iSetArray_rep2(int rows, int cols, int val, I2D **rtr_val);
void iSetArray_rep1(int rows, int cols, int val, I2D **rtr_val);
void iSetArray_rep0(int rows, int cols, int val, I2D **rtr_val);
void fSetArray(int rows, int cols, float val, F2D **rtr_val);
void fSetArray_rep2(int rows, int cols, float val, F2D **rtr_val);
void fSetArray_rep1(int rows, int cols, float val, F2D **rtr_val);
void fSetArray_rep0(int rows, int cols, float val, F2D **rtr_val);
I2D *iDeepCopy(I2D *in);
F2D *fDeepCopy(F2D *in);
I2D *iDeepCopyRange(I2D *in, int startRow, int numberRows, int startCol, int numberCols);
F2D *fDeepCopyRange(F2D *in, int startRow, int numberRows, int startCol, int numberCols);
F2D *fiDeepCopy(I2D *in);
I2D *ifDeepCopy(F2D *in);
F2D *ffVertcat(F2D *matrix1, F2D *matrix2);
I2D *iVertcat(I2D *matrix1, I2D *matrix2);
F2D *fHorzcat(F2D *a, F2D *b);
I2D *iHorzcat(I2D *a, I2D *b);
F2D *horzcat(F2D *a, F2D *b, F2D *c);
F2D *fTranspose(F2D *a);
I2D *iTranspose(I2D *a);
F2D *fReshape(F2D *in, int rows, int cols);
I2D *iReshape(I2D *in, int rows, int cols);
F2D *fDivide(F2D *a, float b);
F2D *fMdivide(F2D *a, F2D *b);
F2D *ffDivide(F2D *a, F2D *b);
F2D *ffTimes(F2D *a, float b);
F2D *fTimes(F2D *a, F2D *b);
I2D *iTimes(I2D *a, I2D *b);
F2D *fMtimes(F2D *a, F2D *b);
F2D *ifMtimes(I2D *a, F2D *b);
F2D *fMinus(F2D *a, F2D *b);
I2D *iMinus(I2D *a, I2D *b);
I2D *isMinus(I2D *a, int b);
F2D *fPlus(F2D *a, F2D *b);
I2D *isPlus(I2D *a, int b);
F2D *calcSobel_dX(F2D *imageIn);
F2D *calcSobel_dY(F2D *imageIn);
F2D *ffConv2(F2D *a, F2D *b);
F2D *fiConv2(I2D *a, F2D *b);
F2D *ffConv2_dY(F2D *a, F2D *b);
F2D *ffiConv2(F2D *a, I2D *b);
I2D *iiConv2(I2D *a, I2D *b);
F2D *imageResize(F2D *imageIn);
F2D *imageBlur(I2D *imageIn);
F2D *fFind3(F2D *in);
F2D *fSum2(F2D *inMat, int dir);
F2D *fSum(F2D *inMat);
I2D *iSort(I2D *in, int dim);
F2D *fSort(F2D *in, int dim);
I2D *iSortIndices(I2D *in, int dim);
I2D *fSortIndices(F2D *input, int dim);
F2D *randnWrapper(int m, int n);
F2D *randWrapper(int m, int n);
int selfCheck(I2D *in1, char *path, int tol);
int fSelfCheck(F2D *in1, char *path, float tol);
void writeMatrix(I2D *input, char *inpath);
void fWriteMatrix(F2D *input, char *inpath);
unsigned int *photonEndTiming();
unsigned int *photonStartTiming();
unsigned int *photonReportTiming(unsigned int *startCycles, unsigned int *endCycles);
void photonPrintTiming(unsigned int *elapsed);
#endif