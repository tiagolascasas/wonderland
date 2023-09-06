#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// wrapc file define:
#define AUTOTB_TVIN_training_X_0 "../tv/cdatafile/c.kNN_PredictAll.autotvin_training_X_0.dat"
#define AUTOTB_TVOUT_training_X_0 "../tv/cdatafile/c.kNN_PredictAll.autotvout_training_X_0.dat"
#define AUTOTB_TVIN_training_X_1 "../tv/cdatafile/c.kNN_PredictAll.autotvin_training_X_1.dat"
#define AUTOTB_TVOUT_training_X_1 "../tv/cdatafile/c.kNN_PredictAll.autotvout_training_X_1.dat"
#define AUTOTB_TVIN_training_X_2 "../tv/cdatafile/c.kNN_PredictAll.autotvin_training_X_2.dat"
#define AUTOTB_TVOUT_training_X_2 "../tv/cdatafile/c.kNN_PredictAll.autotvout_training_X_2.dat"
#define AUTOTB_TVIN_training_X_3 "../tv/cdatafile/c.kNN_PredictAll.autotvin_training_X_3.dat"
#define AUTOTB_TVOUT_training_X_3 "../tv/cdatafile/c.kNN_PredictAll.autotvout_training_X_3.dat"
#define AUTOTB_TVIN_training_Y "../tv/cdatafile/c.kNN_PredictAll.autotvin_training_Y.dat"
#define AUTOTB_TVOUT_training_Y "../tv/cdatafile/c.kNN_PredictAll.autotvout_training_Y.dat"
#define AUTOTB_TVIN_testing_X_0 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_0.dat"
#define AUTOTB_TVOUT_testing_X_0 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_0.dat"
#define AUTOTB_TVIN_testing_X_1 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_1.dat"
#define AUTOTB_TVOUT_testing_X_1 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_1.dat"
#define AUTOTB_TVIN_testing_X_2 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_2.dat"
#define AUTOTB_TVOUT_testing_X_2 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_2.dat"
#define AUTOTB_TVIN_testing_X_3 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_3.dat"
#define AUTOTB_TVOUT_testing_X_3 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_3.dat"
#define AUTOTB_TVIN_testing_X_4 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_4.dat"
#define AUTOTB_TVOUT_testing_X_4 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_4.dat"
#define AUTOTB_TVIN_testing_X_5 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_5.dat"
#define AUTOTB_TVOUT_testing_X_5 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_5.dat"
#define AUTOTB_TVIN_testing_X_6 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_6.dat"
#define AUTOTB_TVOUT_testing_X_6 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_6.dat"
#define AUTOTB_TVIN_testing_X_7 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_7.dat"
#define AUTOTB_TVOUT_testing_X_7 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_7.dat"
#define AUTOTB_TVIN_testing_X_8 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_8.dat"
#define AUTOTB_TVOUT_testing_X_8 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_8.dat"
#define AUTOTB_TVIN_testing_X_9 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_9.dat"
#define AUTOTB_TVOUT_testing_X_9 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_9.dat"
#define AUTOTB_TVIN_testing_X_10 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_10.dat"
#define AUTOTB_TVOUT_testing_X_10 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_10.dat"
#define AUTOTB_TVIN_testing_X_11 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_11.dat"
#define AUTOTB_TVOUT_testing_X_11 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_11.dat"
#define AUTOTB_TVIN_testing_X_12 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_12.dat"
#define AUTOTB_TVOUT_testing_X_12 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_12.dat"
#define AUTOTB_TVIN_testing_X_13 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_13.dat"
#define AUTOTB_TVOUT_testing_X_13 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_13.dat"
#define AUTOTB_TVIN_testing_X_14 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_14.dat"
#define AUTOTB_TVOUT_testing_X_14 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_14.dat"
#define AUTOTB_TVIN_testing_X_15 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_15.dat"
#define AUTOTB_TVOUT_testing_X_15 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_15.dat"
#define AUTOTB_TVIN_testing_X_16 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_16.dat"
#define AUTOTB_TVOUT_testing_X_16 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_16.dat"
#define AUTOTB_TVIN_testing_X_17 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_17.dat"
#define AUTOTB_TVOUT_testing_X_17 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_17.dat"
#define AUTOTB_TVIN_testing_X_18 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_18.dat"
#define AUTOTB_TVOUT_testing_X_18 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_18.dat"
#define AUTOTB_TVIN_testing_X_19 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_19.dat"
#define AUTOTB_TVOUT_testing_X_19 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_19.dat"
#define AUTOTB_TVIN_testing_X_20 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_20.dat"
#define AUTOTB_TVOUT_testing_X_20 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_20.dat"
#define AUTOTB_TVIN_testing_X_21 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_21.dat"
#define AUTOTB_TVOUT_testing_X_21 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_21.dat"
#define AUTOTB_TVIN_testing_X_22 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_22.dat"
#define AUTOTB_TVOUT_testing_X_22 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_22.dat"
#define AUTOTB_TVIN_testing_X_23 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_23.dat"
#define AUTOTB_TVOUT_testing_X_23 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_23.dat"
#define AUTOTB_TVIN_testing_X_24 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_24.dat"
#define AUTOTB_TVOUT_testing_X_24 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_24.dat"
#define AUTOTB_TVIN_testing_X_25 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_25.dat"
#define AUTOTB_TVOUT_testing_X_25 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_25.dat"
#define AUTOTB_TVIN_testing_X_26 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_26.dat"
#define AUTOTB_TVOUT_testing_X_26 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_26.dat"
#define AUTOTB_TVIN_testing_X_27 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_27.dat"
#define AUTOTB_TVOUT_testing_X_27 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_27.dat"
#define AUTOTB_TVIN_testing_X_28 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_28.dat"
#define AUTOTB_TVOUT_testing_X_28 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_28.dat"
#define AUTOTB_TVIN_testing_X_29 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_29.dat"
#define AUTOTB_TVOUT_testing_X_29 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_29.dat"
#define AUTOTB_TVIN_testing_X_30 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_30.dat"
#define AUTOTB_TVOUT_testing_X_30 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_30.dat"
#define AUTOTB_TVIN_testing_X_31 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_31.dat"
#define AUTOTB_TVOUT_testing_X_31 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_31.dat"
#define AUTOTB_TVIN_testing_X_32 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_32.dat"
#define AUTOTB_TVOUT_testing_X_32 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_32.dat"
#define AUTOTB_TVIN_testing_X_33 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_33.dat"
#define AUTOTB_TVOUT_testing_X_33 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_33.dat"
#define AUTOTB_TVIN_testing_X_34 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_34.dat"
#define AUTOTB_TVOUT_testing_X_34 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_34.dat"
#define AUTOTB_TVIN_testing_X_35 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_35.dat"
#define AUTOTB_TVOUT_testing_X_35 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_35.dat"
#define AUTOTB_TVIN_testing_X_36 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_36.dat"
#define AUTOTB_TVOUT_testing_X_36 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_36.dat"
#define AUTOTB_TVIN_testing_X_37 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_37.dat"
#define AUTOTB_TVOUT_testing_X_37 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_37.dat"
#define AUTOTB_TVIN_testing_X_38 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_38.dat"
#define AUTOTB_TVOUT_testing_X_38 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_38.dat"
#define AUTOTB_TVIN_testing_X_39 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_39.dat"
#define AUTOTB_TVOUT_testing_X_39 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_39.dat"
#define AUTOTB_TVIN_testing_X_40 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_40.dat"
#define AUTOTB_TVOUT_testing_X_40 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_40.dat"
#define AUTOTB_TVIN_testing_X_41 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_41.dat"
#define AUTOTB_TVOUT_testing_X_41 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_41.dat"
#define AUTOTB_TVIN_testing_X_42 "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X_42.dat"
#define AUTOTB_TVOUT_testing_X_42 "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X_42.dat"
#define AUTOTB_TVIN_testing_Y "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_Y.dat"
#define AUTOTB_TVOUT_testing_Y "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_Y.dat"
#define AUTOTB_TVIN_min "../tv/cdatafile/c.kNN_PredictAll.autotvin_min.dat"
#define AUTOTB_TVOUT_min "../tv/cdatafile/c.kNN_PredictAll.autotvout_min.dat"
#define AUTOTB_TVIN_max "../tv/cdatafile/c.kNN_PredictAll.autotvin_max.dat"
#define AUTOTB_TVOUT_max "../tv/cdatafile/c.kNN_PredictAll.autotvout_max.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_training_X_0 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_training_X_0.dat"
#define AUTOTB_TVOUT_PC_training_X_1 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_training_X_1.dat"
#define AUTOTB_TVOUT_PC_training_X_2 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_training_X_2.dat"
#define AUTOTB_TVOUT_PC_training_X_3 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_training_X_3.dat"
#define AUTOTB_TVOUT_PC_training_Y "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_training_Y.dat"
#define AUTOTB_TVOUT_PC_testing_X_0 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_0.dat"
#define AUTOTB_TVOUT_PC_testing_X_1 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_1.dat"
#define AUTOTB_TVOUT_PC_testing_X_2 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_2.dat"
#define AUTOTB_TVOUT_PC_testing_X_3 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_3.dat"
#define AUTOTB_TVOUT_PC_testing_X_4 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_4.dat"
#define AUTOTB_TVOUT_PC_testing_X_5 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_5.dat"
#define AUTOTB_TVOUT_PC_testing_X_6 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_6.dat"
#define AUTOTB_TVOUT_PC_testing_X_7 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_7.dat"
#define AUTOTB_TVOUT_PC_testing_X_8 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_8.dat"
#define AUTOTB_TVOUT_PC_testing_X_9 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_9.dat"
#define AUTOTB_TVOUT_PC_testing_X_10 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_10.dat"
#define AUTOTB_TVOUT_PC_testing_X_11 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_11.dat"
#define AUTOTB_TVOUT_PC_testing_X_12 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_12.dat"
#define AUTOTB_TVOUT_PC_testing_X_13 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_13.dat"
#define AUTOTB_TVOUT_PC_testing_X_14 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_14.dat"
#define AUTOTB_TVOUT_PC_testing_X_15 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_15.dat"
#define AUTOTB_TVOUT_PC_testing_X_16 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_16.dat"
#define AUTOTB_TVOUT_PC_testing_X_17 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_17.dat"
#define AUTOTB_TVOUT_PC_testing_X_18 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_18.dat"
#define AUTOTB_TVOUT_PC_testing_X_19 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_19.dat"
#define AUTOTB_TVOUT_PC_testing_X_20 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_20.dat"
#define AUTOTB_TVOUT_PC_testing_X_21 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_21.dat"
#define AUTOTB_TVOUT_PC_testing_X_22 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_22.dat"
#define AUTOTB_TVOUT_PC_testing_X_23 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_23.dat"
#define AUTOTB_TVOUT_PC_testing_X_24 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_24.dat"
#define AUTOTB_TVOUT_PC_testing_X_25 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_25.dat"
#define AUTOTB_TVOUT_PC_testing_X_26 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_26.dat"
#define AUTOTB_TVOUT_PC_testing_X_27 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_27.dat"
#define AUTOTB_TVOUT_PC_testing_X_28 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_28.dat"
#define AUTOTB_TVOUT_PC_testing_X_29 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_29.dat"
#define AUTOTB_TVOUT_PC_testing_X_30 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_30.dat"
#define AUTOTB_TVOUT_PC_testing_X_31 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_31.dat"
#define AUTOTB_TVOUT_PC_testing_X_32 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_32.dat"
#define AUTOTB_TVOUT_PC_testing_X_33 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_33.dat"
#define AUTOTB_TVOUT_PC_testing_X_34 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_34.dat"
#define AUTOTB_TVOUT_PC_testing_X_35 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_35.dat"
#define AUTOTB_TVOUT_PC_testing_X_36 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_36.dat"
#define AUTOTB_TVOUT_PC_testing_X_37 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_37.dat"
#define AUTOTB_TVOUT_PC_testing_X_38 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_38.dat"
#define AUTOTB_TVOUT_PC_testing_X_39 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_39.dat"
#define AUTOTB_TVOUT_PC_testing_X_40 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_40.dat"
#define AUTOTB_TVOUT_PC_testing_X_41 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_41.dat"
#define AUTOTB_TVOUT_PC_testing_X_42 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X_42.dat"
#define AUTOTB_TVOUT_PC_testing_Y "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_Y.dat"
#define AUTOTB_TVOUT_PC_min "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_min.dat"
#define AUTOTB_TVOUT_PC_max "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_max.dat"


