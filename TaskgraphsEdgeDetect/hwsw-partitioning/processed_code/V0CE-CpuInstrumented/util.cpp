#include <cstdio>
#include "config.h"
#include <chrono>
#include <fstream>
int checksum(int buf[262144]) {
   std::ofstream log_file_27;
   log_file_27.open("results.csv", std::ios_base::app);
   std::ofstream log_file_26;
   log_file_26.open("results.csv", std::ios_base::app);
   int n = 0;
   for(int i = 0; i < 512; i++) {
      for(int j = 0; j < 512; j++) {
         n += buf[512 * i + j];
      }
   }
   std::chrono::high_resolution_clock::time_point clava_timing_start_26 = std::chrono::high_resolution_clock::now();
   printf("Checksum %s", n == 259845 ? "SUCCESS" : "FAILURE");
   std::chrono::high_resolution_clock::time_point clava_timing_end_26 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_26 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_26 - clava_timing_start_26).count();
   log_file_26 << "printf," << clava_timing_duration_26 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_start_27 = std::chrono::high_resolution_clock::now();
   printf(" (actual: %d, expected: %d)\n", n, 259845);
   std::chrono::high_resolution_clock::time_point clava_timing_end_27 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_27 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_27 - clava_timing_start_27).count();
   log_file_27 << "printf," << clava_timing_duration_27 << "us" << "\n";
   
   return n;
}

void output_dsp(int buf[262144], char *name) {
   std::ofstream log_file_31;
   log_file_31.open("results.csv", std::ios_base::app);
   std::ofstream log_file_30;
   log_file_30.open("results.csv", std::ios_base::app);
   std::ofstream log_file_29;
   log_file_29.open("results.csv", std::ios_base::app);
   std::ofstream log_file_28;
   log_file_28.open("results.csv", std::ios_base::app);
   std::chrono::high_resolution_clock::time_point clava_timing_start_28 = std::chrono::high_resolution_clock::now();
   FILE *file = fopen(name, "w");
   std::chrono::high_resolution_clock::time_point clava_timing_end_28 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_28 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_28 - clava_timing_start_28).count();
   log_file_28 << "fopen," << clava_timing_duration_28 << "us" << "\n";
   for(int i = 0; i < 512 * 512 - 1; i++) {
      std::chrono::high_resolution_clock::time_point clava_timing_start_29 = std::chrono::high_resolution_clock::now();
      fprintf(file, "%d,", buf[i]);
      std::chrono::high_resolution_clock::time_point clava_timing_end_29 = std::chrono::high_resolution_clock::now();
      auto clava_timing_duration_29 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_29 - clava_timing_start_29).count();
      log_file_29 << "fprintf," << clava_timing_duration_29 << "us" << "\n";
   }
   std::chrono::high_resolution_clock::time_point clava_timing_start_30 = std::chrono::high_resolution_clock::now();
   fprintf(file, "%d", buf[512 * 512 - 1]);
   std::chrono::high_resolution_clock::time_point clava_timing_end_30 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_30 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_30 - clava_timing_start_30).count();
   log_file_30 << "fprintf," << clava_timing_duration_30 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_start_31 = std::chrono::high_resolution_clock::now();
   fclose(file);
   std::chrono::high_resolution_clock::time_point clava_timing_end_31 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_31 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_31 - clava_timing_start_31).count();
   log_file_31 << "fclose," << clava_timing_duration_31 << "us" << "\n";
}

void output_dsp_rgb(int buf[786432], char *name) {
   std::ofstream log_file_35;
   log_file_35.open("results.csv", std::ios_base::app);
   std::ofstream log_file_34;
   log_file_34.open("results.csv", std::ios_base::app);
   std::ofstream log_file_33;
   log_file_33.open("results.csv", std::ios_base::app);
   std::ofstream log_file_32;
   log_file_32.open("results.csv", std::ios_base::app);
   std::chrono::high_resolution_clock::time_point clava_timing_start_32 = std::chrono::high_resolution_clock::now();
   FILE *file = fopen(name, "w");
   std::chrono::high_resolution_clock::time_point clava_timing_end_32 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_32 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_32 - clava_timing_start_32).count();
   log_file_32 << "fopen," << clava_timing_duration_32 << "us" << "\n";
   for(int i = 0; i < 512 * 512 * 3 - 1; i++) {
      std::chrono::high_resolution_clock::time_point clava_timing_start_33 = std::chrono::high_resolution_clock::now();
      fprintf(file, "%d,", buf[i]);
      std::chrono::high_resolution_clock::time_point clava_timing_end_33 = std::chrono::high_resolution_clock::now();
      auto clava_timing_duration_33 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_33 - clava_timing_start_33).count();
      log_file_33 << "fprintf," << clava_timing_duration_33 << "us" << "\n";
   }
   std::chrono::high_resolution_clock::time_point clava_timing_start_34 = std::chrono::high_resolution_clock::now();
   fprintf(file, "%d", buf[512 * 512 * 3 - 1]);
   std::chrono::high_resolution_clock::time_point clava_timing_end_34 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_34 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_34 - clava_timing_start_34).count();
   log_file_34 << "fprintf," << clava_timing_duration_34 << "us" << "\n";
   std::chrono::high_resolution_clock::time_point clava_timing_start_35 = std::chrono::high_resolution_clock::now();
   fclose(file);
   std::chrono::high_resolution_clock::time_point clava_timing_end_35 = std::chrono::high_resolution_clock::now();
   auto clava_timing_duration_35 = std::chrono::duration_cast<std::chrono::microseconds>(clava_timing_end_35 - clava_timing_start_35).count();
   log_file_35 << "fclose," << clava_timing_duration_35 << "us" << "\n";
}
