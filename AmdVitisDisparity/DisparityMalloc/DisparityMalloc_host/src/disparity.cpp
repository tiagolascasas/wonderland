#include "bitmap.h"
#include <dirent.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>

#include "experimental/xrt_bo.h"
#include "experimental/xrt_device.h"
#include "experimental/xrt_kernel.h"
#include "experimental/xrt_xclbin.h"

void cluster(int Ileft_w, int Ileft_h, int *Ileft_data, int Iright_w,
             int Iright_h, int *Iright_data, int Iright_moved_w,
             int Iright_moved_h, int *Iright_moved_data, int win_sz,
             int disparity, int SAD_w, int SAD_h, float *SAD_data,
             int integralImg_w, int integralImg_h, float *integralImg_data,
             int retSAD_w, int retSAD_h, float *retSAD_data, int range_w,
             int range_h, int *range_data) {

  auto device = xrt::device(0);
  auto uuid = device.load_xclbin("./binary_container_1.xclbin");
  auto kernel = xrt::kernel(device, uuid, "cluster");

  auto bo_Ileft_data = xrt::bo(device, Ileft_w * Ileft_h, kernel.group_id(0));
  auto bo_Iright_data =
      xrt::bo(device, Iright_w * Iright_h, kernel.group_id(1));
  auto bo_Iright_moved_data =
      xrt::bo(device, Iright_moved_w * Iright_moved_h, kernel.group_id(2));
  auto bo_SAD_data = xrt::bo(device, SAD_w * SAD_h, kernel.group_id(3));
  auto bo_integralImg_data =
      xrt::bo(device, integralImg_w * integralImg_h, kernel.group_id(0));
  auto bo_retSAD_data =
      xrt::bo(device, retSAD_w * retSAD_h, kernel.group_id(1));
  auto bo_range_data = xrt::bo(device, range_w * range_h, kernel.group_id(2));

  int *host_ptr_Ileft_data = bo_Ileft_data.map<int *>();
  int *host_ptr_Iright_data = bo_Iright_data.map<int *>();
  int *host_ptr_Iright_moved_data = bo_Iright_moved_data.map<int *>();
  float *host_ptr_SAD_data = bo_SAD_data.map<float *>();
  float *host_ptr_integralImg_data = bo_integralImg_data.map<float *>();
  float *host_ptr_retSAD_data = bo_retSAD_data.map<float *>();
  int *host_ptr_range_data = bo_range_data.map<int *>();

  memcpy(host_ptr_Ileft_data, Ileft_data, Ileft_w * Ileft_h * sizeof(int));
  memcpy(host_ptr_Iright_data, Iright_data, Iright_w * Iright_h * sizeof(int));
  memcpy(host_ptr_Iright_moved_data, Iright_moved_data,
         Iright_moved_w * Iright_moved_h * sizeof(int));
  memcpy(host_ptr_SAD_data, SAD_data, SAD_w * SAD_h * sizeof(float));
  memcpy(host_ptr_integralImg_data, integralImg_data,
         integralImg_w * integralImg_h * sizeof(float));
  memcpy(host_ptr_retSAD_data, retSAD_data,
         retSAD_w * retSAD_h * sizeof(float));
  memcpy(host_ptr_range_data, range_data, range_w * range_h * sizeof(int));

  bo_Ileft_data.sync(XCL_BO_SYNC_BO_TO_DEVICE);
  bo_Iright_data.sync(XCL_BO_SYNC_BO_TO_DEVICE);
  bo_Iright_moved_data.sync(XCL_BO_SYNC_BO_TO_DEVICE);
  bo_SAD_data.sync(XCL_BO_SYNC_BO_TO_DEVICE);
  bo_integralImg_data.sync(XCL_BO_SYNC_BO_TO_DEVICE);
  bo_retSAD_data.sync(XCL_BO_SYNC_BO_TO_DEVICE);
  bo_range_data.sync(XCL_BO_SYNC_BO_TO_DEVICE);

  auto kernel_exec =
      kernel(bo_Ileft_data, Ileft_w, Ileft_h, bo_Iright_data, Iright_w,
             Iright_h, bo_Iright_moved_data, Iright_moved_w, Iright_moved_h,
             win_sz, disparity, bo_SAD_data, SAD_w, SAD_h, bo_integralImg_data,
             integralImg_w, integralImg_h, bo_retSAD_data, retSAD_w, retSAD_h,
             bo_range_data, range_w, range_h);
  kernel_exec.wait();

  bo_retSAD_data.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
  memcpy(retSAD_data, host_ptr_retSAD_data,
         retSAD_w * retSAD_h * sizeof(float));
}

void correlateSAD_2D(int Ileft_w, int Ileft_h, int *Ileft_data, int Iright_w,
                     int Iright_h, int *Iright_data, int Iright_moved_w,
                     int Iright_moved_h, int *Iright_moved_data, int win_sz,
                     int disparity, int SAD_w, int SAD_h, float *SAD_data,
                     int integralImg_w, int integralImg_h,
                     float *integralImg_data, int retSAD_w, int retSAD_h,
                     float *retSAD_data) {
  int range_w = 1;
  int range_h = 2;
  int range_data[2] = {0, 0};

  cluster(Ileft_w, Ileft_h, Ileft_data, Iright_w, Iright_h, Iright_data,
          Iright_moved_w, Iright_moved_h, Iright_moved_data, win_sz, disparity,
          SAD_w, SAD_h, SAD_data, integralImg_w, integralImg_h,
          integralImg_data, retSAD_w, retSAD_h, retSAD_data, range_w, range_h,
          range_data);

  return;
}