static const bool little_endian()
{
  int a = 1;
  return *(char*)&a == 1;
}

inline static void rev_endian(char* p, size_t nbytes)
{
  std::reverse(p, p+nbytes);
}

template<size_t bit_width>
struct transaction {
  typedef uint64_t depth_t;
  static const size_t wbytes = (bit_width+7)>>3;
  static const size_t dbytes = sizeof(depth_t);
  const depth_t depth;
  const size_t vbytes;
  const size_t tbytes;
  char * const p;
  typedef char (*p_dat)[wbytes];
  p_dat vp;

  transaction(depth_t depth)
    : depth(depth), vbytes(wbytes*depth), tbytes(dbytes+vbytes),
      p(new char[tbytes]) {
    *(depth_t*)p = depth;
    rev_endian(p, dbytes);
    vp = (p_dat) (p+dbytes);
  }

  void reorder() {
    rev_endian(p, dbytes);
    p_dat vp = (p_dat) (p+dbytes);
    for (depth_t i = 0; i < depth; ++i) {
      rev_endian(vp[i], wbytes);
    }
  }

  template<size_t psize>
  void import(char* param, depth_t num, int64_t offset) {
    param -= offset*psize;
    for (depth_t i = 0; i < num; ++i) {
      memcpy(vp[i], param, wbytes);
      param += psize;
      if (little_endian()) {
        rev_endian(vp[i], wbytes);
      }
    }
    vp += num;
  }

  template<size_t psize>
  void send(char* param, depth_t num) {
    for (depth_t i = 0; i < num; ++i) {
      memcpy(param, vp[i], wbytes);
      param += psize;
    }
    vp += num;
  }

  template<size_t psize>
  void send(char* param, depth_t num, int64_t skip) {
    for (depth_t i = 0; i < num; ++i) {
      memcpy(param, vp[skip+i], wbytes);
      param += psize;
    }
  }

  ~transaction() { if (p) { delete[] p; } }
};


inline static const std::string begin_str(int num)
{
  return std::string("[[transaction]]           ")
         .append(std::to_string(num))
         .append("\n");
}

inline static const std::string end_str()
{
  return std::string("[[/transaction]]\n");
}

const std::string formatData(unsigned char *pos, size_t wbits)
{
  bool LE = little_endian();
  size_t wbytes = (wbits+7)>>3;
  size_t i = LE ? wbytes-1 : 0;
  auto next = [&] () {
    auto c = pos[i];
    LE ? --i : ++i;
    return c;
  };
  std::ostringstream ss;
  ss << "0x";
  if (int t = (wbits & 0x7)) {
    if (t <= 4) {
      unsigned char mask = (1<<t)-1;
      ss << std::hex << std::setfill('0') << std::setw(1)
         << (int) (next() & mask);
      wbytes -= 1;
    }
  }
  for (size_t i = 0; i < wbytes; ++i) {
    ss << std::hex << std::setfill('0') << std::setw(2) << (int)next();
  }
  ss.put('\n');
  return ss.str();
}

static bool RTLOutputCheckAndReplacement(std::string &data)
{
  bool changed = false;
  for (size_t i = 2; i < data.size(); ++i) {
    if (data[i] == 'X' || data[i] == 'x') {
      data[i] = '0';
      changed = true;
    }
  }
  return changed;
}

struct SimException : public std::exception {
  const char *msg;
  const size_t line;
  SimException(const char *msg, const size_t line)
    : msg(msg), line(line)
  {
  }
};

template<size_t bit_width>
class PostCheck
{
  static const char *bad;
  static const char *err;
  std::fstream stream;
  std::string s;

  void send(char *p, ap_uint<bit_width> &data, size_t l, size_t rest)
  {
    if (rest == 0) {
      if (!little_endian()) {
        const size_t wbytes = (bit_width+7)>>3;
        rev_endian(p-wbytes, wbytes);
      }
    } else if (rest < 8) {
      *p = data.range(l+rest-1, l).to_uint();
      send(p+1, data, l+rest, 0);
    } else {
      *p = data.range(l+8-1, l).to_uint();
      send(p+1, data, l+8, rest-8);
    }
  }

  void readline()
  {
    std::getline(stream, s);
    if (stream.eof()) {
      throw SimException(bad, __LINE__);
    }
  }

public:
  char *param;
  size_t psize;
  size_t depth;

  PostCheck(const char *file)
  {
    stream.open(file);
    if (stream.fail()) {
      throw SimException(err, __LINE__);
    } else {
      readline();
      if (s != "[[[runtime]]]") {
        throw SimException(bad, __LINE__);
      }
    }
  }

  ~PostCheck() noexcept(false)
  {
    stream.close();
  }

  void run(size_t AESL_transaction_pc, size_t skip)
  {
    if (stream.peek() == '[') {
      readline();
    }

    for (size_t i = 0; i < skip; ++i) {
      readline();
    }

    bool foundX = false;
    for (size_t i = 0; i < depth; ++i) {
      readline();
      foundX |= RTLOutputCheckAndReplacement(s);
      ap_uint<bit_width> data(s.c_str(), 16);
      send(param+i*psize, data, 0, bit_width);
    }
    if (foundX) {
      std::cerr << "WARNING: [SIM 212-201] RTL produces unknown value "
                << "'x' or 'X' on some port, possible cause: "
                << "There are uninitialized variables in the design.\n";
    }

    if (stream.peek() == '[') {
      readline();
    }
  }
};

template<size_t bit_width>
const char* PostCheck<bit_width>::bad = "Bad TV file";

template<size_t bit_width>
const char* PostCheck<bit_width>::err = "Error on TV file";
      
