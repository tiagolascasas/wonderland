#include <stdio.h>

void funA(int x, int *X, int *Y) {
    for (int i = 0; i < 100; i++) {
        X[i] = Y[i] * x;
    }
}

int funD(int x) {
    return x * x * x;
}

int funB(int *X, int *Y) {
    for (int i = 0; i < 100; i++) {
        X[i] = X[i] * Y[i];
    }

    for (int i = 0; i < 100; i++) {
        Y[i] = X[i] + Y[i];
        Y[i] = funD(Y[i]);
    }

    for (int i = 0; i < 100; i++) {
        Y[i] = X[i] * Y[i];
        Y[i] = funD(Y[i]);
    }
    return X[0] + Y[0];
}

int funC(int x, int y, int *X) {
    funB(X, X);
    return funD(x) + funD(y) + X[6];
}

int main() {
    int A[100] = {1};
    int B[100] = {2};
    int C[100] = {3};

    funA(500, A, B);
    int x = funB(B, C);

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            int y = x + A[0];
            funC(x, y, C);
            funC(y, x, C);
        }
    }

    int sumA = 0;
    int sumB = 0;
    int sumC = 0;
    for (int i = 0; i < 100; i++) {
        sumA += A[i];
        sumB += B[i];
        sumC += C[i];
    }
    printf("A: %d, B: %d, C: %d, x: %d\n", sumA, sumB, sumC, x);

    return A[2];
}