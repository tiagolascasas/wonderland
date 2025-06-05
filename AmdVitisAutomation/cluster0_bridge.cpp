#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <iostream>
#include <fstream>
#include "experimental/xrt_bo.h"
#include "experimental/xrt_device.h"
#include "experimental/xrt_kernel.h"
void cluster0(int output[262144], int filter[9], int temp_buf[262144], int image_gray[262144]);
void cluster0_hw_bridge(int output[262144], int filter[9], int temp_buf[262144], int image_gray[262144])
{

    auto device = xrt::device(0);
    auto uuid = device.load_xclbin("./cluster.xclbin");
    auto kernel = xrt::kernel(device, uuid, "cluster0");

    auto bo_output = xrt::bo(device, 262144 * sizeof(int), kernel.group_id(0));
    auto bo_filter = xrt::bo(device, 9 * sizeof(int), kernel.group_id(1));
    auto bo_temp_buf = xrt::bo(device, 262144 * sizeof(int), kernel.group_id(2));
    auto bo_image_gray = xrt::bo(device, 262144 * sizeof(int), kernel.group_id(3));

    bo_output.write(output);
    bo_output.sync(XCL_BO_SYNC_BO_TO_DEVICE);

    bo_filter.write(filter);
    bo_filter.sync(XCL_BO_SYNC_BO_TO_DEVICE);

    bo_image_gray.write(image_gray);
    bo_image_gray.sync(XCL_BO_SYNC_BO_TO_DEVICE);

    auto kernel_run = xrt::run(kernel);
    kernel_run.set_arg(0, bo_output);
    kernel_run.set_arg(1, bo_filter);
    kernel_run.set_arg(2, bo_temp_buf);
    kernel_run.set_arg(3, bo_image_gray);
    kernel_run.start();

    kernel_run.wait();

    bo_output.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
    bo_output.read(output);
    bo_temp_buf.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
    bo_temp_buf.read(temp_buf);
}
