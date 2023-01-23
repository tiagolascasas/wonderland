#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <iostream>
#include "config.h"
#include "util.h"
#include <fstream>
using namespace std;
using namespace std::chrono;
void rgbToGrayscale(int input_image[786432], int output_image[262144]) {
   std::ofstream log_file_0;
   log_file_0.open("results.csv", std::ios_base::app);
   // #pragma HLS interface
   for(int i = 0; i < 512; i++) {
      int jj = 0;
      for(int j = 0; j < 512; j++) {
         #pragma HLS pipeline
         int r = input_image[i * 512 * 3 + jj];
         int g = input_image[i * 512 * 3 + jj + 1];
         int b = input_image[i * 512 * 3 + jj + 2];
         jj += 3;
         float gray = 0.299 * r + 0.587 * g + 0.114 * b;
         std::chrono::high_resolution_clock::time_point clava_timing_start_0 = std::chrono::high_resolution_clock::now();
         output_image[i * 512 + j] = (int) floor(gray);
         std::chrono::high_resolution_clock::time_point clava_timing_end_0 = std::chrono::high_resolution_clock::now();
         auto clava_timing_duration_0 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_0 - clava_timing_start_0).count();
         log_file_0 << "floor," << clava_timing_duration_0 << "us" << "\n";
      }
   }
}

void convolve2d(int input_image[262144], int filter[9], int output_image[262144]) {
   std::ofstream log_file_1;
   log_file_1.open("results.csv", std::ios_base::app);
   int i;
   int j;
   int c;
   int r;
   int normal_factor;
   int sum;
   int dead_rows;
   int dead_cols;
   dead_rows = 3 / 2;
   dead_cols = 3 / 2;
   normal_factor = 0;
   for(r = 0; r < 3; r++) {
      #pragma HLS unroll
      for(c = 0; c < 3; c++) {
         std::chrono::high_resolution_clock::time_point clava_timing_start_1 = std::chrono::high_resolution_clock::now();
         normal_factor += abs(filter[r * 3 + c]);
         std::chrono::high_resolution_clock::time_point clava_timing_end_1 = std::chrono::high_resolution_clock::now();
         auto clava_timing_duration_1 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_1 - clava_timing_start_1).count();
         log_file_1 << "abs," << clava_timing_duration_1 << "us" << "\n";
      }
   }
   if(normal_factor == 0) normal_factor = 1;
   for(r = 0; r < 512 - 3 + 1; r++) {
      for(c = 0; c < 512 - 3 + 1; c++) {
         #pragma HLS pipeline
         sum = 0;
         for(i = 0; i < 3; i++) {
            #pragma HLS unroll
            for(j = 0; j < 3; j++) {
               sum += input_image[(r + i) * 512 + (c + j)] * filter[i * 3 + j];
            }
         }
         output_image[(r + dead_rows) * 512 + (c + dead_cols)] = (sum / normal_factor);
      }
   }
}

void combthreshold(int image_gray[262144], int temp_buf[262144], int output[262144]) {
   std::ofstream log_file_3;
   log_file_3.open("results.csv", std::ios_base::app);
   std::ofstream log_file_2;
   log_file_2.open("results.csv", std::ios_base::app);
   int i, j;
   int temp1;
   int temp2;
   int temp3;
   for(i = 0; i < 512; i++) {
      for(j = 0; j < 512; ++j) {
         std::chrono::high_resolution_clock::time_point clava_timing_start_2 = std::chrono::high_resolution_clock::now();
         #pragma HLS pipeline
         temp1 = abs(image_gray[i * 512 + j]);
         std::chrono::high_resolution_clock::time_point clava_timing_end_2 = std::chrono::high_resolution_clock::now();
         auto clava_timing_duration_2 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_2 - clava_timing_start_2).count();
         log_file_2 << "abs," << clava_timing_duration_2 << "us" << "\n";
         std::chrono::high_resolution_clock::time_point clava_timing_start_3 = std::chrono::high_resolution_clock::now();
         temp2 = abs(temp_buf[i * 512 + j]);
         std::chrono::high_resolution_clock::time_point clava_timing_end_3 = std::chrono::high_resolution_clock::now();
         auto clava_timing_duration_3 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_3 - clava_timing_start_3).count();
         log_file_3 << "abs," << clava_timing_duration_3 << "us" << "\n";
         temp3 = (temp1 > temp2) ? temp1 : temp2;
         output[i * 512 + j] = (temp3 > 50) ? 255 : 0;
      }
   }
}

void set_filter_smooth(int filter[9]) {
   filter[0] = 1;
   filter[1] = 2;
   filter[2] = 1;
   filter[3] = 2;
   filter[4] = 4;
   filter[5] = 2;
   filter[6] = 1;
   filter[7] = 2;
   filter[8] = 1;
}

void set_filter_vert(int filter[9]) {
   filter[0] = 1;
   filter[1] = 0;
   filter[2] = -1;
   filter[3] = 2;
   filter[4] = 0;
   filter[5] = -2;
   filter[6] = 1;
   filter[7] = 0;
   filter[8] = -1;
}

