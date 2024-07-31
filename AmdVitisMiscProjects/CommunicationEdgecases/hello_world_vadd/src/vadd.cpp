extern "C" {
void vadd(int size) {
    int n = size;
    for (int i = 0; i < 1024; i++) {
        n += i * 2 + size;
    }
}
}
