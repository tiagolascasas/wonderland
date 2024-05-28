#include <iostream>
#include <cstdint>

inline uint64_t begin_read() {
#if defined(__arm__) || defined(__aarch64__)
    uint32_t value;
    asm volatile("MRC p15, 0, %0, c9, c14, 0" : "=r"(value));
    value |= 1 << 1;
    asm volatile("MCR p15, 0, %0, c9, c14, 0" : : "r"(value));
    asm volatile("MCR p15, 0, %0, c9, c12, 0" : : "r"(0x00000007));
    asm volatile("MCR p15, 0, %0, c9, c12, 1" : : "r"(0x80000000));
    asm volatile("MRC p15, 0, %0, c9, c12, 0" : "=r"(value));
    value |= 0x1;
    asm volatile("MCR p15, 0, %0, c9, c12, 0" : : "r"(value));

    uint32_t res;
    asm volatile("MRC p15, 0, %0, c9, c13, 0" : "=r"(res));
    uint64_t extended = static_cast<uint64_t>(res);
    return extended;

#elif defined(__x86_64__) || defined(__i386__)
    unsigned int hi, lo;
    asm volatile("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;

#else
    std::cout << "Unsupported architecture for HW timer read" << std::endl;
    return 0;
#endif
}

inline uint32_t end_read() {
#if defined(__arm__) || defined(__aarch64__)
    uint32_t res;
    asm volatile("MRC p15, 0, %0, c9, c13, 0" : "=r"(res));
    uint64_t extended = static_cast<uint64_t>(res);

    uint32_t value;
    asm volatile("MRC p15, 0, %0, c9, c12, 0" : "=r"(value));
    value &= ~0x1;
    asm volatile("MCR p15, 0, %0, c9, c12, 0" : : "r"(value));

    return extended;

#elif defined(__x86_64__) || defined(__i386__)
    unsigned int hi, lo;
    asm volatile("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
    
#else
    std::cout << "Unsupported architecture for HW timer read" << std::endl;
    return 0;
#endif
}