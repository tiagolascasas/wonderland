#include <iostream>
#include <random>
#include <cstring>
#include <linux/limits.h>
#include <unistd.h>
#include <limits.h>

// XRT includes
#include "experimental/xrt_bo.h"
#include "experimental/xrt_device.h"
#include "experimental/xrt_kernel.h"
#include "xrt/xrt_uuid.h"

#define DATA_SIZE 4096

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

void wrapped_vadd(int* A, int* B, int* C, int size, xrt::device device, xrt::uuid uuid) {
    uint64_t start;
    uint64_t end;

    xrt::kernel kernel = xrt::kernel(device, uuid, "vadd");

    start = get_cpu_counter();
    xrt::bo bo_A = xrt::bo(device, size * sizeof(A[0]), kernel.group_id(0));
    xrt::bo bo_B = xrt::bo(device, size * sizeof(A[0]), kernel.group_id(1));
    xrt::bo bo_C = xrt::bo(device, size * sizeof(A[0]), kernel.group_id(2));

    int* host_ptr_A = bo_A.map<int*>();
    int* host_ptr_B = bo_B.map<int*>();
    int* host_ptr_C = bo_C.map<int*>();

    memcpy(host_ptr_A, A, size * sizeof(A[0]));
    memcpy(host_ptr_B, B, size * sizeof(B[0]));

    bo_A.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    bo_B.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    end = get_cpu_counter();

    std::cout << "CPU->FPGA copy time: " << end - start << "us | " << (end - start) / 10e6  << "s" << std::endl;

    start = get_cpu_counter();
    xrt::run kernel_execution = kernel(bo_A, bo_B, bo_C, size);
    kernel_execution.wait();
    end = get_cpu_counter();

    std::cout << "Kernel exec time: " << end - start << "us | " << (end - start) / 10e6  << "s" << std::endl;

    start = get_cpu_counter();
    bo_C.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
    
    memcpy(C, host_ptr_C, size * sizeof(C[0]));
    end = get_cpu_counter();

    std::cout << "FPGA->CPU time: " << end - start << "us | " << (end - start) / 10e6  << "s" << std::endl;
}

int main() {
    // Xclbin setup
    char buffer[PATH_MAX];
    getcwd(buffer, sizeof(buffer));

    auto xclbin_path = std::string(buffer).append("/").append("vadd.xclbin");
    auto xclbin = xrt::xclbin(xclbin_path);
    auto device_id = 0;

    auto device = xrt::device(device_id);
    auto uuid = device.load_xclbin(xclbin);

    int SIZE_1 = 1024;
    int *A1 = new int[SIZE_1];
    int *B1 = new int[SIZE_1];
    int *C1 = new int[SIZE_1];
    for (int i = 0; i < SIZE_1; i++) {
        A1[i] = i;
        B1[i] = i;
        C1[i] = 0;
    }
    wrapped_vadd(A1, B1, C1, SIZE_1, device, uuid);
    std::cout << "C1 = [" << C1[0] << ", " << C1[1] << ", " << C1[2] << ", ... , " << C1[SIZE_1 - 1] << "]" << std::endl;

    int SIZE_2 = 2e6;
    int *A2 = new int[SIZE_2];
    int *B2 = new int[SIZE_2];
    int *C2 = new int[SIZE_2];
    for (int i = 0; i < SIZE_2; i++) {
        A2[i] = i;
        B2[i] = i;
        C2[i] = 0;
    }
    wrapped_vadd(A2, B2, C2, SIZE_2, device, uuid);
    std::cout << "C2 = [" << C2[0] << ", " << C2[1] << ", " << C2[2] << ", ... , " << C2[SIZE_2 - 1] << "]" << std::endl;

    return 0;
}