void set_filter_horiz(int filter[9]) {
   filter[0] = 1;
   filter[1] = 2;
   filter[2] = 1;
   filter[3] = 0;
   filter[4] = 0;
   filter[5] = 0;
   filter[6] = -1;
   filter[7] = -2;
   filter[8] = -1;
}

void edge_detect(int image_rgb[786432], int image_gray[262144], int temp_buf[262144], int filter[9], int output[262144]) {
   std::ofstream log_file_11;
   log_file_11.open("results.csv", std::ios_base::app);
   std::ofstream log_file_10;
   log_file_10.open("results.csv", std::ios_base::app);
   std::ofstream log_file_9;
   log_file_9.open("results.csv", std::ios_base::app);
   std::ofstream log_file_8;
   log_file_8.open("results.csv", std::ios_base::app);
   std::ofstream log_file_7;
   log_file_7.open("results.csv", std::ios_base::app);
   std::ofstream log_file_6;
   log_file_6.open("results.csv", std::ios_base::app);
   std::ofstream log_file_5;
   log_file_5.open("results.csv", std::ios_base::app);
   std::ofstream log_file_4;
   log_file_4.open("results.csv", std::ios_base::app);
   std::chrono::high_resolution_clock::time_point clava_timing_start_4 = std::chrono::high_resolution_clock::now();
   rgbToGrayscale(image_rgb, image_gray);
   std::chrono::high_resolution_clock::time_point clava_timing_end_4 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_4 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_4 - clava_timing_start_4).count();
   log_file_4 << "rgbToGrayscale," << clava_timing_duration_4 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_start_5 = std::chrono::high_resolution_clock::now();
   set_filter_smooth(filter);
   std::chrono::high_resolution_clock::time_point clava_timing_end_5 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_5 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_5 - clava_timing_start_5).count();
   log_file_5 << "set_filter_smooth," << clava_timing_duration_5 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_start_6 = std::chrono::high_resolution_clock::now();
   convolve2d(image_gray, filter, output);
   std::chrono::high_resolution_clock::time_point clava_timing_end_6 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_6 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_6 - clava_timing_start_6).count();
   log_file_6 << "convolve2d," << clava_timing_duration_6 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_start_7 = std::chrono::high_resolution_clock::now();
   set_filter_vert(filter);
   std::chrono::high_resolution_clock::time_point clava_timing_end_7 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_7 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_7 - clava_timing_start_7).count();
   log_file_7 << "set_filter_vert," << clava_timing_duration_7 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_start_8 = std::chrono::high_resolution_clock::now();
   convolve2d(output, filter, image_gray);
   std::chrono::high_resolution_clock::time_point clava_timing_end_8 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_8 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_8 - clava_timing_start_8).count();
   log_file_8 << "convolve2d," << clava_timing_duration_8 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_start_9 = std::chrono::high_resolution_clock::now();
   set_filter_horiz(filter);
   std::chrono::high_resolution_clock::time_point clava_timing_end_9 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_9 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_9 - clava_timing_start_9).count();
   log_file_9 << "set_filter_horiz," << clava_timing_duration_9 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_start_10 = std::chrono::high_resolution_clock::now();
   convolve2d(output, filter, temp_buf);
   std::chrono::high_resolution_clock::time_point clava_timing_end_10 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_10 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_10 - clava_timing_start_10).count();
   log_file_10 << "convolve2d," << clava_timing_duration_10 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_start_11 = std::chrono::high_resolution_clock::now();
   combthreshold(image_gray, temp_buf, output);
   std::chrono::high_resolution_clock::time_point clava_timing_end_11 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_11 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_11 - clava_timing_start_11).count();
   log_file_11 << "combthreshold," << clava_timing_duration_11 << "us" << "\n";
}

