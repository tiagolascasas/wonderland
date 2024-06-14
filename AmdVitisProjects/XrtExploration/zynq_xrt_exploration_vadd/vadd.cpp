extern "C" {
    void vadd(int *in1, int *in2, int *out, int size) {
        for (int i = 0; i < size; i++) {
            out[i] = in1[i] + in2[i];
        }
    }
}