class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  training_X_0_depth = 0;
  training_X_1_depth = 0;
  training_X_2_depth = 0;
  training_X_3_depth = 0;
  training_Y_depth = 0;
  testing_X_0_depth = 0;
  testing_X_1_depth = 0;
  testing_X_2_depth = 0;
  testing_X_3_depth = 0;
  testing_X_4_depth = 0;
  testing_X_5_depth = 0;
  testing_X_6_depth = 0;
  testing_X_7_depth = 0;
  testing_X_8_depth = 0;
  testing_X_9_depth = 0;
  testing_X_10_depth = 0;
  testing_X_11_depth = 0;
  testing_X_12_depth = 0;
  testing_X_13_depth = 0;
  testing_X_14_depth = 0;
  testing_X_15_depth = 0;
  testing_X_16_depth = 0;
  testing_X_17_depth = 0;
  testing_X_18_depth = 0;
  testing_X_19_depth = 0;
  testing_X_20_depth = 0;
  testing_X_21_depth = 0;
  testing_X_22_depth = 0;
  testing_X_23_depth = 0;
  testing_X_24_depth = 0;
  testing_X_25_depth = 0;
  testing_X_26_depth = 0;
  testing_X_27_depth = 0;
  testing_X_28_depth = 0;
  testing_X_29_depth = 0;
  testing_X_30_depth = 0;
  testing_X_31_depth = 0;
  testing_X_32_depth = 0;
  testing_X_33_depth = 0;
  testing_X_34_depth = 0;
  testing_X_35_depth = 0;
  testing_X_36_depth = 0;
  testing_X_37_depth = 0;
  testing_X_38_depth = 0;
  testing_X_39_depth = 0;
  testing_X_40_depth = 0;
  testing_X_41_depth = 0;
  testing_X_42_depth = 0;
  testing_Y_depth = 0;
  min_depth = 0;
  max_depth = 0;
  trans_num =0;
}
~INTER_TCL_FILE() {
  mFile.open(mName);
  if (!mFile.good()) {
    cout << "Failed to open file ref.tcl" << endl;
    exit (1); 
  }
  string total_list = get_depth_list();
  mFile << "set depth_list {\n";
  mFile << total_list;
  mFile << "}\n";
  mFile << "set trans_num "<<trans_num<<endl;
  mFile.close();
}
string get_depth_list () {
  stringstream total_list;
  total_list << "{training_X_0 " << training_X_0_depth << "}\n";
  total_list << "{training_X_1 " << training_X_1_depth << "}\n";
  total_list << "{training_X_2 " << training_X_2_depth << "}\n";
  total_list << "{training_X_3 " << training_X_3_depth << "}\n";
  total_list << "{training_Y " << training_Y_depth << "}\n";
  total_list << "{testing_X_0 " << testing_X_0_depth << "}\n";
  total_list << "{testing_X_1 " << testing_X_1_depth << "}\n";
  total_list << "{testing_X_2 " << testing_X_2_depth << "}\n";
  total_list << "{testing_X_3 " << testing_X_3_depth << "}\n";
  total_list << "{testing_X_4 " << testing_X_4_depth << "}\n";
  total_list << "{testing_X_5 " << testing_X_5_depth << "}\n";
  total_list << "{testing_X_6 " << testing_X_6_depth << "}\n";
  total_list << "{testing_X_7 " << testing_X_7_depth << "}\n";
  total_list << "{testing_X_8 " << testing_X_8_depth << "}\n";
  total_list << "{testing_X_9 " << testing_X_9_depth << "}\n";
  total_list << "{testing_X_10 " << testing_X_10_depth << "}\n";
  total_list << "{testing_X_11 " << testing_X_11_depth << "}\n";
  total_list << "{testing_X_12 " << testing_X_12_depth << "}\n";
  total_list << "{testing_X_13 " << testing_X_13_depth << "}\n";
  total_list << "{testing_X_14 " << testing_X_14_depth << "}\n";
  total_list << "{testing_X_15 " << testing_X_15_depth << "}\n";
  total_list << "{testing_X_16 " << testing_X_16_depth << "}\n";
  total_list << "{testing_X_17 " << testing_X_17_depth << "}\n";
  total_list << "{testing_X_18 " << testing_X_18_depth << "}\n";
  total_list << "{testing_X_19 " << testing_X_19_depth << "}\n";
  total_list << "{testing_X_20 " << testing_X_20_depth << "}\n";
  total_list << "{testing_X_21 " << testing_X_21_depth << "}\n";
  total_list << "{testing_X_22 " << testing_X_22_depth << "}\n";
  total_list << "{testing_X_23 " << testing_X_23_depth << "}\n";
  total_list << "{testing_X_24 " << testing_X_24_depth << "}\n";
  total_list << "{testing_X_25 " << testing_X_25_depth << "}\n";
  total_list << "{testing_X_26 " << testing_X_26_depth << "}\n";
  total_list << "{testing_X_27 " << testing_X_27_depth << "}\n";
  total_list << "{testing_X_28 " << testing_X_28_depth << "}\n";
  total_list << "{testing_X_29 " << testing_X_29_depth << "}\n";
  total_list << "{testing_X_30 " << testing_X_30_depth << "}\n";
  total_list << "{testing_X_31 " << testing_X_31_depth << "}\n";
  total_list << "{testing_X_32 " << testing_X_32_depth << "}\n";
  total_list << "{testing_X_33 " << testing_X_33_depth << "}\n";
  total_list << "{testing_X_34 " << testing_X_34_depth << "}\n";
  total_list << "{testing_X_35 " << testing_X_35_depth << "}\n";
  total_list << "{testing_X_36 " << testing_X_36_depth << "}\n";
  total_list << "{testing_X_37 " << testing_X_37_depth << "}\n";
  total_list << "{testing_X_38 " << testing_X_38_depth << "}\n";
  total_list << "{testing_X_39 " << testing_X_39_depth << "}\n";
  total_list << "{testing_X_40 " << testing_X_40_depth << "}\n";
  total_list << "{testing_X_41 " << testing_X_41_depth << "}\n";
  total_list << "{testing_X_42 " << testing_X_42_depth << "}\n";
  total_list << "{testing_Y " << testing_Y_depth << "}\n";
  total_list << "{min " << min_depth << "}\n";
  total_list << "{max " << max_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int training_X_0_depth;
    int training_X_1_depth;
    int training_X_2_depth;
    int training_X_3_depth;
    int training_Y_depth;
    int testing_X_0_depth;
    int testing_X_1_depth;
    int testing_X_2_depth;
    int testing_X_3_depth;
    int testing_X_4_depth;
    int testing_X_5_depth;
    int testing_X_6_depth;
    int testing_X_7_depth;
    int testing_X_8_depth;
    int testing_X_9_depth;
    int testing_X_10_depth;
    int testing_X_11_depth;
    int testing_X_12_depth;
    int testing_X_13_depth;
    int testing_X_14_depth;
    int testing_X_15_depth;
    int testing_X_16_depth;
    int testing_X_17_depth;
    int testing_X_18_depth;
    int testing_X_19_depth;
    int testing_X_20_depth;
    int testing_X_21_depth;
    int testing_X_22_depth;
    int testing_X_23_depth;
    int testing_X_24_depth;
    int testing_X_25_depth;
    int testing_X_26_depth;
    int testing_X_27_depth;
    int testing_X_28_depth;
    int testing_X_29_depth;
    int testing_X_30_depth;
    int testing_X_31_depth;
    int testing_X_32_depth;
    int testing_X_33_depth;
    int testing_X_34_depth;
    int testing_X_35_depth;
    int testing_X_36_depth;
    int testing_X_37_depth;
    int testing_X_38_depth;
    int testing_X_39_depth;
    int testing_X_40_depth;
    int testing_X_41_depth;
    int testing_X_42_depth;
    int testing_Y_depth;
    int min_depth;
    int max_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};


extern "C" void kNN_PredictAll_hw_stub_wrapper(volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *);

