#include <cstring>
#include <iostream>
#include <limits.h>
#include <linux/limits.h>
#include <random>
#include <unistd.h>

#include "deprecated/xrt.h"
#include "experimental/xrt_bo.h"
#include "experimental/xrt_device.h"
#include "experimental/xrt_kernel.h"

#include "config.h"
#include "edgedetect.h"
#include "experimental/xrt_xclbin.h"
#include "util.h"

#define ITER 1
#define USE_REAL_IMAGE

void wrapped_edgedetect(unsigned char image_rgb[H * W * 3],
                        unsigned char image_gray[H * W],
                        unsigned char temp_buf[H * W],
                        unsigned char filter[K * K],
                        unsigned char output[H * W]) {

  auto device = xrt::device(0);
  auto uuid = device.load_xclbin("./binary_container_1.xclbin");
  auto kernel = xrt::kernel(device, uuid, "edgedetect");

  auto bo_image_rgb = xrt::bo(device, H * W * 3, kernel.group_id(0));
  auto bo_image_gray = xrt::bo(device, H * W, kernel.group_id(1));
  auto bo_temp_buf = xrt::bo(device, H * W, kernel.group_id(2));
  auto bo_filter = xrt::bo(device, K * K, kernel.group_id(3));
  auto bo_output = xrt::bo(device, H * W, kernel.group_id(0));

  unsigned char *host_ptr_image_rgb = bo_image_rgb.map<unsigned char *>();
  unsigned char *host_ptr_image_gray = bo_image_gray.map<unsigned char *>();
  unsigned char *host_ptr_temp_buf = bo_temp_buf.map<unsigned char *>();
  unsigned char *host_ptr_filter = bo_filter.map<unsigned char *>();
  unsigned char *host_ptr_output = bo_output.map<unsigned char *>();

  memcpy(host_ptr_image_rgb, image_rgb, H * W * 3);
  memcpy(host_ptr_image_gray, image_gray, H * W);
  memcpy(host_ptr_temp_buf, temp_buf, H * W);
  memcpy(host_ptr_filter, filter, K * K);
  memcpy(host_ptr_output, output, H * W);

  bo_image_rgb.sync(XCL_BO_SYNC_BO_TO_DEVICE);
  bo_image_gray.sync(XCL_BO_SYNC_BO_TO_DEVICE);
  bo_temp_buf.sync(XCL_BO_SYNC_BO_TO_DEVICE);
  bo_filter.sync(XCL_BO_SYNC_BO_TO_DEVICE);
  bo_output.sync(XCL_BO_SYNC_BO_TO_DEVICE);

  auto kernel_execution = kernel(bo_image_rgb, bo_image_gray, bo_temp_buf, bo_filter, bo_output);
  kernel_execution.wait();

  bo_image_rgb.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
  bo_image_gray.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
  bo_temp_buf.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
  bo_filter.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
  bo_output.sync(XCL_BO_SYNC_BO_FROM_DEVICE);

  memcpy(image_rgb, host_ptr_image_rgb, H * W * 3);
  memcpy(image_gray, host_ptr_image_gray, H * W);
  memcpy(temp_buf, host_ptr_temp_buf, H * W);
  memcpy(filter, host_ptr_filter, K * K);
  memcpy(output, host_ptr_output, H * W);
}

int main(int argc, char **argv) {

  unsigned char *image_rgb;
  try {
    image_rgb = readBMP("./input.bmp", W, H, 8);
  } catch (...) {
    std::cout << "Failed to load image, loading random data instead..." << std::endl;
    image_rgb = new unsigned char[W * H * 3];
  }

  unsigned char image_gray[H * W] = {0};
  unsigned char temp_buf[H * W] = {0};
  unsigned char filter[K * K] = {0};
  unsigned char output[H * W] = {0};

  auto start = std::chrono::high_resolution_clock::now();
  
  for (int i = 0; i < ITER; i++) {
    wrapped_edgedetect(image_rgb, image_gray, temp_buf, filter, output);
  }

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "Duration: " << duration.count() << "us" << std::endl;

  try {
    writeBMPGrayscale("./output.bmp", output, W, H);
  } catch (...) {
    std::cout << "Failed to save the output image" << std::endl;
  }

  return 0;
}