void findDisparity(int retSAD_w, int retSAD_h, float *retSAD_data, int minSAD_w,
                   int minSAD_h, float *minSAD_data, int retDisp_w,
                   int retDisp_h, int *retDisp_data, int level, int nr,
                   int nc) {
  int i;
  int j;
  int a;
  int b;

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
                     int disparity, int SAD_w, int SAD_h, float *SAD_data,
                     int integralImg_w, int integralImg_h,
                     float *integralImg_data, int retSAD_w, int retSAD_h,
                     float *retSAD_data, int minSAD_w, int minSAD_h,
                     float *minSAD_data, int retDisp_w, int retDisp_h,
                     int *retDisp_data, int nr, int nc) {
  correlateSAD_2D(Ileft_w, Ileft_h, Ileft_data, Iright_w, Iright_h, Iright_data,
                  Iright_moved_w, Iright_moved_h, Iright_moved_data, win_sz,
                  disparity, SAD_w, SAD_h, SAD_data, integralImg_w,
                  integralImg_h, integralImg_data, retSAD_w, retSAD_h,
                  retSAD_data);

  findDisparity(retSAD_w, retSAD_h, retSAD_data, minSAD_w, minSAD_h,
                minSAD_data, retDisp_w, retDisp_h, retDisp_data, disparity, nr,
                nc);
}

void getDisparity(int Ileft_w, int Ileft_h, int *Ileft_data, int Iright_w,
                  int Iright_h, int *Iright_data, int win_sz, int max_shift,
                  int retDisp_w, int retDisp_h, int *retDisp_data) {
  int nr = Ileft_h;
  int nc = Ileft_w;
  int half_win_sz = win_sz / 2;
  int cols;
  int rows;
  int k;

  // I2D *halfWin;
  int halfWin_w = 1;
  int halfWin_h = 2;
  int *halfWin_data = (int *)malloc(sizeof(int) * halfWin_w * halfWin_h);
  halfWin_data[0] = 1;
  halfWin_data[1] = 2;

  // I2D *Iright_moved;
  int Iright_moved_w = 595;
  int Iright_moved_h = 488;
  int *Iright_moved_data =
      (int *)malloc(sizeof(int) * Iright_moved_w * Iright_moved_h);

  // I2D *IleftPadded;

  // I2D *IrightPadded;

  // F2D *SAD;
  int SAD_w = 595;
  int SAD_h = 488;
  float *SAD_data = (float *)malloc(sizeof(float) * SAD_w * SAD_h);
  for (int i = 0; i < SAD_w * SAD_h; i++) {
    SAD_data[i] = 255.0;
  }

  // F2D *integralImg;
  int integralImg_w = 595;
  int integralImg_h = 488;
  float *integralImg_data =
      (float *)malloc(sizeof(float) * integralImg_w * integralImg_h);
  for (int i = 0; i < integralImg_w * integralImg_h; i++) {
    integralImg_data[i] = 0.0;
  }

  // F2D *retSAD;
  int retSAD_w = 595;
  int retSAD_h = 488;
  float *retSAD_data = (float *)malloc(sizeof(float) * retSAD_w * retSAD_h);

  // F2D *minSAD;
  int minSAD_w = nc;
  int minSAD_h = nr;
  float *minSAD_data = (float *)malloc(sizeof(float) * minSAD_w * minSAD_h);
  for (int i = 0; i < minSAD_w * minSAD_h; i++) {
    minSAD_data[i] = 65025.0;
  }

  // I2D *retDisp;
  for (int i = 0; i < retDisp_w * retDisp_h; i++) {
    retDisp_data[i] = max_shift;
  }

  for (k = 0; k < max_shift; k++) {
    outlined_loop_0(Ileft_w, Ileft_h, Ileft_data, Iright_w, Iright_h,
                    Iright_data, Iright_moved_w, Iright_moved_h,
                    Iright_moved_data, win_sz, k, SAD_w, SAD_h, SAD_data,
                    integralImg_w, integralImg_h, integralImg_data, retSAD_w,
                    retSAD_h, retSAD_data, minSAD_w, minSAD_h, minSAD_data,
                    retDisp_w, retDisp_h, retDisp_data, nr, nc);
  }

  return;
}

int main(int argc, char **argv) {

  int Ileft_w = 587;
  int Ileft_h = 480;
  //int *Ileft_data = (int *)malloc(sizeof(int) * Ileft_w * Ileft_h);
  int *Ileft_data = readBMP("./1.bmp", &Ileft_w, &Ileft_h);

  int Iright_w = 587;
  int Iright_h = 480;
  //int *Iright_data = (int *)malloc(sizeof(int) * Iright_w * Iright_h);
  int *Iright_data = readBMP("./2.bmp", &Iright_w, &Iright_h);

  int retDisp_w = 595;
  int retDisp_h = 488;
  int *retDisp_data = (int *)malloc(sizeof(int) * retDisp_w * retDisp_h);

  int WIN_SZ = 8;
  int SHIFT = 64;

  auto start = std::chrono::high_resolution_clock::now();

  try {
    getDisparity(Ileft_w, Ileft_h, Ileft_data, Iright_w, Iright_h, Iright_data,
                WIN_SZ, SHIFT, retDisp_w, retDisp_h, retDisp_data);
  } catch (const std::exception& e) {
      std::cerr << "Exception! " << e.what() << std::endl;
  }

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "Duration: " << duration.count() << "us" << std::endl;

  long sum = 0;
  for (int i = 0; i < retDisp_w * retDisp_h; i++) {
    sum += retDisp_data[i];
  }
  printf("sum = %ld\n", sum);

  writeBMP("./output.bmp", retDisp_w, retDisp_h, retDisp_data);
  return 0;
}