extern "C" void apatb_kNN_PredictAll_hw(volatile void * __xlx_apatb_param_training_X_0, volatile void * __xlx_apatb_param_training_X_1, volatile void * __xlx_apatb_param_training_X_2, volatile void * __xlx_apatb_param_training_X_3, volatile void * __xlx_apatb_param_training_Y, volatile void * __xlx_apatb_param_testing_X_0, volatile void * __xlx_apatb_param_testing_X_1, volatile void * __xlx_apatb_param_testing_X_2, volatile void * __xlx_apatb_param_testing_X_3, volatile void * __xlx_apatb_param_testing_X_4, volatile void * __xlx_apatb_param_testing_X_5, volatile void * __xlx_apatb_param_testing_X_6, volatile void * __xlx_apatb_param_testing_X_7, volatile void * __xlx_apatb_param_testing_X_8, volatile void * __xlx_apatb_param_testing_X_9, volatile void * __xlx_apatb_param_testing_X_10, volatile void * __xlx_apatb_param_testing_X_11, volatile void * __xlx_apatb_param_testing_X_12, volatile void * __xlx_apatb_param_testing_X_13, volatile void * __xlx_apatb_param_testing_X_14, volatile void * __xlx_apatb_param_testing_X_15, volatile void * __xlx_apatb_param_testing_X_16, volatile void * __xlx_apatb_param_testing_X_17, volatile void * __xlx_apatb_param_testing_X_18, volatile void * __xlx_apatb_param_testing_X_19, volatile void * __xlx_apatb_param_testing_X_20, volatile void * __xlx_apatb_param_testing_X_21, volatile void * __xlx_apatb_param_testing_X_22, volatile void * __xlx_apatb_param_testing_X_23, volatile void * __xlx_apatb_param_testing_X_24, volatile void * __xlx_apatb_param_testing_X_25, volatile void * __xlx_apatb_param_testing_X_26, volatile void * __xlx_apatb_param_testing_X_27, volatile void * __xlx_apatb_param_testing_X_28, volatile void * __xlx_apatb_param_testing_X_29, volatile void * __xlx_apatb_param_testing_X_30, volatile void * __xlx_apatb_param_testing_X_31, volatile void * __xlx_apatb_param_testing_X_32, volatile void * __xlx_apatb_param_testing_X_33, volatile void * __xlx_apatb_param_testing_X_34, volatile void * __xlx_apatb_param_testing_X_35, volatile void * __xlx_apatb_param_testing_X_36, volatile void * __xlx_apatb_param_testing_X_37, volatile void * __xlx_apatb_param_testing_X_38, volatile void * __xlx_apatb_param_testing_X_39, volatile void * __xlx_apatb_param_testing_X_40, volatile void * __xlx_apatb_param_testing_X_41, volatile void * __xlx_apatb_param_testing_X_42, volatile void * __xlx_apatb_param_testing_Y, volatile void * __xlx_apatb_param_min, volatile void * __xlx_apatb_param_max) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
static AESL_FILE_HANDLER aesl_fh;
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_0, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_0, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_0);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_0_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_0_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_0" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_0)[j*8+0] = testing_X_0_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_0)[j*8+1] = testing_X_0_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_0)[j*8+2] = testing_X_0_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_0)[j*8+3] = testing_X_0_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_0)[j*8+4] = testing_X_0_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_0)[j*8+5] = testing_X_0_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_0)[j*8+6] = testing_X_0_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_0)[j*8+7] = testing_X_0_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_1, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_1, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_1);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_1_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_1_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_1" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_1)[j*8+0] = testing_X_1_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_1)[j*8+1] = testing_X_1_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_1)[j*8+2] = testing_X_1_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_1)[j*8+3] = testing_X_1_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_1)[j*8+4] = testing_X_1_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_1)[j*8+5] = testing_X_1_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_1)[j*8+6] = testing_X_1_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_1)[j*8+7] = testing_X_1_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_2, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_2, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_2);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_2_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_2_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_2" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_2)[j*8+0] = testing_X_2_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_2)[j*8+1] = testing_X_2_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_2)[j*8+2] = testing_X_2_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_2)[j*8+3] = testing_X_2_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_2)[j*8+4] = testing_X_2_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_2)[j*8+5] = testing_X_2_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_2)[j*8+6] = testing_X_2_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_2)[j*8+7] = testing_X_2_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_3, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_3, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_3);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_3_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_3_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_3" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_3)[j*8+0] = testing_X_3_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_3)[j*8+1] = testing_X_3_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_3)[j*8+2] = testing_X_3_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_3)[j*8+3] = testing_X_3_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_3)[j*8+4] = testing_X_3_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_3)[j*8+5] = testing_X_3_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_3)[j*8+6] = testing_X_3_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_3)[j*8+7] = testing_X_3_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_4, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_4, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_4);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_4_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_4_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_4" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_4)[j*8+0] = testing_X_4_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_4)[j*8+1] = testing_X_4_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_4)[j*8+2] = testing_X_4_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_4)[j*8+3] = testing_X_4_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_4)[j*8+4] = testing_X_4_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_4)[j*8+5] = testing_X_4_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_4)[j*8+6] = testing_X_4_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_4)[j*8+7] = testing_X_4_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_5, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_5, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_5);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_5_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_5_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_5" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_5)[j*8+0] = testing_X_5_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_5)[j*8+1] = testing_X_5_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_5)[j*8+2] = testing_X_5_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_5)[j*8+3] = testing_X_5_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_5)[j*8+4] = testing_X_5_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_5)[j*8+5] = testing_X_5_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_5)[j*8+6] = testing_X_5_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_5)[j*8+7] = testing_X_5_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_6, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_6, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_6);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_6_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_6_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_6" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_6)[j*8+0] = testing_X_6_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_6)[j*8+1] = testing_X_6_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_6)[j*8+2] = testing_X_6_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_6)[j*8+3] = testing_X_6_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_6)[j*8+4] = testing_X_6_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_6)[j*8+5] = testing_X_6_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_6)[j*8+6] = testing_X_6_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_6)[j*8+7] = testing_X_6_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_7, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_7, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_7);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_7_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_7_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_7" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_7)[j*8+0] = testing_X_7_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_7)[j*8+1] = testing_X_7_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_7)[j*8+2] = testing_X_7_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_7)[j*8+3] = testing_X_7_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_7)[j*8+4] = testing_X_7_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_7)[j*8+5] = testing_X_7_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_7)[j*8+6] = testing_X_7_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_7)[j*8+7] = testing_X_7_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_8, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_8, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_8);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_8_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_8_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_8" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_8)[j*8+0] = testing_X_8_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_8)[j*8+1] = testing_X_8_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_8)[j*8+2] = testing_X_8_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_8)[j*8+3] = testing_X_8_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_8)[j*8+4] = testing_X_8_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_8)[j*8+5] = testing_X_8_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_8)[j*8+6] = testing_X_8_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_8)[j*8+7] = testing_X_8_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_9, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_9, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_9);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_9_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_9_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_9" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_9)[j*8+0] = testing_X_9_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_9)[j*8+1] = testing_X_9_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_9)[j*8+2] = testing_X_9_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_9)[j*8+3] = testing_X_9_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_9)[j*8+4] = testing_X_9_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_9)[j*8+5] = testing_X_9_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_9)[j*8+6] = testing_X_9_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_9)[j*8+7] = testing_X_9_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_10, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_10, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_10);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_10_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_10_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_10" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_10)[j*8+0] = testing_X_10_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_10)[j*8+1] = testing_X_10_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_10)[j*8+2] = testing_X_10_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_10)[j*8+3] = testing_X_10_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_10)[j*8+4] = testing_X_10_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_10)[j*8+5] = testing_X_10_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_10)[j*8+6] = testing_X_10_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_10)[j*8+7] = testing_X_10_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_11, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_11, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_11);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_11_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_11_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_11" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_11)[j*8+0] = testing_X_11_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_11)[j*8+1] = testing_X_11_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_11)[j*8+2] = testing_X_11_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_11)[j*8+3] = testing_X_11_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_11)[j*8+4] = testing_X_11_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_11)[j*8+5] = testing_X_11_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_11)[j*8+6] = testing_X_11_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_11)[j*8+7] = testing_X_11_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_12, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_12, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_12);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_12_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_12_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_12" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_12)[j*8+0] = testing_X_12_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_12)[j*8+1] = testing_X_12_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_12)[j*8+2] = testing_X_12_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_12)[j*8+3] = testing_X_12_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_12)[j*8+4] = testing_X_12_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_12)[j*8+5] = testing_X_12_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_12)[j*8+6] = testing_X_12_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_12)[j*8+7] = testing_X_12_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_13, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_13, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_13);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_13_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_13_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_13" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_13)[j*8+0] = testing_X_13_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_13)[j*8+1] = testing_X_13_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_13)[j*8+2] = testing_X_13_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_13)[j*8+3] = testing_X_13_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_13)[j*8+4] = testing_X_13_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_13)[j*8+5] = testing_X_13_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_13)[j*8+6] = testing_X_13_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_13)[j*8+7] = testing_X_13_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_14, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_14, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_14);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_14_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_14_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_14" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_14)[j*8+0] = testing_X_14_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_14)[j*8+1] = testing_X_14_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_14)[j*8+2] = testing_X_14_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_14)[j*8+3] = testing_X_14_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_14)[j*8+4] = testing_X_14_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_14)[j*8+5] = testing_X_14_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_14)[j*8+6] = testing_X_14_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_14)[j*8+7] = testing_X_14_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_15, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_15, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_15);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_15_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_15_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_15" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_15)[j*8+0] = testing_X_15_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_15)[j*8+1] = testing_X_15_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_15)[j*8+2] = testing_X_15_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_15)[j*8+3] = testing_X_15_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_15)[j*8+4] = testing_X_15_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_15)[j*8+5] = testing_X_15_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_15)[j*8+6] = testing_X_15_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_15)[j*8+7] = testing_X_15_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_16, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_16, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_16);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_16_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_16_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_16" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_16)[j*8+0] = testing_X_16_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_16)[j*8+1] = testing_X_16_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_16)[j*8+2] = testing_X_16_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_16)[j*8+3] = testing_X_16_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_16)[j*8+4] = testing_X_16_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_16)[j*8+5] = testing_X_16_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_16)[j*8+6] = testing_X_16_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_16)[j*8+7] = testing_X_16_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_17, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_17, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_17);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_17_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_17_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_17" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_17)[j*8+0] = testing_X_17_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_17)[j*8+1] = testing_X_17_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_17)[j*8+2] = testing_X_17_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_17)[j*8+3] = testing_X_17_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_17)[j*8+4] = testing_X_17_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_17)[j*8+5] = testing_X_17_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_17)[j*8+6] = testing_X_17_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_17)[j*8+7] = testing_X_17_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_18, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_18, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_18);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_18_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_18_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_18" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_18)[j*8+0] = testing_X_18_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_18)[j*8+1] = testing_X_18_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_18)[j*8+2] = testing_X_18_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_18)[j*8+3] = testing_X_18_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_18)[j*8+4] = testing_X_18_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_18)[j*8+5] = testing_X_18_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_18)[j*8+6] = testing_X_18_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_18)[j*8+7] = testing_X_18_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_19, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_19, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_19);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_19_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_19_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_19" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_19)[j*8+0] = testing_X_19_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_19)[j*8+1] = testing_X_19_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_19)[j*8+2] = testing_X_19_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_19)[j*8+3] = testing_X_19_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_19)[j*8+4] = testing_X_19_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_19)[j*8+5] = testing_X_19_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_19)[j*8+6] = testing_X_19_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_19)[j*8+7] = testing_X_19_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_20, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_20, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_20);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_20_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_20_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_20" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_20)[j*8+0] = testing_X_20_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_20)[j*8+1] = testing_X_20_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_20)[j*8+2] = testing_X_20_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_20)[j*8+3] = testing_X_20_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_20)[j*8+4] = testing_X_20_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_20)[j*8+5] = testing_X_20_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_20)[j*8+6] = testing_X_20_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_20)[j*8+7] = testing_X_20_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_21, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_21, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_21);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_21_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_21_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_21" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_21)[j*8+0] = testing_X_21_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_21)[j*8+1] = testing_X_21_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_21)[j*8+2] = testing_X_21_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_21)[j*8+3] = testing_X_21_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_21)[j*8+4] = testing_X_21_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_21)[j*8+5] = testing_X_21_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_21)[j*8+6] = testing_X_21_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_21)[j*8+7] = testing_X_21_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_22, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_22, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_22);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_22_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_22_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_22" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_22)[j*8+0] = testing_X_22_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_22)[j*8+1] = testing_X_22_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_22)[j*8+2] = testing_X_22_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_22)[j*8+3] = testing_X_22_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_22)[j*8+4] = testing_X_22_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_22)[j*8+5] = testing_X_22_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_22)[j*8+6] = testing_X_22_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_22)[j*8+7] = testing_X_22_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_23, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_23, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_23);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_23_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_23_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_23" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_23)[j*8+0] = testing_X_23_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_23)[j*8+1] = testing_X_23_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_23)[j*8+2] = testing_X_23_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_23)[j*8+3] = testing_X_23_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_23)[j*8+4] = testing_X_23_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_23)[j*8+5] = testing_X_23_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_23)[j*8+6] = testing_X_23_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_23)[j*8+7] = testing_X_23_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_24, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_24, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_24);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_24_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_24_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_24" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_24)[j*8+0] = testing_X_24_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_24)[j*8+1] = testing_X_24_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_24)[j*8+2] = testing_X_24_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_24)[j*8+3] = testing_X_24_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_24)[j*8+4] = testing_X_24_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_24)[j*8+5] = testing_X_24_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_24)[j*8+6] = testing_X_24_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_24)[j*8+7] = testing_X_24_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_25, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_25, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_25);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_25_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_25_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_25" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_25)[j*8+0] = testing_X_25_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_25)[j*8+1] = testing_X_25_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_25)[j*8+2] = testing_X_25_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_25)[j*8+3] = testing_X_25_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_25)[j*8+4] = testing_X_25_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_25)[j*8+5] = testing_X_25_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_25)[j*8+6] = testing_X_25_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_25)[j*8+7] = testing_X_25_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_26, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_26, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_26);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_26_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_26_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_26" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_26)[j*8+0] = testing_X_26_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_26)[j*8+1] = testing_X_26_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_26)[j*8+2] = testing_X_26_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_26)[j*8+3] = testing_X_26_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_26)[j*8+4] = testing_X_26_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_26)[j*8+5] = testing_X_26_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_26)[j*8+6] = testing_X_26_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_26)[j*8+7] = testing_X_26_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_27, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_27, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_27);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_27_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_27_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_27" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_27)[j*8+0] = testing_X_27_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_27)[j*8+1] = testing_X_27_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_27)[j*8+2] = testing_X_27_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_27)[j*8+3] = testing_X_27_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_27)[j*8+4] = testing_X_27_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_27)[j*8+5] = testing_X_27_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_27)[j*8+6] = testing_X_27_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_27)[j*8+7] = testing_X_27_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_28, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_28, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_28);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_28_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_28_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_28" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_28)[j*8+0] = testing_X_28_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_28)[j*8+1] = testing_X_28_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_28)[j*8+2] = testing_X_28_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_28)[j*8+3] = testing_X_28_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_28)[j*8+4] = testing_X_28_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_28)[j*8+5] = testing_X_28_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_28)[j*8+6] = testing_X_28_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_28)[j*8+7] = testing_X_28_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_29, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_29, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_29);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_29_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_29_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_29" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_29)[j*8+0] = testing_X_29_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_29)[j*8+1] = testing_X_29_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_29)[j*8+2] = testing_X_29_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_29)[j*8+3] = testing_X_29_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_29)[j*8+4] = testing_X_29_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_29)[j*8+5] = testing_X_29_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_29)[j*8+6] = testing_X_29_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_29)[j*8+7] = testing_X_29_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_30, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_30, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_30);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_30_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_30_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_30" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_30)[j*8+0] = testing_X_30_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_30)[j*8+1] = testing_X_30_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_30)[j*8+2] = testing_X_30_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_30)[j*8+3] = testing_X_30_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_30)[j*8+4] = testing_X_30_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_30)[j*8+5] = testing_X_30_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_30)[j*8+6] = testing_X_30_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_30)[j*8+7] = testing_X_30_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_31, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_31, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_31);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_31_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_31_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_31" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_31)[j*8+0] = testing_X_31_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_31)[j*8+1] = testing_X_31_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_31)[j*8+2] = testing_X_31_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_31)[j*8+3] = testing_X_31_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_31)[j*8+4] = testing_X_31_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_31)[j*8+5] = testing_X_31_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_31)[j*8+6] = testing_X_31_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_31)[j*8+7] = testing_X_31_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_32, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_32, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_32);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_32_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_32_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_32" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_32)[j*8+0] = testing_X_32_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_32)[j*8+1] = testing_X_32_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_32)[j*8+2] = testing_X_32_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_32)[j*8+3] = testing_X_32_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_32)[j*8+4] = testing_X_32_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_32)[j*8+5] = testing_X_32_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_32)[j*8+6] = testing_X_32_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_32)[j*8+7] = testing_X_32_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_33, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_33, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_33);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_33_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_33_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_33" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_33)[j*8+0] = testing_X_33_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_33)[j*8+1] = testing_X_33_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_33)[j*8+2] = testing_X_33_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_33)[j*8+3] = testing_X_33_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_33)[j*8+4] = testing_X_33_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_33)[j*8+5] = testing_X_33_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_33)[j*8+6] = testing_X_33_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_33)[j*8+7] = testing_X_33_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_34, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_34, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_34);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_34_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_34_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_34" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_34)[j*8+0] = testing_X_34_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_34)[j*8+1] = testing_X_34_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_34)[j*8+2] = testing_X_34_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_34)[j*8+3] = testing_X_34_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_34)[j*8+4] = testing_X_34_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_34)[j*8+5] = testing_X_34_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_34)[j*8+6] = testing_X_34_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_34)[j*8+7] = testing_X_34_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_35, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_35, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_35);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_35_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_35_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_35" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_35)[j*8+0] = testing_X_35_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_35)[j*8+1] = testing_X_35_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_35)[j*8+2] = testing_X_35_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_35)[j*8+3] = testing_X_35_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_35)[j*8+4] = testing_X_35_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_35)[j*8+5] = testing_X_35_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_35)[j*8+6] = testing_X_35_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_35)[j*8+7] = testing_X_35_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_36, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_36, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_36);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_36_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_36_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_36" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_36)[j*8+0] = testing_X_36_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_36)[j*8+1] = testing_X_36_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_36)[j*8+2] = testing_X_36_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_36)[j*8+3] = testing_X_36_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_36)[j*8+4] = testing_X_36_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_36)[j*8+5] = testing_X_36_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_36)[j*8+6] = testing_X_36_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_36)[j*8+7] = testing_X_36_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_37, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_37, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_37);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_37_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_37_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_37" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_37)[j*8+0] = testing_X_37_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_37)[j*8+1] = testing_X_37_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_37)[j*8+2] = testing_X_37_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_37)[j*8+3] = testing_X_37_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_37)[j*8+4] = testing_X_37_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_37)[j*8+5] = testing_X_37_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_37)[j*8+6] = testing_X_37_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_37)[j*8+7] = testing_X_37_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_38, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_38, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_38);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_38_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_38_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_38" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_38)[j*8+0] = testing_X_38_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_38)[j*8+1] = testing_X_38_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_38)[j*8+2] = testing_X_38_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_38)[j*8+3] = testing_X_38_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_38)[j*8+4] = testing_X_38_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_38)[j*8+5] = testing_X_38_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_38)[j*8+6] = testing_X_38_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_38)[j*8+7] = testing_X_38_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_39, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_39, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_39);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_39_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_39_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_39" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_39)[j*8+0] = testing_X_39_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_39)[j*8+1] = testing_X_39_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_39)[j*8+2] = testing_X_39_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_39)[j*8+3] = testing_X_39_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_39)[j*8+4] = testing_X_39_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_39)[j*8+5] = testing_X_39_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_39)[j*8+6] = testing_X_39_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_39)[j*8+7] = testing_X_39_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_40, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_40, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_40);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_40_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_40_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_40" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_40)[j*8+0] = testing_X_40_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_40)[j*8+1] = testing_X_40_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_40)[j*8+2] = testing_X_40_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_40)[j*8+3] = testing_X_40_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_40)[j*8+4] = testing_X_40_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_40)[j*8+5] = testing_X_40_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_40)[j*8+6] = testing_X_40_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_40)[j*8+7] = testing_X_40_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_41, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_41, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_41);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_41_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_41_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_41" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_41)[j*8+0] = testing_X_41_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_41)[j*8+1] = testing_X_41_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_41)[j*8+2] = testing_X_41_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_41)[j*8+3] = testing_X_41_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_41)[j*8+4] = testing_X_41_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_41)[j*8+5] = testing_X_41_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_41)[j*8+6] = testing_X_41_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_41)[j*8+7] = testing_X_41_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<64> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_X_42, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<8>((char*)__xlx_apatb_param_testing_X_42, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_X_42);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > testing_X_42_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_X_42_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_X_42" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_X_42)[j*8+0] = testing_X_42_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_testing_X_42)[j*8+1] = testing_X_42_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_testing_X_42)[j*8+2] = testing_X_42_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_testing_X_42)[j*8+3] = testing_X_42_pc_buffer[i].range(31, 24).to_int64();
((char*)__xlx_apatb_param_testing_X_42)[j*8+4] = testing_X_42_pc_buffer[i].range(39, 32).to_int64();
((char*)__xlx_apatb_param_testing_X_42)[j*8+5] = testing_X_42_pc_buffer[i].range(47, 40).to_int64();
((char*)__xlx_apatb_param_testing_X_42)[j*8+6] = testing_X_42_pc_buffer[i].range(55, 48).to_int64();
((char*)__xlx_apatb_param_testing_X_42)[j*8+7] = testing_X_42_pc_buffer[i].range(63, 56).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
#ifdef USE_BINARY_TV_FILE
{
transaction<8> tr(1082);
aesl_fh.read(AUTOTB_TVOUT_PC_testing_Y, tr.p, tr.tbytes);
if (little_endian()) { tr.reorder(); }
tr.send<1>((char*)__xlx_apatb_param_testing_Y, 1082);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_testing_Y);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<8> > testing_Y_pc_buffer(1082);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              testing_Y_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "testing_Y" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1082; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_testing_Y)[j*1+0] = testing_Y_pc_buffer[i].range(7, 0).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif

    AESL_transaction_pc++;
    return ;
  }
