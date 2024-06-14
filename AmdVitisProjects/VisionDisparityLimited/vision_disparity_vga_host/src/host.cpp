#include <cstring>
#include <iostream>
#include <vector>
#include <limits.h>
#include <linux/limits.h>
#include <random>
#include <unistd.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "experimental/xrt_bo.h"
#include "experimental/xrt_device.h"
#include "experimental/xrt_kernel.h"

#define WIDTH 595
#define HEIGHT 488
#define IMG_SIZE ((WIDTH + 10) * HEIGHT)
#define BUF_SIZE IMG_SIZE * sizeof(int)

inline uint64_t get_cpu_counter() {
#if defined(__aarch64__)
  uint64_t value;
  asm("isb; mrs %0, CNTVCT_EL0" : "=r"(value));
  return value;

#elif defined(__x86_64__) || defined(__i386__)
  unsigned int hi, lo;
  asm volatile("rdtsc" : "=a"(lo), "=d"(hi));
  return ((uint64_t)hi << 32) | lo;

#else
#warning Unsupported Architecture, get_cpu_counter will return 0
  return 0;
#endif
}

void *align_pointer(void *unaligned_ptr, size_t size, size_t alignment) {
  void *aligned_ptr = nullptr;
  if (posix_memalign(&aligned_ptr, alignment, size) != 0) {
    std::cout << "Failed to allocate memory-aligned buffer!" << std::endl;
    return nullptr;
  }

  std::memcpy(aligned_ptr, unaligned_ptr, size);

  return aligned_ptr;
}

void fill_random(int *array, size_t size) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 100);

  for (size_t i = 0; i < size; ++i) {
    array[i] = dis(gen);
  }
}

#define SIZE 595 * 488

// from padarray4.c
void padarray4(int inMat_w, int inMat_h, int *inMat_data, int borderMat_w,
               int borderMat_h, int *borderMat_data, int dir, int paddedArray_w,
               int paddedArray_h, int *paddedArray_data) {
  int rows;
  int cols;
  int bRows;
  int bCols;
  int newRows;
  int newCols;
  int i;
  int j;
  int adir;
  adir = abs(dir);
  rows = (inMat_h);
  cols = (inMat_w);
  bRows = borderMat_data[0];
  bCols = borderMat_data[1];
  newRows = rows + bRows;
  newCols = cols + bCols;
  int decomp_0;
  decomp_0 = dir == 1;

  // printf("padarray4: rows = %d, cols = %d, bRows = %d, bCols = %d, newRows =
  // %d, newCols = %d, dir = %d\n",  rows, cols, bRows, bCols, newRows, newCols,
  // dir);

  if (decomp_0) {
    for (i = 0; i < rows; i++) {
#pragma HLS loop_tripcount min = 488 max = 488
      for (j = 0; j < cols; j++) {
#pragma HLS loop_tripcount min = 595 max = 595
        paddedArray_data[(i) * (paddedArray_w) + (j)] =
            inMat_data[(i) * (inMat_w) + (j)];
      }
    }
  } else {
    for (i = 0; i < rows - bRows; i++) {
#pragma HLS loop_tripcount min = 488 max = 488
      for (j = 0; j < cols - bCols; j++) {
#pragma HLS loop_tripcount min = 595 max = 595
        paddedArray_data[((bRows + i)) * (paddedArray_w) + ((bCols + j))] =
            inMat_data[(i) * (inMat_w) + (j)];
      }
    }
  }

  return;
}

