#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "disparity.h"
#include "bitmap.h"

int main(int argc, char *argv[])
{
    FILE *log_file_0 = fopen("app_exec_time.csv", "w+");
    if (log_file_0 == NULL)
    {
        printf("Error opening file app_exec_time.csv\n");
        exit(1);
    }
    int rows = 32;
    int cols = 32;
    I2D *imleft, *imright, *retDisparity;
    unsigned int *start, *endC, *elapsed;
    int i, j;
    char im1[100];
    char im2[100];
    char timFile[100];
    int WIN_SZ = 8, SHIFT = 64;
    FILE *fp;
    if (argc < 2)
    {
        printf("We need input image path and output path\n");
        fclose(log_file_0);

        return -1;
    }
    sprintf(im1, "%s/1.bmp", argv[1]);
    sprintf(im2, "%s/2.bmp", argv[1]);
    imleft = readImage(im1);
    imright = readImage(im2);
    rows = imleft->height;
    cols = imleft->width;
    start = photonStartTiming();
    struct timespec clava_timing_start_0, clava_timing_end_0;
    clock_gettime(CLOCK_MONOTONIC, &clava_timing_start_0);

    getDisparity(imleft, imright, WIN_SZ, SHIFT, &retDisparity);

    clock_gettime(CLOCK_MONOTONIC, &clava_timing_end_0);
    double clava_timing_duration_0 = ((clava_timing_end_0.tv_sec + ((double)clava_timing_end_0.tv_nsec / 1000000000)) - (clava_timing_start_0.tv_sec + ((double)clava_timing_start_0.tv_nsec / 1000000000))) * (1000000);
    fprintf(log_file_0, "%fus\n", clava_timing_duration_0);
    endC = photonEndTiming();
    printf("Input size\t\t- (%dx%d)\n", rows, cols);
    elapsed = photonReportTiming(start, endC);
    photonPrintTiming(elapsed);
    iFreeHandle(imleft);
    iFreeHandle(imright);

    writeBMP("output.bmp", retDisparity->width, retDisparity->height, retDisparity->data);

    iFreeHandle(retDisparity);
    free(start);
    free(endC);
    free(elapsed);
    fclose(log_file_0);

    return 0;
}
