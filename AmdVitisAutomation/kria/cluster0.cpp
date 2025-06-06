#include <cstring>

void cluster0(int v1[2048], int v2[2048], int v3[2048])
{
    for (int i = 0; i < 2048; i++)
    {
#pragma HLS unroll factor = 32
#pragma HLS pipeline II = 1
        v3[i] = v1[i] + v2[i];
    }
}