int main() {
   std::ofstream log_file_26;
   log_file_26.open("results.csv", std::ios_base::app);
   std::ofstream log_file_25;
   log_file_25.open("results.csv", std::ios_base::app);
   std::ofstream log_file_24;
   log_file_24.open("results.csv", std::ios_base::app);
   std::ofstream log_file_23;
   log_file_23.open("results.csv", std::ios_base::app);
   std::ofstream log_file_22;
   log_file_22.open("results.csv", std::ios_base::app);
   std::ofstream log_file_21;
   log_file_21.open("results.csv", std::ios_base::app);
   std::ofstream log_file_20;
   log_file_20.open("results.csv", std::ios_base::app);
   std::ofstream log_file_19;
   log_file_19.open("results.csv", std::ios_base::app);
   std::ofstream log_file_18;
   log_file_18.open("results.csv", std::ios_base::app);
   std::ofstream log_file_17;
   log_file_17.open("results.csv", std::ios_base::app);
   std::ofstream log_file_16;
   log_file_16.open("results.csv", std::ios_base::app);
   std::ofstream log_file_15;
   log_file_15.open("results.csv", std::ios_base::app);
   std::ofstream log_file_14;
   log_file_14.open("results.csv", std::ios_base::app);
   std::ofstream log_file_13;
   log_file_13.open("results.csv", std::ios_base::app);
   std::ofstream log_file_12;
   log_file_12.open("results.csv", std::ios_base::app);
   int image_rgb[786432] = {
#include "img_512_512.dat"
   };
   int image_gray[262144] = {0};
   int temp_buf[262144] = {0};
   int filter[9] = {0};
   int output[262144] = {0};
   std::chrono::high_resolution_clock::time_point clava_timing_start_12 = std::chrono::high_resolution_clock::now();
   auto start = high_resolution_clock::now();
   std::chrono::high_resolution_clock::time_point clava_timing_end_12 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_12 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_12 - clava_timing_start_12).count();
   log_file_12 << "now," << clava_timing_duration_12 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_start_13 = std::chrono::high_resolution_clock::now();
   edge_detect(image_rgb, image_gray, temp_buf, filter, output);
   std::chrono::high_resolution_clock::time_point clava_timing_end_13 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_13 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_13 - clava_timing_start_13).count();
   log_file_13 << "edge_detect," << clava_timing_duration_13 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_start_14 = std::chrono::high_resolution_clock::now();
   auto stop = high_resolution_clock::now();
   std::chrono::high_resolution_clock::time_point clava_timing_end_14 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_14 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_14 - clava_timing_start_14).count();
   log_file_14 << "now," << clava_timing_duration_14 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_start_15 = std::chrono::high_resolution_clock::now();
   std::chrono::high_resolution_clock::time_point clava_timing_start_16 = std::chrono::high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stop - start);
   std::chrono::high_resolution_clock::time_point clava_timing_end_16 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_16 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_16 - clava_timing_start_16).count();
   log_file_16 << "operator-," << clava_timing_duration_16 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_end_15 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_15 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_15 - clava_timing_start_15).count();
   log_file_15 << "duration_cast," << clava_timing_duration_15 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_start_17 = std::chrono::high_resolution_clock::now();
   std::chrono::high_resolution_clock::time_point clava_timing_start_18 = std::chrono::high_resolution_clock::now();
   std::chrono::high_resolution_clock::time_point clava_timing_start_19 = std::chrono::high_resolution_clock::now();
   std::chrono::high_resolution_clock::time_point clava_timing_start_20 = std::chrono::high_resolution_clock::now();
   cout << "Duration: " << duration.count() << endl;
   std::chrono::high_resolution_clock::time_point clava_timing_end_20 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_20 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_20 - clava_timing_start_20).count();
   log_file_20 << "count," << clava_timing_duration_20 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_end_19 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_19 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_19 - clava_timing_start_19).count();
   log_file_19 << "operator<<," << clava_timing_duration_19 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_end_18 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_18 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_18 - clava_timing_start_18).count();
   log_file_18 << "operator<<," << clava_timing_duration_18 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_end_17 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_17 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_17 - clava_timing_start_17).count();
   log_file_17 << "operator<<," << clava_timing_duration_17 << "us" << "\n";
   int actual = 0;
   int real = 2455650;
   for(int i = 0; i < 262144; i++) {
      actual += output[i];
   }
   std::chrono::high_resolution_clock::time_point clava_timing_start_21 = std::chrono::high_resolution_clock::now();
   std::chrono::high_resolution_clock::time_point clava_timing_start_22 = std::chrono::high_resolution_clock::now();
   std::chrono::high_resolution_clock::time_point clava_timing_start_23 = std::chrono::high_resolution_clock::now();
   std::chrono::high_resolution_clock::time_point clava_timing_start_24 = std::chrono::high_resolution_clock::now();
   std::chrono::high_resolution_clock::time_point clava_timing_start_25 = std::chrono::high_resolution_clock::now();
   std::chrono::high_resolution_clock::time_point clava_timing_start_26 = std::chrono::high_resolution_clock::now();
   cout << "Checksum: real = " << real << ", actual = " << actual << (real == actual ? " (VERIFIED)" : " (ERROR)") << endl;
   std::chrono::high_resolution_clock::time_point clava_timing_end_26 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_26 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_26 - clava_timing_start_26).count();
   log_file_26 << "operator<<," << clava_timing_duration_26 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_end_25 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_25 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_25 - clava_timing_start_25).count();
   log_file_25 << "operator<<," << clava_timing_duration_25 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_end_24 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_24 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_24 - clava_timing_start_24).count();
   log_file_24 << "operator<<," << clava_timing_duration_24 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_end_23 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_23 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_23 - clava_timing_start_23).count();
   log_file_23 << "operator<<," << clava_timing_duration_23 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_end_22 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_22 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_22 - clava_timing_start_22).count();
   log_file_22 << "operator<<," << clava_timing_duration_22 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_end_21 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_21 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_21 - clava_timing_start_21).count();
   log_file_21 << "operator<<," << clava_timing_duration_21 << "us" << "\n";
   
   return 0;
}
