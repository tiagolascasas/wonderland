#pragma once

#include "config.h"

void input_dsp(int buf[H * W * 3]);

void output_dsp(int *buf, char *name, int width, int height);

void output_dsp_rgb(int buf[H * W * 3], char *name);