// from computeSAD.c
void computeSAD(/*I2D Ileft,*/ int Ileft_w, int Ileft_h, int *Ileft_data,
                /*I2D *Iright_moved,*/ int Iright_moved_w, int Iright_moved_h,
                int *Iright_moved_data,
                /*F2D *SAD*/ int SAD_w, int SAD_h, int *SAD_data) {
  int rows;
  int cols;
  int i;
  int j;
  int diff;
  rows = Ileft_h;
  cols = Ileft_w;

  // printf("computeSAD: rows = %d, cols = %d\n", rows, cols);

  for (i = 0; i < rows; i++) {
#pragma HLS loop_tripcount min = 488 max = 488
    for (j = 0; j < cols; j++) {
#pragma HLS loop_tripcount min = 595 max = 595
      diff = Ileft_data[(i) * (Ileft_w) + (j)] -
             Iright_moved_data[(i) * (Iright_moved_w) + (j)];
      SAD_data[(i) * (SAD_w) + (j)] = diff * diff;
    }
  }
  return;
}

// from integralImage2D2D.c
void wrapped_integralImage2D2D(int SAD_w, int SAD_h, int *SAD_data,
                               int integralImg_w, int integralImg_h,
                               int *integralImg_data) {
  // Xclbin setup
  char buffer[PATH_MAX];
  getcwd(buffer, sizeof(buffer));

  auto xclbin = std::string(buffer);
  xclbin.append("/").append("disparity.xclbin");
  auto device_id = 0;

  auto device = xrt::device(device_id);
  auto uuid = device.load_xclbin(xclbin);

  auto krnl = xrt::kernel(device, uuid, "integralImage2D2D");
/*
  int PAGE_SIZE = 4096;

  int *aligned_SAD_data = (int *)align_pointer(SAD_data, BUF_SIZE, PAGE_SIZE);

  int *aligned_integralImg_data =
      (int *)align_pointer(integralImg_data, BUF_SIZE, PAGE_SIZE);

  auto bo_SAD_data =
      xrt::bo(device, aligned_SAD_data, BUF_SIZE, PAGE_SIZE, krnl.group_id(0));
  auto bo_integralImg_data = xrt::bo(device, aligned_integralImg_data, BUF_SIZE,
                                     PAGE_SIZE, krnl.group_id(1));

  bo_SAD_data.sync(XCL_BO_SYNC_BO_TO_DEVICE);

  auto run = krnl(SAD_w, SAD_h, bo_SAD_data, integralImg_w, integralImg_h,
                  bo_integralImg_data);
  run.wait();

  bo_integralImg_data.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
  std::memcpy(integralImg_data, aligned_integralImg_data, BUF_SIZE);*/
    //std::vector<int> input(SAD_data, SAD_data + IMG_SIZE);
    //std::vector<int> output(integralImg_data, integralImg_data + IMG_SIZE);
    std::vector<int> input(IMG_SIZE, 2);
    std::vector<int> output(IMG_SIZE, 0);

    auto in_bo = xrt::bo(device, IMG_SIZE * sizeof(int), krnl.group_id(0));
    auto out_bo = xrt::bo(device, IMG_SIZE * sizeof(int), krnl.group_id(0));

    auto in_bo_map = in_bo.map<int*>();
    auto out_bo_map = out_bo.map<int*>();

    std::copy(input.begin(), input.end(), in_bo_map);
    in_bo.sync(XCL_BO_SYNC_BO_TO_DEVICE);

    auto run = krnl(SAD_w, SAD_h, in_bo, integralImg_w, integralImg_h, out_bo);
    run.wait();

    out_bo.sync(XCL_BO_SYNC_BO_FROM_DEVICE);

    std::copy(out_bo_map, out_bo_map + BUF_SIZE, output.begin());
}

