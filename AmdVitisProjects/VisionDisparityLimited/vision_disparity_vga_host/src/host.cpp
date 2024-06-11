#include <iostream>
#include <random>
#include <cstring>
#include <linux/limits.h>
#include <unistd.h>
#include <limits.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "experimental/xrt_bo.h"
#include "experimental/xrt_device.h"
#include "experimental/xrt_kernel.h"

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

void fill_random(int* array, size_t size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);

    for (size_t i = 0; i < size; ++i) {
        array[i] = dis(gen);
    }
}

void iMallocHandle_rep1(int *range_w, int *range_h, int **range_data)
{
    *range_w = 1;
    *range_h = 2;
    *range_data = (int *)malloc(sizeof(int) * (*range_w) * (*range_h));
}

void iFreeHandle_rep4(int **range_data) { free(*range_data); }



// from findDisparity.c
void findDisparity(int retSAD_w, int retSAD_h, int *retSAD_data,
                   int minSAD_w, int minSAD_h, int *minSAD_data,
                   int retDisp_w, int retDisp_h, int *retDisp_data, int level,
                   int nr, int nc)
{
    int i;
    int j;
    int a;
    int b;
    //printf("findDisparity: nr = %d, nc = %d\n", nr, nc);
    for (i = 0; i < nr; i++)
    {
#pragma HLS loop_tripcount min = 480 max = 480
        for (j = 0; j < nc; j++)
        {
#pragma HLS loop_tripcount min = 587 max = 587
            a = retSAD_data[(i) * (retSAD_w) + (j)];
            b = minSAD_data[(i) * (minSAD_w) + (j)];
            int decomp_0;
            decomp_0 = a < b;
            if (decomp_0)
            {
                minSAD_data[(i) * (minSAD_w) + (j)] = a;
                retDisp_data[(i) * (retDisp_w) + (j)] = level;
            }
        }
    }

    return;
}

void outlined_loop_0(int Ileft_w, int Ileft_h, int *Ileft_data, int Iright_w, int Iright_h, int *Iright_data, int Iright_moved_w, int Iright_moved_h, int *Iright_moved_data, int win_sz, int disparity, int SAD_w, int SAD_h, int *SAD_data, int integralImg_w, int integralImg_h, int *integralImg_data, int retSAD_w, int retSAD_h, int *retSAD_data, int range_w, int range_h, int *range_data, int minSAD_w, int minSAD_h, int *minSAD_data, int retDisp_w, int retDisp_h, int *retDisp_data, int nr, int nc)
{
    correlateSAD_2D(Ileft_w, Ileft_h, Ileft_data, Iright_w, Iright_h,
                    Iright_data, Iright_moved_w, Iright_moved_h,
                    Iright_moved_data, win_sz, disparity, SAD_w, SAD_h,
                    SAD_data, integralImg_w, integralImg_h, integralImg_data,
                    retSAD_w, retSAD_h, retSAD_data,
                    range_w, range_h, range_data);
    findDisparity(retSAD_w, retSAD_h, retSAD_data, minSAD_w, minSAD_h,
                  minSAD_data, retDisp_w, retDisp_h, retDisp_data, disparity,
                  nr, nc);
}

// adapted from getDisparity.c
void top_level(
                int Ileft_w, int Ileft_h, int *Ileft_data, 
                int Iright_w, int Iright_h, int *Iright_data, 
                int Iright_moved_w, int Iright_moved_h, int *Iright_moved_data, 
                int win_sz,
                int SAD_w, int SAD_h, int *SAD_data, 
                int integralImg_w, int integralImg_h, int *integralImg_data, 
                int retSAD_w, int retSAD_h, int *retSAD_data, 
                int minSAD_w, int minSAD_h, int *minSAD_data, 
                int retDisp_w, int retDisp_h, int *retDisp_data, 
                int nr, int nc,
                int range_w, int range_h, int *range_data
)
{
    for (int disparity = 0; disparity < 64; disparity++)
    {
        outlined_loop_0(Ileft_w, Ileft_h, Ileft_data, Iright_w, Iright_h, Iright_data, Iright_moved_w, Iright_moved_h, Iright_moved_data, win_sz, disparity, SAD_w, SAD_h, SAD_data, integralImg_w, integralImg_h, integralImg_data, retSAD_w, retSAD_h, retSAD_data, range_w, range_h, range_data, minSAD_w, minSAD_h, minSAD_data, retDisp_w, retDisp_h, retDisp_data, nr, nc);
    }
}

