#include <stdint.h>

extern "C" {
void vadd(unsigned int* in1, unsigned int* in2, unsigned int* out, int size) {
    for (int i = 0; i < size; i++) {
        out[i] = in1[i] + in2[i];
    }
}
}