void integralImage2D2D_sw(int SAD_w, int SAD_h, int *SAD_data,
                       int integralImg_w, int integralImg_h,
                       int *integralImg_data)
{
    int nr;
    int nc;
    int i;
    int j;
    nr = (SAD_h);
    nc = (SAD_w);
    //printf("integralImage2D2D: nr = %d, nc = %d\n", nr, nc);
    for (i = 0; i < nc; i++)
    {
#pragma HLS loop_tripcount min = 595 max = 595
        integralImg_data[(0) * (integralImg_w) + (i)] =
            SAD_data[(0) * (SAD_w) + (i)];
    }
    for (i = 1; i < nr; i++)
    {
#pragma HLS loop_tripcount min = 488 max = 488
        for (j = 0; j < nc; j++)
        {
#pragma HLS loop_tripcount min = 595 max = 595
            integralImg_data[(i) * (integralImg_w) + (j)] =
                integralImg_data[((i - 1)) * (integralImg_w) + (j)] +
                SAD_data[(i) * (SAD_w) + (j)];
        }
    }
    for (i = 0; i < nr; i++)
    {
#pragma HLS loop_tripcount min = 488 max = 488
        for (j = 1; j < nc; j++)
        {
#pragma HLS loop_tripcount min = 595 max = 595
            integralImg_data[(i) * (integralImg_w) + (j)] =
                integralImg_data[(i) * (integralImg_w) + ((j - 1))] +
                integralImg_data[(i) * (integralImg_w) + (j)];
        }
    }

    return;
}


// from finalSAD.c
void finalSAD(/*F2D *integralImg,*/ int integralImg_w, int integralImg_h,
              int *integralImg_data, int win_sz,
              /*F2D *retSAD*/ int retSAD_w, int retSAD_h, int *retSAD_data) {
  int endR;
  int endC;
  int i;
  int j;
  int k;
  endR = (integralImg_h);
  endC = (integralImg_w);
  k = 0;

  // printf("finalSAD: endR = %d, endC = %d\n", endR - win_sz, endC - win_sz);
  for (j = 0; j < (endC - win_sz); j++) {
#pragma HLS loop_tripcount min = 587 max = 587
    for (i = 0; i < (endR - win_sz); i++) {
#pragma HLS loop_tripcount min = 480 max = 480
      retSAD_data[(i) * (retSAD_w) + (j)] =
          integralImg_data[((win_sz + i)) * (integralImg_w) + ((j + win_sz))] +
          integralImg_data[((i + 1)) * (integralImg_w) + ((j + 1))] -
          integralImg_data[((i + 1)) * (integralImg_w) + ((j + win_sz))] -
          integralImg_data[((win_sz + i)) * (integralImg_w) + ((j + 1))];
    }
  }

  return;
}

void outlined_fun_18(int range_w, int range_h, int *range_data, int disparity,
                     int *rows, int Iright_moved_w, int Iright_moved_h,
                     int *Iright_moved_data, int *cols, int *i) {
  // printf("outlined_fun_18: %d %d\n", (*rows), (*cols));
  range_data[(0) * (range_w) + (0)] = 0;
  range_data[(0) * (range_w) + (1)] = (disparity);
  (*rows) = (Iright_moved_h);
  (*cols) = (Iright_moved_w);
  for ((*i) = 0; (*i) < (*rows) * (*cols); (*i)++) {
#pragma HLS loop_tripcount min = 290360 max = 290360
    Iright_moved_data[(*i)] = 0;
  }
}

void iMallocHandle_rep1(int *range_w, int *range_h, int **range_data) {
  *range_w = 1;
  *range_h = 2;
  *range_data = (int *)malloc(sizeof(int) * (*range_w) * (*range_h));
}

void iFreeHandle_rep4(int **range_data) { free(*range_data); }

