#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#include <sys/time.h>
#include <sched.h>
#include <math.h>
#include "polybench.h"
/**
* This version is stamped on May 10, 2016
*
* Contact:
*   Louis-Noel Pouchet <pouchet.ohio-state.edu>
*   Tomofumi Yuki <tomofumi.yuki.fr>
*
* Web address: http://polybench.sourceforge.net
*/

/*polybench.c: this file is part of PolyBench/C*/

// Do not include <sys/resource.h>

/*By default, collect PAPI counters on thread 0.*/

/*Total LLC cache size. By default 32+MB..*/

int polybench_papi_counters_threadid = 0;
double polybench_program_total_flops = 0;
/*
* Allocation table, to enable inter-array padding. All data allocated
* with polybench_alloc_data should be freed with polybench_free_data.
*
*/

struct polybench_data_ptrs {
   void **user_view;
   void **real_ptr;
   int nb_entries;
   int nb_avail_entries;
};

static struct polybench_data_ptrs *_polybench_alloc_table = ((void *) 0);
static size_t polybench_inter_array_padding_sz = 0;
/*Timer code (gettimeofday).*/

double polybench_t_start;
double polybench_t_end;
/*Timer code (RDTSC).*/

unsigned long long polybench_c_start;
unsigned long long polybench_c_end;
static double rtclock() {
   struct timeval Tp;
   int stat;
   stat = gettimeofday(&Tp, ((void *) 0));
   if(stat != 0) printf("Error return from gettimeofday: %d", stat);
   
   return (Tp.tv_sec + Tp.tv_usec * 1.0e-6);
}

void polybench_flush_cache() {
   int cs = 32770 * 1024 / sizeof(double);
   double *flush = (double *) calloc(cs, sizeof(double));
   int i;
   double tmp = 0.0;
   //#pragma omp parallel for reduction(+:tmp) private(i)
   for(i = 0; i < cs; i++)
      tmp += flush[i];
   (void) ((!!(tmp <= 10.0)) || (_assert("tmp <= 10.0", "C:\\Users\\Tiago\\AppData\\Local\\Temp\\__clava_woven_5a76154b-7d14-4ad4-b517-70bea7dbcfd9\\polybench.c", 131) , 0));
   free(flush);
}

/*Use FIFO scheduler to limit OS interference. Program must be run
as root, and this works only for Linux kernels.*/
/*Restore to standard scheduler policy.*/
// PAPI 5.4.3 has changed the API for PAPI_perror.
//#pragma omp parallel
//#pragma omp parallel
/*! POLYBENCH_PAPI*/
void polybench_prepare_instruments() {
   polybench_flush_cache();
}

void polybench_timer_start() {
   polybench_prepare_instruments();
   polybench_t_start = rtclock();
}

void polybench_timer_stop() {
   polybench_t_end = rtclock();
}

void polybench_timer_print() {
   printf("%0.6f\n", polybench_t_end - polybench_t_start);
}

/*
* These functions are used only if the user defines a specific
* inter-array padding. It grows a global structure,
* _polybench_alloc_table, which keeps track of the data allocated via
* polybench_alloc_data (on which inter-array padding is applied), so
* that the original, non-shifted pointer can be recovered when
* calling polybench_free_data.
*
*/
/*Should never happen if the API is properly used.*/
static void * xmalloc(size_t alloc_sz) {
   void *ret = ((void *) 0);
   /*By default, post-pad the arrays. Safe behavior, but likely useless.*/
   polybench_inter_array_padding_sz += 0;
   size_t padded_sz = alloc_sz + polybench_inter_array_padding_sz;
   int err = posix_memalign(&ret, 4096, padded_sz);
   if(!ret || err) {
      fprintf((__acrt_iob_func(2)), "[PolyBench] posix_memalign: cannot allocate memory");
      exit(1);
   }
   /*Safeguard: this is invoked only if polybench.c has been compiled
   with inter-array padding support from polybench.h. If so, move
   the starting address of the allocation and return it to the
   user. The original pointer is registered in an allocation table
   internal to polybench.c. Data must then be freed using
   polybench_free_data, which will inspect the allocation table to
   free the original pointer.*/
   /*This moves the 'ret' pointer by (padded_sz - alloc_sz) positions, and
   registers it in the lookup table for future free using
   polybench_free_data.*/
   
   return ret;
}

void polybench_free_data(void *ptr) {
   free(ptr);
}

void * polybench_alloc_data(unsigned long long n, int elt_size) {
   /// FIXME: detect overflow!
   size_t val = n;
   val *= elt_size;
   void *ret = xmalloc(val);
   
   return ret;
}