static unsigned AESL_transaction;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
CodeState = DUMP_INPUTS;
unsigned __xlx_offset_byte_param_training_X_0 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_training_X_0, 'b');
transaction<64> tr(46612);
  __xlx_offset_byte_param_training_X_0 = 0*8;
  if (__xlx_apatb_param_training_X_0) {
tr.import<8>((char*)__xlx_apatb_param_training_X_0, 46612, 0);
  }
aesl_fh.write(AUTOTB_TVIN_training_X_0, tr.p, tr.tbytes);
}

  tcl_file.set_num(46612, &tcl_file.training_X_0_depth);
#else
// print training_X_0 Transactions
{
aesl_fh.write(AUTOTB_TVIN_training_X_0, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_training_X_0 = 0*8;
if (__xlx_apatb_param_training_X_0) {
for (size_t i = 0; i < 46612; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_training_X_0 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_training_X_0, s);
}
}
}

  tcl_file.set_num(46612, &tcl_file.training_X_0_depth);
aesl_fh.write(AUTOTB_TVIN_training_X_0, end_str());
}

#endif
unsigned __xlx_offset_byte_param_training_X_1 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_training_X_1, 'b');
transaction<64> tr(46612);
  __xlx_offset_byte_param_training_X_1 = 0*8;
  if (__xlx_apatb_param_training_X_1) {
tr.import<8>((char*)__xlx_apatb_param_training_X_1, 46612, 0);
  }
aesl_fh.write(AUTOTB_TVIN_training_X_1, tr.p, tr.tbytes);
}

  tcl_file.set_num(46612, &tcl_file.training_X_1_depth);
#else
// print training_X_1 Transactions
{
aesl_fh.write(AUTOTB_TVIN_training_X_1, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_training_X_1 = 0*8;
if (__xlx_apatb_param_training_X_1) {
for (size_t i = 0; i < 46612; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_training_X_1 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_training_X_1, s);
}
}
}

  tcl_file.set_num(46612, &tcl_file.training_X_1_depth);
aesl_fh.write(AUTOTB_TVIN_training_X_1, end_str());
}

#endif
unsigned __xlx_offset_byte_param_training_X_2 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_training_X_2, 'b');
transaction<64> tr(46612);
  __xlx_offset_byte_param_training_X_2 = 0*8;
  if (__xlx_apatb_param_training_X_2) {
tr.import<8>((char*)__xlx_apatb_param_training_X_2, 46612, 0);
  }
aesl_fh.write(AUTOTB_TVIN_training_X_2, tr.p, tr.tbytes);
}

  tcl_file.set_num(46612, &tcl_file.training_X_2_depth);
#else
// print training_X_2 Transactions
{
aesl_fh.write(AUTOTB_TVIN_training_X_2, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_training_X_2 = 0*8;
if (__xlx_apatb_param_training_X_2) {
for (size_t i = 0; i < 46612; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_training_X_2 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_training_X_2, s);
}
}
}

  tcl_file.set_num(46612, &tcl_file.training_X_2_depth);
aesl_fh.write(AUTOTB_TVIN_training_X_2, end_str());
}

#endif
unsigned __xlx_offset_byte_param_training_X_3 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_training_X_3, 'b');
transaction<64> tr(46612);
  __xlx_offset_byte_param_training_X_3 = 0*8;
  if (__xlx_apatb_param_training_X_3) {
tr.import<8>((char*)__xlx_apatb_param_training_X_3, 46612, 0);
  }
aesl_fh.write(AUTOTB_TVIN_training_X_3, tr.p, tr.tbytes);
}

  tcl_file.set_num(46612, &tcl_file.training_X_3_depth);
#else
// print training_X_3 Transactions
{
aesl_fh.write(AUTOTB_TVIN_training_X_3, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_training_X_3 = 0*8;
if (__xlx_apatb_param_training_X_3) {
for (size_t i = 0; i < 46612; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_training_X_3 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_training_X_3, s);
}
}
}

  tcl_file.set_num(46612, &tcl_file.training_X_3_depth);
aesl_fh.write(AUTOTB_TVIN_training_X_3, end_str());
}