void correlateSAD_2D(int Ileft_w, int Ileft_h, int *Ileft_data, int Iright_w,
                     int Iright_h, int *Iright_data, int Iright_moved_w,
                     int Iright_moved_h, int *Iright_moved_data, int win_sz,
                     int disparity, int SAD_w, int SAD_h, int *SAD_data,
                     int integralImg_w, int integralImg_h,
                     int *integralImg_data, int retSAD_w, int retSAD_h,
                     int *retSAD_data, int range_w, int range_h,
                     int *range_data) {
  int rows;
  int cols;
  int i;
  int j;
  int endRM;
  //std::cout << 1 << std::endl << std::flush;
  outlined_fun_18(range_w, range_h, range_data, disparity, &rows, Iright_w,
                  Iright_h, Iright_data, &cols, &i);
  //std::cout << 2 << std::endl << std::flush;
  padarray4(Iright_w, Iright_h, Iright_data, range_w, range_h, range_data, -1,
            Iright_moved_w, Iright_moved_h, Iright_moved_data);
  //std::cout << 3 << std::endl << std::flush;
  computeSAD(Ileft_w, Ileft_h, Ileft_data, Iright_moved_w, Iright_moved_h,
             Iright_moved_data, SAD_w, SAD_h, SAD_data);
  //std::cout << 4 << std::endl << std::flush;
  wrapped_integralImage2D2D(SAD_w, SAD_h, SAD_data, integralImg_w, integralImg_h, integralImg_data);
  //integralImage2D2D_sw(SAD_w, SAD_h, SAD_data, integralImg_w, integralImg_h, integralImg_data);
  //std::cout << 5 << std::endl << std::flush;
  finalSAD(integralImg_w, integralImg_h, integralImg_data, win_sz, retSAD_w,
           retSAD_h, retSAD_data);
  //std::cout << 6 << std::endl << std::flush;
  return;
}

// from findDisparity.c
void findDisparity(int retSAD_w, int retSAD_h, int *retSAD_data, int minSAD_w,
                   int minSAD_h, int *minSAD_data, int retDisp_w, int retDisp_h,
                   int *retDisp_data, int level, int nr, int nc) {
  int i;
  int j;
  int a;
  int b;
  // printf("findDisparity: nr = %d, nc = %d\n", nr, nc);
  for (i = 0; i < nr; i++) {
#pragma HLS loop_tripcount min = 480 max = 480
    for (j = 0; j < nc; j++) {
#pragma HLS loop_tripcount min = 587 max = 587
      a = retSAD_data[(i) * (retSAD_w) + (j)];
      b = minSAD_data[(i) * (minSAD_w) + (j)];
      int decomp_0;
      decomp_0 = a < b;
      if (decomp_0) {
        minSAD_data[(i) * (minSAD_w) + (j)] = a;
        retDisp_data[(i) * (retDisp_w) + (j)] = level;
      }
    }
  }

  return;
}

void outlined_loop_0(int Ileft_w, int Ileft_h, int *Ileft_data, int Iright_w,
                     int Iright_h, int *Iright_data, int Iright_moved_w,
                     int Iright_moved_h, int *Iright_moved_data, int win_sz,
                     int disparity, int SAD_w, int SAD_h, int *SAD_data,
                     int integralImg_w, int integralImg_h,
                     int *integralImg_data, int retSAD_w, int retSAD_h,
                     int *retSAD_data, int range_w, int range_h,
                     int *range_data, int minSAD_w, int minSAD_h,
                     int *minSAD_data, int retDisp_w, int retDisp_h,
                     int *retDisp_data, int nr, int nc) {
  correlateSAD_2D(Ileft_w, Ileft_h, Ileft_data, Iright_w, Iright_h, Iright_data,
                  Iright_moved_w, Iright_moved_h, Iright_moved_data, win_sz,
                  disparity, SAD_w, SAD_h, SAD_data, integralImg_w,
                  integralImg_h, integralImg_data, retSAD_w, retSAD_h,
                  retSAD_data, range_w, range_h, range_data);
  findDisparity(retSAD_w, retSAD_h, retSAD_data, minSAD_w, minSAD_h,
                minSAD_data, retDisp_w, retDisp_h, retDisp_data, disparity, nr,
                nc);
}

