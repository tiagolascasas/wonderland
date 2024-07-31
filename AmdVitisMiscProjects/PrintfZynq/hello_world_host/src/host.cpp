#include <iostream>
#include <cstring>
#include <linux/limits.h>
#include <unistd.h>
#include <limits.h>

#include "experimental/xrt_bo.h"
#include "experimental/xrt_device.h"
#include "experimental/xrt_kernel.h"
#include "xrt/xrt_uuid.h"

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

void print_device_info(xrt::device device) {
    std::cout << "Device info" << std::endl 
            << "bfd: " << device.get_info<xrt::info::device::bdf>() << std::endl
            // << "interface_uuid: " << device.get_info<xrt::info::device::interface_uuid>() << std::endl
            // << "kdma: " << device.get_info<xrt::info::device::kdma>() << std::endl
            << "max_clock_frequency_mhz: " << device.get_info<xrt::info::device::max_clock_frequency_mhz>() << std::endl
            << "m2m: " << device.get_info<xrt::info::device::m2m>() << std::endl
            << "name: " << device.get_info<xrt::info::device::name>() << std::endl
            << "nodma: " << device.get_info<xrt::info::device::nodma>() << std::endl
            // << "offline: " << device.get_info<xrt::info::device::offline>() << std::endl
            // << "electrical: " << device.get_info<xrt::info::device::electrical>() << std::endl
            // << "thermal: " << device.get_info<xrt::info::device::thermal>() << std::endl
            // << "mechanical: " << device.get_info<xrt::info::device::mechanical>() << std::endl
            //<< "memory: " << device.get_info<xrt::info::device::memory>() << std::endl
            // << "platform: " << device.get_info<xrt::info::device::platform>() << std::endl
            // << "pcie_info: " << device.get_info<xrt::info::device::pcie_info>() << std::endl
            << "host: " << device.get_info<xrt::info::device::host>() << std::endl
            // << "aie: " << device.get_info<xrt::info::device::aie>() << std::endl
            // << "aie_shim: " << device.get_info<xrt::info::device::aie_shim>() << std::endl
            // << "dynamic_regions: " << device.get_info<xrt::info::device::dynamic_regions>() << std::endl
            // << "vmr: " << device.get_info<xrt::info::device::vmr>() << std::endl
            // << "aie_mem: " << device.get_info<xrt::info::device::aie_mem>() << std::endl
            << std::endl;
}

void vadd_simple(xrt::device device, xrt::uuid uuid) {
    unsigned int* in1 = new unsigned int[DATA_SIZE];
    unsigned int* in2 = new unsigned int[DATA_SIZE];
    unsigned int* out = new unsigned int[DATA_SIZE];

    for (int i = 0; i < DATA_SIZE; ++i) {
        in1[i] = i + 1;
        in2[i] = 1;
        out[i] = 0;
    }

    auto krnl = xrt::kernel(device, uuid, "vadd");

    size_t size = DATA_SIZE;

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

    for (int i = 0; i < DATA_SIZE; i++) {
        if (i % 32 == 0) {
            std::cout << in1[i] << " + " << in2[i] << " = " << out[i] << std::endl;
        }
    }

    delete[] in1;
    delete[] in2;
    delete[] out;
    delete device;

    return;
}

int main() {
        char buffer[PATH_MAX];
    getcwd(buffer, sizeof(buffer));

    auto xclbin = std::string(buffer);
    xclbin.append("/").append("vadd.xclbin");
    auto device_id = 0;

    auto device = xrt::device(device_id);
    auto uuid = device.load_xclbin(xclbin);

    print_device_info(device);

    vadd_simple(device, uuid);
    std::cout << "-------------------------------" << std::endl;
    vadd_simple(device, uuid);
    return 0;
}