#endif
unsigned __xlx_offset_byte_param_training_Y = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_training_Y, 'b');
transaction<8> tr(4336);
  __xlx_offset_byte_param_training_Y = 0*1;
  if (__xlx_apatb_param_training_Y) {
tr.import<1>((char*)__xlx_apatb_param_training_Y, 4336, 0);
  }
aesl_fh.write(AUTOTB_TVIN_training_Y, tr.p, tr.tbytes);
}

  tcl_file.set_num(4336, &tcl_file.training_Y_depth);
#else
// print training_Y Transactions
{
aesl_fh.write(AUTOTB_TVIN_training_Y, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_training_Y = 0*1;
if (__xlx_apatb_param_training_Y) {
for (size_t i = 0; i < 4336; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_training_Y + i * 1;
std::string s = formatData(pos, 8);
aesl_fh.write(AUTOTB_TVIN_training_Y, s);
}
}
}

  tcl_file.set_num(4336, &tcl_file.training_Y_depth);
aesl_fh.write(AUTOTB_TVIN_training_Y, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_0 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_0, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_0 = 0*8;
  if (__xlx_apatb_param_testing_X_0) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_0, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_0, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_0_depth);
#else
// print testing_X_0 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_0, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_0 = 0*8;
if (__xlx_apatb_param_testing_X_0) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_0 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_0, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_0_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_0, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_1 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_1, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_1 = 0*8;
  if (__xlx_apatb_param_testing_X_1) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_1, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_1, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_1_depth);
#else
// print testing_X_1 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_1, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_1 = 0*8;
if (__xlx_apatb_param_testing_X_1) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_1 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_1, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_1_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_1, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_2 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_2, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_2 = 0*8;
  if (__xlx_apatb_param_testing_X_2) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_2, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_2, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_2_depth);
#else
// print testing_X_2 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_2, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_2 = 0*8;
if (__xlx_apatb_param_testing_X_2) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_2 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_2, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_2_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_2, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_3 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_3, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_3 = 0*8;
  if (__xlx_apatb_param_testing_X_3) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_3, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_3, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_3_depth);
#else
// print testing_X_3 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_3, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_3 = 0*8;
if (__xlx_apatb_param_testing_X_3) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_3 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_3, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_3_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_3, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_4 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_4, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_4 = 0*8;
  if (__xlx_apatb_param_testing_X_4) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_4, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_4, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_4_depth);
#else
// print testing_X_4 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_4, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_4 = 0*8;
if (__xlx_apatb_param_testing_X_4) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_4 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_4, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_4_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_4, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_5 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_5, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_5 = 0*8;
  if (__xlx_apatb_param_testing_X_5) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_5, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_5, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_5_depth);
#else
// print testing_X_5 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_5, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_5 = 0*8;
if (__xlx_apatb_param_testing_X_5) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_5 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_5, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_5_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_5, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_6 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_6, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_6 = 0*8;
  if (__xlx_apatb_param_testing_X_6) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_6, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_6, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_6_depth);
#else
// print testing_X_6 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_6, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_6 = 0*8;
if (__xlx_apatb_param_testing_X_6) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_6 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_6, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_6_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_6, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_7 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_7, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_7 = 0*8;
  if (__xlx_apatb_param_testing_X_7) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_7, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_7, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_7_depth);
#else
// print testing_X_7 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_7, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_7 = 0*8;
if (__xlx_apatb_param_testing_X_7) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_7 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_7, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_7_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_7, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_8 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_8, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_8 = 0*8;
  if (__xlx_apatb_param_testing_X_8) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_8, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_8, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_8_depth);
#else
// print testing_X_8 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_8, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_8 = 0*8;
if (__xlx_apatb_param_testing_X_8) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_8 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_8, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_8_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_8, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_9 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_9, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_9 = 0*8;
  if (__xlx_apatb_param_testing_X_9) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_9, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_9, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_9_depth);
#else
// print testing_X_9 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_9, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_9 = 0*8;
if (__xlx_apatb_param_testing_X_9) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_9 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_9, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_9_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_9, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_10 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_10, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_10 = 0*8;
  if (__xlx_apatb_param_testing_X_10) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_10, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_10, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_10_depth);
#else
// print testing_X_10 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_10, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_10 = 0*8;
if (__xlx_apatb_param_testing_X_10) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_10 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_10, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_10_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_10, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_11 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_11, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_11 = 0*8;
  if (__xlx_apatb_param_testing_X_11) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_11, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_11, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_11_depth);
#else
// print testing_X_11 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_11, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_11 = 0*8;
if (__xlx_apatb_param_testing_X_11) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_11 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_11, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_11_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_11, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_12 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_12, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_12 = 0*8;
  if (__xlx_apatb_param_testing_X_12) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_12, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_12, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_12_depth);
#else
// print testing_X_12 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_12, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_12 = 0*8;
if (__xlx_apatb_param_testing_X_12) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_12 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_12, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_12_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_12, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_13 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_13, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_13 = 0*8;
  if (__xlx_apatb_param_testing_X_13) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_13, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_13, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_13_depth);
#else
// print testing_X_13 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_13, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_13 = 0*8;
if (__xlx_apatb_param_testing_X_13) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_13 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_13, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_13_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_13, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_14 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_14, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_14 = 0*8;
  if (__xlx_apatb_param_testing_X_14) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_14, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_14, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_14_depth);
#else
// print testing_X_14 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_14, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_14 = 0*8;
if (__xlx_apatb_param_testing_X_14) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_14 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_14, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_14_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_14, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_15 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_15, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_15 = 0*8;
  if (__xlx_apatb_param_testing_X_15) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_15, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_15, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_15_depth);
#else
// print testing_X_15 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_15, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_15 = 0*8;
if (__xlx_apatb_param_testing_X_15) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_15 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_15, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_15_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_15, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_16 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_16, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_16 = 0*8;
  if (__xlx_apatb_param_testing_X_16) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_16, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_16, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_16_depth);
#else
// print testing_X_16 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_16, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_16 = 0*8;
if (__xlx_apatb_param_testing_X_16) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_16 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_16, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_16_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_16, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_17 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_17, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_17 = 0*8;
  if (__xlx_apatb_param_testing_X_17) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_17, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_17, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_17_depth);
#else
// print testing_X_17 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_17, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_17 = 0*8;
if (__xlx_apatb_param_testing_X_17) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_17 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_17, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_17_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_17, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_18 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_18, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_18 = 0*8;
  if (__xlx_apatb_param_testing_X_18) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_18, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_18, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_18_depth);
#else
// print testing_X_18 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_18, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_18 = 0*8;
if (__xlx_apatb_param_testing_X_18) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_18 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_18, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_18_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_18, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_19 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_19, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_19 = 0*8;
  if (__xlx_apatb_param_testing_X_19) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_19, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_19, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_19_depth);
#else
// print testing_X_19 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_19, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_19 = 0*8;
if (__xlx_apatb_param_testing_X_19) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_19 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_19, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_19_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_19, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_20 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_20, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_20 = 0*8;
  if (__xlx_apatb_param_testing_X_20) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_20, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_20, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_20_depth);
#else
// print testing_X_20 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_20, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_20 = 0*8;
if (__xlx_apatb_param_testing_X_20) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_20 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_20, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_20_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_20, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_21 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_21, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_21 = 0*8;
  if (__xlx_apatb_param_testing_X_21) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_21, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_21, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_21_depth);
#else
// print testing_X_21 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_21, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_21 = 0*8;
if (__xlx_apatb_param_testing_X_21) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_21 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_21, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_21_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_21, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_22 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_22, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_22 = 0*8;
  if (__xlx_apatb_param_testing_X_22) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_22, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_22, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_22_depth);
#else
// print testing_X_22 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_22, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_22 = 0*8;
if (__xlx_apatb_param_testing_X_22) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_22 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_22, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_22_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_22, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_23 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_23, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_23 = 0*8;
  if (__xlx_apatb_param_testing_X_23) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_23, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_23, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_23_depth);
#else
// print testing_X_23 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_23, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_23 = 0*8;
if (__xlx_apatb_param_testing_X_23) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_23 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_23, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_23_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_23, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_24 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_24, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_24 = 0*8;
  if (__xlx_apatb_param_testing_X_24) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_24, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_24, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_24_depth);
#else
// print testing_X_24 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_24, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_24 = 0*8;
if (__xlx_apatb_param_testing_X_24) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_24 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_24, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_24_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_24, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_25 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_25, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_25 = 0*8;
  if (__xlx_apatb_param_testing_X_25) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_25, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_25, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_25_depth);
#else
// print testing_X_25 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_25, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_25 = 0*8;
if (__xlx_apatb_param_testing_X_25) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_25 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_25, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_25_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_25, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_26 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_26, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_26 = 0*8;
  if (__xlx_apatb_param_testing_X_26) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_26, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_26, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_26_depth);
#else
// print testing_X_26 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_26, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_26 = 0*8;
if (__xlx_apatb_param_testing_X_26) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_26 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_26, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_26_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_26, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_27 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_27, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_27 = 0*8;
  if (__xlx_apatb_param_testing_X_27) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_27, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_27, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_27_depth);
#else
// print testing_X_27 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_27, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_27 = 0*8;
if (__xlx_apatb_param_testing_X_27) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_27 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_27, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_27_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_27, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_28 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_28, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_28 = 0*8;
  if (__xlx_apatb_param_testing_X_28) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_28, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_28, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_28_depth);
#else
// print testing_X_28 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_28, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_28 = 0*8;
if (__xlx_apatb_param_testing_X_28) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_28 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_28, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_28_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_28, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_29 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_29, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_29 = 0*8;
  if (__xlx_apatb_param_testing_X_29) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_29, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_29, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_29_depth);
#else
// print testing_X_29 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_29, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_29 = 0*8;
if (__xlx_apatb_param_testing_X_29) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_29 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_29, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_29_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_29, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_30 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_30, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_30 = 0*8;
  if (__xlx_apatb_param_testing_X_30) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_30, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_30, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_30_depth);
#else
// print testing_X_30 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_30, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_30 = 0*8;
if (__xlx_apatb_param_testing_X_30) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_30 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_30, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_30_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_30, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_31 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_31, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_31 = 0*8;
  if (__xlx_apatb_param_testing_X_31) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_31, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_31, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_31_depth);
#else
// print testing_X_31 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_31, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_31 = 0*8;
if (__xlx_apatb_param_testing_X_31) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_31 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_31, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_31_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_31, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_32 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_32, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_32 = 0*8;
  if (__xlx_apatb_param_testing_X_32) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_32, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_32, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_32_depth);