int main() {
    // Xclbin setup
    char buffer[PATH_MAX];
    getcwd(buffer, sizeof(buffer));

    auto xclbin = std::string(buffer);
    xclbin.append("/").append("disparity.xclbin");
    auto device_id = 0;

    auto device = xrt::device(device_id);
    auto uuid = device.load_xclbin(xclbin);

    auto krnl = xrt::kernel(device, uuid, "top_level");

    // Data declaration and initialization
    //int WIDTH = 595;
    //int HEIGHT = 488;
    int WIDTH = 20;
    int HEIGHT = 10;
    int IMG_SIZE = HEIGHT * WIDTH;
    int BUF_SIZE = IMG_SIZE * sizeof(int);

    int Ileft_w = WIDTH;
    int Ileft_h = HEIGHT;
    int *Ileft_data = new int[IMG_SIZE];
    fill_random(Ileft_data, IMG_SIZE);
     
    int Iright_w = WIDTH;
    int Iright_h = HEIGHT; 
    int *Iright_data = new int[IMG_SIZE];
    fill_random(Iright_data, IMG_SIZE);
    
    int Iright_moved_w = WIDTH;
    int Iright_moved_h = HEIGHT;
    int *Iright_moved_data = new int[IMG_SIZE];
    fill_random(Iright_moved_data, IMG_SIZE);
    
    int win_sz = 8;
               
    int SAD_w = WIDTH;
    int SAD_h = HEIGHT;
    int *SAD_data = new int[IMG_SIZE];
    fill_random(SAD_data, IMG_SIZE);
    
    int integralImg_w = WIDTH;
    int integralImg_h = HEIGHT;
    int *integralImg_data = new int[IMG_SIZE];
    fill_random(integralImg_data, IMG_SIZE);
    
    int retSAD_w = WIDTH;
    int retSAD_h = HEIGHT;
    int *retSAD_data = new int[IMG_SIZE];
    fill_random(retSAD_data, IMG_SIZE);
    
    int minSAD_w = WIDTH;
    int minSAD_h = HEIGHT;
    int *minSAD_data = new int[IMG_SIZE];
    fill_random(minSAD_data, IMG_SIZE);
    
    int retDisp_w = WIDTH;
    int retDisp_h = HEIGHT;
    int *retDisp_data = new int[IMG_SIZE];
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
    int PAGE_SIZE = 4096;

    int *aligned_Ileft_data = (int*)align_pointer(Ileft_data, BUF_SIZE, PAGE_SIZE);
    int *aligned_Iright_data = (int*)align_pointer(Iright_data, BUF_SIZE, PAGE_SIZE);
    int *aligned_Iright_moved_data = (int*)align_pointer(Iright_moved_data, BUF_SIZE, PAGE_SIZE);
    int *aligned_SAD_data = (int*)align_pointer(SAD_data, BUF_SIZE, PAGE_SIZE);
    int *aligned_integralImg_data = (int*)align_pointer(integralImg_data, BUF_SIZE, PAGE_SIZE);
    int *aligned_retSAD_data = (int*)align_pointer(retSAD_data, BUF_SIZE, PAGE_SIZE);
    int *aligned_minSAD_data = (int*)align_pointer(minSAD_data, BUF_SIZE, PAGE_SIZE);
    int *aligned_range_data = (int*)align_pointer(range_data, 2, PAGE_SIZE);

    auto bo_Ileft_data = xrt::bo(device, aligned_Ileft_data, BUF_SIZE, PAGE_SIZE, krnl.group_id(0));
    auto bo_Iright_data = xrt::bo(device, aligned_Iright_data, BUF_SIZE, PAGE_SIZE, krnl.group_id(1));
    auto bo_Iright_moved_data = xrt::bo(device, aligned_Iright_moved_data, BUF_SIZE, PAGE_SIZE, krnl.group_id(2));
    auto bo_SAD_data = xrt::bo(device, aligned_SAD_data, BUF_SIZE, PAGE_SIZE, krnl.group_id(3));
    auto bo_integralImg_data = xrt::bo(device, aligned_integralImg_data, BUF_SIZE, PAGE_SIZE, krnl.group_id(0));
    auto bo_retSAD_data = xrt::bo(device, aligned_retSAD_data, BUF_SIZE, PAGE_SIZE, krnl.group_id(1));
    auto bo_minSAD_data = xrt::bo(device, aligned_minSAD_data, BUF_SIZE, PAGE_SIZE, krnl.group_id(2));
    auto bo_range_data = xrt::bo(device, aligned_range_data, sizeof(int) * 2, PAGE_SIZE, krnl.group_id(3));

    int *aligned_retDisp_data = (int*)align_pointer(retDisp_data, BUF_SIZE, PAGE_SIZE);
    auto bo_retDisp_data = xrt::bo(device, aligned_retDisp_data, BUF_SIZE, PAGE_SIZE, krnl.group_id(0));

    bo_Ileft_data.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    bo_Iright_data.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    bo_Iright_moved_data.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    bo_SAD_data.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    bo_integralImg_data.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    bo_retSAD_data.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    bo_minSAD_data.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    bo_range_data.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    end = get_cpu_counter();

    std::cout << "CPU->FPGA copy time: " << end - start << "us | " << (end - start) / 10e6  << "s" << std::endl;

    start = get_cpu_counter();
    auto run = krnl(
        Ileft_w, Ileft_h, bo_Ileft_data,
        Iright_w, Iright_h, bo_Iright_data,
        Iright_moved_w, Iright_moved_h, bo_Iright_moved_data,
        win_sz,
        SAD_w, SAD_h, bo_SAD_data,
        integralImg_w, integralImg_h, bo_integralImg_data,
        retSAD_w, retSAD_h, bo_retSAD_data,
        minSAD_w, minSAD_h, bo_minSAD_data,
        retDisp_w, retDisp_h, bo_retDisp_data,
        nr, nc,
        range_w, range_h, bo_range_data
    );
    run.wait();
    end = get_cpu_counter();

    std::cout << "Kernel exec time: " << end - start << "us | " << (end - start) / 10e6  << "s" << std::endl;

    start = get_cpu_counter();
    bo_retDisp_data.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
    std::memcpy(retDisp_data, aligned_retDisp_data, BUF_SIZE);
    end = get_cpu_counter();

    std::cout << "FPGA->CPU time: " << end - start << "us | " << (end - start) / 10e6  << "s" << std::endl;

    return 0;
}