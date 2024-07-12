#include "config.h"

void edgedetect(unsigned char image_rgb[H * W * 3],
                 unsigned char image_gray[H * W],
                 unsigned char temp_buf[H * W],
                 unsigned char filter[K * K],
                 unsigned char output[H * W]);