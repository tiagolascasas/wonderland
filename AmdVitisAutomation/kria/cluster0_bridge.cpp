#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <iostream>
#include <fstream>
#include "experimental/xrt_bo.h"
#include "experimental/xrt_device.h"
#include "experimental/xrt_kernel.h"

void cluster0_hw_bridge(int v1[2048], int v2[2048], int v3[2048])
{
    auto device = xrt::device(0);
    auto uuid = device.load_xclbin("./cluster.xclbin");
    auto kernel = xrt::kernel(device, uuid, "cluster0");

    auto bo_v1 = xrt::bo(device, 2048 * sizeof(int), kernel.group_id(0));
    auto bo_v2 = xrt::bo(device, 2048 * sizeof(int), kernel.group_id(1));
    auto bo_v3 = xrt::bo(device, 2048 * sizeof(int), kernel.group_id(2));

    bo_v1.write(v1);
    bo_v1.sync(XCL_BO_SYNC_BO_TO_DEVICE);

    bo_v2.write(v2);
    bo_v2.sync(XCL_BO_SYNC_BO_TO_DEVICE);

    auto kernel_run = xrt::run(kernel);
    kernel_run.set_arg(0, v1);
    kernel_run.set_arg(1, v2);
    kernel_run.set_arg(2, v3);
    kernel_run.start();

    kernel_run.wait();

    bo_v3.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
    bo_v3.read(v3);
}
