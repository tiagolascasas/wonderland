#include <iostream>
#include <cstring>
#include <linux/limits.h>
#include <unistd.h>
#include <limits.h>

#include "experimental/xrt_bo.h"
#include "experimental/xrt_device.h"
#include "experimental/xrt_kernel.h"

#include "timer.hpp"

#define DATA_SIZE 1024

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

void* align_pointer(void* unaligned_ptr, size_t size, size_t alignment) {
    void* aligned_ptr = nullptr;
    if (posix_memalign(&aligned_ptr, alignment, size) != 0) {
        return nullptr;
    }

    std::memcpy(aligned_ptr, unaligned_ptr, size);

    return aligned_ptr;
}

void wrapped_vadd(unsigned int* in1, unsigned int* in2, unsigned int* out, int size) {
    char buffer[PATH_MAX];
    getcwd(buffer, sizeof(buffer));

    auto xclbin = std::string(buffer);
    xclbin.append("/").append("vadd.xclbin");
    auto device_id = 0;

    auto device = xrt::device(device_id);
    auto uuid = device.load_xclbin(xclbin);

    auto krnl = xrt::kernel(device, uuid, "vadd");

    uint64_t start;
    uint64_t end;

    start = get_cpu_counter();
    unsigned int* aligned_in1 = (unsigned int*)align_pointer(in1, size * sizeof(unsigned int), 4096);
    unsigned int* aligned_in2 = (unsigned int*)align_pointer(in2, size * sizeof(unsigned int), 4096);
    unsigned int* aligned_out = (unsigned int*)align_pointer(out, size * sizeof(unsigned int), 4096);

    auto bo0 = xrt::bo(device, aligned_in1, size * sizeof(unsigned int), krnl.group_id(0));
    auto bo1 = xrt::bo(device, aligned_in2, size * sizeof(unsigned int), krnl.group_id(1));
    auto bo_out = xrt::bo(device, aligned_out, size * sizeof(unsigned int), krnl.group_id(2));

    bo0.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    bo1.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    end = get_cpu_counter();
    std::cout << "CPU->FPGA copy time: " << end - start << "us | " << (end - start) / 10e6  << "s" << std::endl;

    start = get_cpu_counter();
    auto run = krnl(bo0, bo1, bo_out, size);
    run.wait();
    end = get_cpu_counter();
    std::cout << "Kernel exec time: " << end - start << "us | " << (end - start) / 10e6  << "s" << std::endl;

    start = get_cpu_counter();
    bo_out.sync(XCL_BO_SYNC_BO_FROM_DEVICE);

    std::memcpy(in1, aligned_in1, size * sizeof(unsigned int));
    std::memcpy(in2, aligned_in2, size * sizeof(unsigned int));
    std::memcpy(out, aligned_out, size * sizeof(unsigned int));
    end = get_cpu_counter();
    std::cout << "FPGA->CPU time: " << end - start << "us | " << (end - start) / 10e6  << "s" << std::endl;
}

int main() {
    unsigned int* in1 = new unsigned int[DATA_SIZE];
    unsigned int* in2 = new unsigned int[DATA_SIZE];
    unsigned int* out = new unsigned int[DATA_SIZE];

    for (int i = 0; i < DATA_SIZE; ++i) {
        in1[i] = i + 1;
        in2[i] = 1;
        out[i] = 0;
    }

    wrapped_vadd(in1, in2, out, DATA_SIZE);

    for (int i = 0; i < DATA_SIZE; i++) {
        if (i % 32 == 0) {
            std::cout << in1[i] << " + " << in2[i] << " = " << out[i] << std::endl;
        }
    }

    delete[] in1;
    delete[] in2;
    delete[] out;

    return 0;
}