#else
// print testing_X_32 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_32, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_32 = 0*8;
if (__xlx_apatb_param_testing_X_32) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_32 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_32, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_32_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_32, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_33 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_33, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_33 = 0*8;
  if (__xlx_apatb_param_testing_X_33) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_33, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_33, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_33_depth);
#else
// print testing_X_33 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_33, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_33 = 0*8;
if (__xlx_apatb_param_testing_X_33) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_33 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_33, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_33_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_33, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_34 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_34, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_34 = 0*8;
  if (__xlx_apatb_param_testing_X_34) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_34, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_34, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_34_depth);
#else
// print testing_X_34 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_34, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_34 = 0*8;
if (__xlx_apatb_param_testing_X_34) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_34 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_34, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_34_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_34, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_35 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_35, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_35 = 0*8;
  if (__xlx_apatb_param_testing_X_35) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_35, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_35, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_35_depth);
#else
// print testing_X_35 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_35, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_35 = 0*8;
if (__xlx_apatb_param_testing_X_35) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_35 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_35, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_35_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_35, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_36 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_36, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_36 = 0*8;
  if (__xlx_apatb_param_testing_X_36) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_36, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_36, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_36_depth);
#else
// print testing_X_36 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_36, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_36 = 0*8;
if (__xlx_apatb_param_testing_X_36) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_36 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_36, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_36_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_36, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_37 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_37, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_37 = 0*8;
  if (__xlx_apatb_param_testing_X_37) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_37, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_37, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_37_depth);
#else
// print testing_X_37 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_37, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_37 = 0*8;
if (__xlx_apatb_param_testing_X_37) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_37 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_37, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_37_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_37, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_38 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_38, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_38 = 0*8;
  if (__xlx_apatb_param_testing_X_38) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_38, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_38, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_38_depth);
#else
// print testing_X_38 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_38, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_38 = 0*8;
if (__xlx_apatb_param_testing_X_38) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_38 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_38, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_38_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_38, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_39 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_39, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_39 = 0*8;
  if (__xlx_apatb_param_testing_X_39) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_39, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_39, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_39_depth);
#else
// print testing_X_39 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_39, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_39 = 0*8;
if (__xlx_apatb_param_testing_X_39) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_39 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_39, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_39_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_39, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_40 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_40, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_40 = 0*8;
  if (__xlx_apatb_param_testing_X_40) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_40, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_40, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_40_depth);
#else
// print testing_X_40 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_40, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_40 = 0*8;
if (__xlx_apatb_param_testing_X_40) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_40 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_40, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_40_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_40, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_41 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_41, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_41 = 0*8;
  if (__xlx_apatb_param_testing_X_41) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_41, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_41, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_41_depth);
#else
// print testing_X_41 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_41, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_41 = 0*8;
if (__xlx_apatb_param_testing_X_41) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_41 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_41, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_41_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_41, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_X_42 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X_42, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_42 = 0*8;
  if (__xlx_apatb_param_testing_X_42) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_42, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X_42, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_42_depth);
#else
// print testing_X_42 Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X_42, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_42 = 0*8;
if (__xlx_apatb_param_testing_X_42) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_42 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X_42, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_42_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X_42, end_str());
}

#endif
unsigned __xlx_offset_byte_param_testing_Y = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_Y, 'b');
transaction<8> tr(1082);
  __xlx_offset_byte_param_testing_Y = 0*1;
  if (__xlx_apatb_param_testing_Y) {
tr.import<1>((char*)__xlx_apatb_param_testing_Y, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_Y, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_Y_depth);
#else
// print testing_Y Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_Y, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_Y = 0*1;
if (__xlx_apatb_param_testing_Y) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_Y + i * 1;
std::string s = formatData(pos, 8);
aesl_fh.write(AUTOTB_TVIN_testing_Y, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_Y_depth);
aesl_fh.write(AUTOTB_TVIN_testing_Y, end_str());
}

#endif
unsigned __xlx_offset_byte_param_min = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_min, 'b');
transaction<64> tr(43);
  __xlx_offset_byte_param_min = 0*8;
  if (__xlx_apatb_param_min) {
tr.import<8>((char*)__xlx_apatb_param_min, 43, 0);
  }
aesl_fh.write(AUTOTB_TVIN_min, tr.p, tr.tbytes);
}

  tcl_file.set_num(43, &tcl_file.min_depth);
#else
// print min Transactions
{
aesl_fh.write(AUTOTB_TVIN_min, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_min = 0*8;
if (__xlx_apatb_param_min) {
for (size_t i = 0; i < 43; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_min + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_min, s);
}
}
}

  tcl_file.set_num(43, &tcl_file.min_depth);
aesl_fh.write(AUTOTB_TVIN_min, end_str());
}

#endif
unsigned __xlx_offset_byte_param_max = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_max, 'b');
transaction<64> tr(43);
  __xlx_offset_byte_param_max = 0*8;
  if (__xlx_apatb_param_max) {
tr.import<8>((char*)__xlx_apatb_param_max, 43, 0);
  }
aesl_fh.write(AUTOTB_TVIN_max, tr.p, tr.tbytes);
}

  tcl_file.set_num(43, &tcl_file.max_depth);
#else
// print max Transactions
{
aesl_fh.write(AUTOTB_TVIN_max, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_max = 0*8;
if (__xlx_apatb_param_max) {
for (size_t i = 0; i < 43; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_max + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_max, s);
}
}
}

  tcl_file.set_num(43, &tcl_file.max_depth);
aesl_fh.write(AUTOTB_TVIN_max, end_str());
}

#endif
CodeState = CALL_C_DUT;
kNN_PredictAll_hw_stub_wrapper(__xlx_apatb_param_training_X_0, __xlx_apatb_param_training_X_1, __xlx_apatb_param_training_X_2, __xlx_apatb_param_training_X_3, __xlx_apatb_param_training_Y, __xlx_apatb_param_testing_X_0, __xlx_apatb_param_testing_X_1, __xlx_apatb_param_testing_X_2, __xlx_apatb_param_testing_X_3, __xlx_apatb_param_testing_X_4, __xlx_apatb_param_testing_X_5, __xlx_apatb_param_testing_X_6, __xlx_apatb_param_testing_X_7, __xlx_apatb_param_testing_X_8, __xlx_apatb_param_testing_X_9, __xlx_apatb_param_testing_X_10, __xlx_apatb_param_testing_X_11, __xlx_apatb_param_testing_X_12, __xlx_apatb_param_testing_X_13, __xlx_apatb_param_testing_X_14, __xlx_apatb_param_testing_X_15, __xlx_apatb_param_testing_X_16, __xlx_apatb_param_testing_X_17, __xlx_apatb_param_testing_X_18, __xlx_apatb_param_testing_X_19, __xlx_apatb_param_testing_X_20, __xlx_apatb_param_testing_X_21, __xlx_apatb_param_testing_X_22, __xlx_apatb_param_testing_X_23, __xlx_apatb_param_testing_X_24, __xlx_apatb_param_testing_X_25, __xlx_apatb_param_testing_X_26, __xlx_apatb_param_testing_X_27, __xlx_apatb_param_testing_X_28, __xlx_apatb_param_testing_X_29, __xlx_apatb_param_testing_X_30, __xlx_apatb_param_testing_X_31, __xlx_apatb_param_testing_X_32, __xlx_apatb_param_testing_X_33, __xlx_apatb_param_testing_X_34, __xlx_apatb_param_testing_X_35, __xlx_apatb_param_testing_X_36, __xlx_apatb_param_testing_X_37, __xlx_apatb_param_testing_X_38, __xlx_apatb_param_testing_X_39, __xlx_apatb_param_testing_X_40, __xlx_apatb_param_testing_X_41, __xlx_apatb_param_testing_X_42, __xlx_apatb_param_testing_Y, __xlx_apatb_param_min, __xlx_apatb_param_max);
CodeState = DUMP_OUTPUTS;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_0, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_0 = 0*8;
  if (__xlx_apatb_param_testing_X_0) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_0, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_0, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_0_depth);
#else
// print testing_X_0 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_0, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_0 = 0*8;
if (__xlx_apatb_param_testing_X_0) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_0 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_0, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_0_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_0, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_1, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_1 = 0*8;
  if (__xlx_apatb_param_testing_X_1) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_1, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_1, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_1_depth);
#else
// print testing_X_1 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_1, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_1 = 0*8;
if (__xlx_apatb_param_testing_X_1) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_1 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_1, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_1_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_1, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_2, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_2 = 0*8;
  if (__xlx_apatb_param_testing_X_2) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_2, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_2, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_2_depth);
#else
// print testing_X_2 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_2, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_2 = 0*8;
if (__xlx_apatb_param_testing_X_2) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_2 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_2, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_2_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_2, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_3, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_3 = 0*8;
  if (__xlx_apatb_param_testing_X_3) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_3, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_3, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_3_depth);
#else
// print testing_X_3 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_3, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_3 = 0*8;
if (__xlx_apatb_param_testing_X_3) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_3 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_3, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_3_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_3, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_4, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_4 = 0*8;
  if (__xlx_apatb_param_testing_X_4) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_4, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_4, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_4_depth);
#else
// print testing_X_4 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_4, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_4 = 0*8;
if (__xlx_apatb_param_testing_X_4) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_4 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_4, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_4_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_4, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_5, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_5 = 0*8;
  if (__xlx_apatb_param_testing_X_5) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_5, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_5, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_5_depth);
#else
// print testing_X_5 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_5, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_5 = 0*8;
if (__xlx_apatb_param_testing_X_5) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_5 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_5, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_5_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_5, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_6, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_6 = 0*8;
  if (__xlx_apatb_param_testing_X_6) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_6, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_6, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_6_depth);
#else
// print testing_X_6 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_6, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_6 = 0*8;
if (__xlx_apatb_param_testing_X_6) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_6 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_6, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_6_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_6, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_7, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_7 = 0*8;
  if (__xlx_apatb_param_testing_X_7) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_7, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_7, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_7_depth);
#else
// print testing_X_7 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_7, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_7 = 0*8;
if (__xlx_apatb_param_testing_X_7) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_7 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_7, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_7_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_7, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_8, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_8 = 0*8;
  if (__xlx_apatb_param_testing_X_8) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_8, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_8, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_8_depth);
#else
// print testing_X_8 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_8, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_8 = 0*8;
if (__xlx_apatb_param_testing_X_8) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_8 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_8, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_8_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_8, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_9, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_9 = 0*8;
  if (__xlx_apatb_param_testing_X_9) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_9, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_9, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_9_depth);
#else
// print testing_X_9 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_9, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_9 = 0*8;
if (__xlx_apatb_param_testing_X_9) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_9 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_9, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_9_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_9, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_10, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_10 = 0*8;
  if (__xlx_apatb_param_testing_X_10) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_10, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_10, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_10_depth);
