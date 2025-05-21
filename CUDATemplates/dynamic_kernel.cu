#include <cstdio>
#include <cuda_runtime.h>

__global__ void mult_array_const(float *data, int N)
{
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < N)
    {
        data[idx] *= 2.0f;
    }
}

void bridge_mult_array_const(float *host_data, int N)
{
    float *device_data;
    cudaMalloc(&device_data, N * sizeof(float));
    cudaMemcpy(device_data, host_data, N * sizeof(float), cudaMemcpyHostToDevice);

    int device;
    cudaGetDevice(&device);

    cudaDeviceProp props;
    cudaGetDeviceProperties(&props, device);

    int threadsPerBlock = props.maxThreadsPerBlock;
    int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;

    printf("Using device %d: %s\n", device, props.name);
    printf("Max threads per block: %d\n", threadsPerBlock);
    printf("Blocks per grid: %d\n", blocksPerGrid);
    printf("Total threads: %d\n", blocksPerGrid * threadsPerBlock);
    printf("Total data size: %lu bytes\n", N * sizeof(float));
    printf("Total data size in MB: %.2f MB\n", (float)(N * sizeof(float)) / (1024 * 1024));

    mult_array_const<<<blocksPerGrid, threadsPerBlock>>>(device_data, N);

    cudaDeviceSynchronize();

    cudaMemcpy(host_data, device_data, N * sizeof(float), cudaMemcpyDeviceToHost);
    cudaFree(device_data);
}

int main()
{
    int N = 10000;

    float *host_data = new float[N];
    for (int i = 0; i < N; ++i)
        host_data[i] = (float)i;

    bridge_mult_array_const(host_data, N);
    for (int i = 0; i < 10; ++i)
    {
        printf("host_data[%d] = %f\n", i, host_data[i]);
    }

    delete[] host_data;

    return 0;
}
