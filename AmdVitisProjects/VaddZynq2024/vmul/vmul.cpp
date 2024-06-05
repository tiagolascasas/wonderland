void vmul(int A[4096], int B[4096], int C[4096]) {
    for (int i = 0; i < 4096; i++) {
        #pragma HLS unroll factor=4
        C[i] = A[i] * B[i];
    }
}