#define N 1000000

void f1(int A[N], int B[N]) {
    for (int i = 0; i < N; i++) {
        B[i] = A[i] * A[i] + 2;
    }
}

void f2(int B[N]) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += B[N] * 2;
    }
}

void top_function(int* A, int* B) {
#pragma HLS DATAFLOW
    f1(A, B);
    f2(B);
}