// adapted from getDisparity.c
void top_level(int Ileft_w, int Ileft_h, int *Ileft_data, int Iright_w,
               int Iright_h, int *Iright_data, int Iright_moved_w,
               int Iright_moved_h, int *Iright_moved_data, int win_sz,
               int SAD_w, int SAD_h, int *SAD_data, int integralImg_w,
               int integralImg_h, int *integralImg_data, int retSAD_w,
               int retSAD_h, int *retSAD_data, int minSAD_w, int minSAD_h,
               int *minSAD_data, int retDisp_w, int retDisp_h,
               int *retDisp_data, int nr, int nc, int range_w, int range_h,
               int *range_data) {
  for (int disparity = 0; disparity < 64; disparity++) {
    outlined_loop_0(
        Ileft_w, Ileft_h, Ileft_data, Iright_w, Iright_h, Iright_data,
        Iright_moved_w, Iright_moved_h, Iright_moved_data, win_sz, disparity,
        SAD_w, SAD_h, SAD_data, integralImg_w, integralImg_h, integralImg_data,
        retSAD_w, retSAD_h, retSAD_data, range_w, range_h, range_data, minSAD_w,
        minSAD_h, minSAD_data, retDisp_w, retDisp_h, retDisp_data, nr, nc);
    //std::cout << "Finished iteration " << disparity << std::endl;
  }
}
int main() {
  // Data declaration and initialization
  int Ileft_w = WIDTH;
  int Ileft_h = HEIGHT;
  int *Ileft_data = (int *)malloc(BUF_SIZE);
  fill_random(Ileft_data, IMG_SIZE);

  int Iright_w = WIDTH;
  int Iright_h = HEIGHT;
  int *Iright_data = (int *)malloc(BUF_SIZE);
  fill_random(Iright_data, IMG_SIZE);

  int Iright_moved_w = WIDTH;
  int Iright_moved_h = HEIGHT;
  int *Iright_moved_data = (int *)malloc(BUF_SIZE);
  fill_random(Iright_moved_data, IMG_SIZE);

  int win_sz = 8;

  int SAD_w = WIDTH;
  int SAD_h = HEIGHT;
  int *SAD_data = (int *)malloc(BUF_SIZE);
  fill_random(SAD_data, IMG_SIZE);

  int integralImg_w = WIDTH;
  int integralImg_h = HEIGHT;
  int *integralImg_data = (int *)malloc(BUF_SIZE);
  fill_random(integralImg_data, IMG_SIZE);

  int retSAD_w = WIDTH;
  int retSAD_h = HEIGHT;
  int *retSAD_data = (int *)malloc(BUF_SIZE);
  fill_random(retSAD_data, IMG_SIZE);

  int minSAD_w = WIDTH;
  int minSAD_h = HEIGHT;
  int *minSAD_data = (int *)malloc(BUF_SIZE);
  fill_random(minSAD_data, IMG_SIZE);

  int retDisp_w = WIDTH;
  int retDisp_h = HEIGHT;
  int *retDisp_data = (int *)malloc(BUF_SIZE);
  fill_random(retDisp_data, IMG_SIZE);

  int nr = HEIGHT;
  int nc = WIDTH;

  int range_w = 2;
  int range_h = 1;
  int *range_data = new int[2];
  fill_random(range_data, sizeof(int) * 2);

  uint64_t start;
  uint64_t end;

  start = get_cpu_counter();

  top_level(Ileft_w, Ileft_h, Ileft_data, Iright_w, Iright_h, Iright_data,
            Iright_moved_w, Iright_moved_h, Iright_moved_data, win_sz, SAD_w,
            SAD_h, SAD_data, integralImg_w, integralImg_h, integralImg_data,
            retSAD_w, retSAD_h, retSAD_data, minSAD_w, minSAD_h, minSAD_data,
            retDisp_w, retDisp_h, retDisp_data, nr, nc, range_w, range_h,
            range_data);

  end = get_cpu_counter();
  std::cout << "Elapsed time: " << end - start << "us | "
            << (end - start) / 10e6 << "s" << std::endl;

  return 0;
}