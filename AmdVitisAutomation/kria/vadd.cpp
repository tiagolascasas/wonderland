#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
using namespace std::chrono;

void cluster0_hw_bridge(int v1[2048], int v2[2048], int v3[2048]);

void vadd(int v1[2048], int v2[2048], int v3[2048])
{
    int local_v1[2048];
    int local_v2[2048];
    int local_v3[2048];
    memcpy(local_v1, v1, 2048 * sizeof(int));
    memcpy(local_v2, v2, 2048 * sizeof(int));

    for (int i = 0; i < 2048; i++)
    {
        local_v3[i] = local_v1[i] + local_v2[i];
    }
    memcpy(v3, local_v3, 2048 * sizeof(int));
}

void cluster0_sw(int v1[2048], int v2[2048], int v3[2048])
{
    vadd(v1, v2, v3);
}

int main()
{
    srand(42);
    std::ofstream log_file_0;
    log_file_0.open("app_exec_time.csv", std::ios_base::app);
    int *v1 = (int *)calloc(2048, sizeof(int));
    int *v2 = (int *)calloc(2048, sizeof(int));
    int *v3 = (int *)calloc(2048, sizeof(int));

    for (int i = 0; i < 2048; i++)
    {
        v1[i] = rand() % 10;
        v2[i] = rand() % 10;
    }

    auto start = high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point clava_timing_start_0;
    std::chrono::high_resolution_clock::time_point clava_timing_end_0;
    clava_timing_start_0 = std::chrono::high_resolution_clock::now();

#ifndef OFFLOAD
    cluster0_sw(v1, v2, v3);
#else
    cluster0_hw_bridge(v1, v2, v3);
#endif

    clava_timing_end_0 = std::chrono::high_resolution_clock::now();
    long long clava_timing_duration_0 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_0 - clava_timing_start_0).count();
    log_file_0 << clava_timing_duration_0 << "us" << "\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Duration: " << duration.count() << "us" << std::endl;

    int actual = 0;
    int expected = 18606;
    for (int i = 0; i < 2048; i++)
    {
        actual += v3[i];
    }
    cout << "Checksum: expected = " << expected << ", actual = " << actual << (expected == actual ? " (VERIFIED)" : " (ERROR)") << endl;

    return 0;
}