#else
// print testing_X_10 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_10, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_10 = 0*8;
if (__xlx_apatb_param_testing_X_10) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_10 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_10, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_10_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_10, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_11, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_11 = 0*8;
  if (__xlx_apatb_param_testing_X_11) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_11, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_11, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_11_depth);
#else
// print testing_X_11 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_11, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_11 = 0*8;
if (__xlx_apatb_param_testing_X_11) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_11 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_11, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_11_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_11, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_12, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_12 = 0*8;
  if (__xlx_apatb_param_testing_X_12) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_12, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_12, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_12_depth);
#else
// print testing_X_12 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_12, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_12 = 0*8;
if (__xlx_apatb_param_testing_X_12) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_12 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_12, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_12_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_12, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_13, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_13 = 0*8;
  if (__xlx_apatb_param_testing_X_13) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_13, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_13, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_13_depth);
#else
// print testing_X_13 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_13, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_13 = 0*8;
if (__xlx_apatb_param_testing_X_13) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_13 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_13, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_13_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_13, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_14, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_14 = 0*8;
  if (__xlx_apatb_param_testing_X_14) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_14, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_14, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_14_depth);
#else
// print testing_X_14 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_14, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_14 = 0*8;
if (__xlx_apatb_param_testing_X_14) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_14 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_14, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_14_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_14, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_15, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_15 = 0*8;
  if (__xlx_apatb_param_testing_X_15) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_15, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_15, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_15_depth);
#else
// print testing_X_15 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_15, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_15 = 0*8;
if (__xlx_apatb_param_testing_X_15) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_15 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_15, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_15_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_15, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_16, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_16 = 0*8;
  if (__xlx_apatb_param_testing_X_16) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_16, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_16, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_16_depth);
#else
// print testing_X_16 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_16, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_16 = 0*8;
if (__xlx_apatb_param_testing_X_16) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_16 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_16, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_16_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_16, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_17, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_17 = 0*8;
  if (__xlx_apatb_param_testing_X_17) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_17, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_17, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_17_depth);
#else
// print testing_X_17 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_17, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_17 = 0*8;
if (__xlx_apatb_param_testing_X_17) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_17 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_17, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_17_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_17, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_18, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_18 = 0*8;
  if (__xlx_apatb_param_testing_X_18) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_18, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_18, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_18_depth);
#else
// print testing_X_18 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_18, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_18 = 0*8;
if (__xlx_apatb_param_testing_X_18) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_18 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_18, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_18_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_18, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_19, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_19 = 0*8;
  if (__xlx_apatb_param_testing_X_19) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_19, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_19, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_19_depth);
#else
// print testing_X_19 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_19, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_19 = 0*8;
if (__xlx_apatb_param_testing_X_19) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_19 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_19, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_19_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_19, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_20, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_20 = 0*8;
  if (__xlx_apatb_param_testing_X_20) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_20, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_20, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_20_depth);
#else
// print testing_X_20 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_20, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_20 = 0*8;
if (__xlx_apatb_param_testing_X_20) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_20 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_20, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_20_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_20, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_21, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_21 = 0*8;
  if (__xlx_apatb_param_testing_X_21) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_21, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_21, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_21_depth);
#else
// print testing_X_21 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_21, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_21 = 0*8;
if (__xlx_apatb_param_testing_X_21) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_21 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_21, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_21_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_21, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_22, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_22 = 0*8;
  if (__xlx_apatb_param_testing_X_22) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_22, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_22, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_22_depth);
#else
// print testing_X_22 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_22, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_22 = 0*8;
if (__xlx_apatb_param_testing_X_22) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_22 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_22, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_22_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_22, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_23, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_23 = 0*8;
  if (__xlx_apatb_param_testing_X_23) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_23, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_23, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_23_depth);
#else
// print testing_X_23 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_23, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_23 = 0*8;
if (__xlx_apatb_param_testing_X_23) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_23 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_23, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_23_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_23, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_24, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_24 = 0*8;
  if (__xlx_apatb_param_testing_X_24) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_24, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_24, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_24_depth);
#else
// print testing_X_24 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_24, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_24 = 0*8;
if (__xlx_apatb_param_testing_X_24) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_24 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_24, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_24_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_24, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_25, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_25 = 0*8;
  if (__xlx_apatb_param_testing_X_25) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_25, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_25, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_25_depth);
#else
// print testing_X_25 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_25, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_25 = 0*8;
if (__xlx_apatb_param_testing_X_25) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_25 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_25, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_25_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_25, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_26, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_26 = 0*8;
  if (__xlx_apatb_param_testing_X_26) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_26, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_26, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_26_depth);
#else
// print testing_X_26 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_26, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_26 = 0*8;
if (__xlx_apatb_param_testing_X_26) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_26 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_26, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_26_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_26, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_27, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_27 = 0*8;
  if (__xlx_apatb_param_testing_X_27) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_27, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_27, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_27_depth);
#else
// print testing_X_27 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_27, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_27 = 0*8;
if (__xlx_apatb_param_testing_X_27) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_27 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_27, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_27_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_27, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_28, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_28 = 0*8;
  if (__xlx_apatb_param_testing_X_28) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_28, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_28, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_28_depth);
#else
// print testing_X_28 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_28, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_28 = 0*8;
if (__xlx_apatb_param_testing_X_28) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_28 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_28, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_28_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_28, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_29, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_29 = 0*8;
  if (__xlx_apatb_param_testing_X_29) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_29, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_29, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_29_depth);
#else
// print testing_X_29 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_29, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_29 = 0*8;
if (__xlx_apatb_param_testing_X_29) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_29 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_29, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_29_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_29, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_30, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_30 = 0*8;
  if (__xlx_apatb_param_testing_X_30) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_30, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_30, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_30_depth);
#else
// print testing_X_30 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_30, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_30 = 0*8;
if (__xlx_apatb_param_testing_X_30) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_30 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_30, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_30_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_30, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_31, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_31 = 0*8;
  if (__xlx_apatb_param_testing_X_31) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_31, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_31, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_31_depth);
#else
// print testing_X_31 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_31, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_31 = 0*8;
if (__xlx_apatb_param_testing_X_31) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_31 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_31, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_31_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_31, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_32, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_32 = 0*8;
  if (__xlx_apatb_param_testing_X_32) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_32, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_32, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_32_depth);
#else
// print testing_X_32 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_32, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_32 = 0*8;
if (__xlx_apatb_param_testing_X_32) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_32 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_32, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_32_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_32, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_33, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_33 = 0*8;
  if (__xlx_apatb_param_testing_X_33) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_33, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_33, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_33_depth);
#else
// print testing_X_33 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_33, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_33 = 0*8;
if (__xlx_apatb_param_testing_X_33) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_33 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_33, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_33_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_33, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_34, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_34 = 0*8;
  if (__xlx_apatb_param_testing_X_34) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_34, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_34, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_34_depth);
#else
// print testing_X_34 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_34, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_34 = 0*8;
if (__xlx_apatb_param_testing_X_34) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_34 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_34, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_34_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_34, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_35, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_35 = 0*8;
  if (__xlx_apatb_param_testing_X_35) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_35, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_35, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_35_depth);
#else
// print testing_X_35 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_35, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_35 = 0*8;
if (__xlx_apatb_param_testing_X_35) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_35 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_35, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_35_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_35, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_36, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_36 = 0*8;
  if (__xlx_apatb_param_testing_X_36) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_36, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_36, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_36_depth);
#else
// print testing_X_36 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_36, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_36 = 0*8;
if (__xlx_apatb_param_testing_X_36) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_36 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_36, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_36_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_36, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_37, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_37 = 0*8;
  if (__xlx_apatb_param_testing_X_37) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_37, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_37, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_37_depth);
#else
// print testing_X_37 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_37, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_37 = 0*8;
if (__xlx_apatb_param_testing_X_37) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_37 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_37, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_37_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_37, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_38, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_38 = 0*8;
  if (__xlx_apatb_param_testing_X_38) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_38, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_38, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_38_depth);
#else
// print testing_X_38 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_38, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_38 = 0*8;
if (__xlx_apatb_param_testing_X_38) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_38 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_38, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_38_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_38, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_39, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_39 = 0*8;
  if (__xlx_apatb_param_testing_X_39) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_39, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_39, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_39_depth);
#else
// print testing_X_39 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_39, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_39 = 0*8;
if (__xlx_apatb_param_testing_X_39) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_39 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_39, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_39_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_39, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_40, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_40 = 0*8;
  if (__xlx_apatb_param_testing_X_40) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_40, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_40, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_40_depth);
#else
// print testing_X_40 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_40, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_40 = 0*8;
if (__xlx_apatb_param_testing_X_40) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_40 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_40, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_40_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_40, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_41, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_41 = 0*8;
  if (__xlx_apatb_param_testing_X_41) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_41, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_41, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_41_depth);
#else
// print testing_X_41 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_41, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_41 = 0*8;
if (__xlx_apatb_param_testing_X_41) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_41 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_41, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_41_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_41, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_X_42, 'b');
transaction<64> tr(1082);
  __xlx_offset_byte_param_testing_X_42 = 0*8;
  if (__xlx_apatb_param_testing_X_42) {
tr.import<8>((char*)__xlx_apatb_param_testing_X_42, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_X_42, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_X_42_depth);
#else
// print testing_X_42 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_X_42, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X_42 = 0*8;
if (__xlx_apatb_param_testing_X_42) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X_42 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVOUT_testing_X_42, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_X_42_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_X_42, end_str());
}

#endif
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_testing_Y, 'b');
transaction<8> tr(1082);
  __xlx_offset_byte_param_testing_Y = 0*1;
  if (__xlx_apatb_param_testing_Y) {
tr.import<1>((char*)__xlx_apatb_param_testing_Y, 1082, 0);
  }
aesl_fh.write(AUTOTB_TVOUT_testing_Y, tr.p, tr.tbytes);
}

  tcl_file.set_num(1082, &tcl_file.testing_Y_depth);
#else
// print testing_Y Transactions
{
aesl_fh.write(AUTOTB_TVOUT_testing_Y, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_Y = 0*1;
if (__xlx_apatb_param_testing_Y) {
for (size_t i = 0; i < 1082; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_Y + i * 1;
std::string s = formatData(pos, 8);
aesl_fh.write(AUTOTB_TVOUT_testing_Y, s);
}
}
}

  tcl_file.set_num(1082, &tcl_file.testing_Y_depth);
aesl_fh.write(AUTOTB_TVOUT_testing_Y, end_str());
}

#endif
CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
