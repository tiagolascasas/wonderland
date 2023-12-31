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
#define AUTOTB_TVIN_training_X_4 "../tv/cdatafile/c.kNN_PredictAll.autotvin_training_X_4.dat"
#define AUTOTB_TVOUT_training_X_4 "../tv/cdatafile/c.kNN_PredictAll.autotvout_training_X_4.dat"
#define AUTOTB_TVIN_training_X_5 "../tv/cdatafile/c.kNN_PredictAll.autotvin_training_X_5.dat"
#define AUTOTB_TVOUT_training_X_5 "../tv/cdatafile/c.kNN_PredictAll.autotvout_training_X_5.dat"
#define AUTOTB_TVIN_training_Y "../tv/cdatafile/c.kNN_PredictAll.autotvin_training_Y.dat"
#define AUTOTB_TVOUT_training_Y "../tv/cdatafile/c.kNN_PredictAll.autotvout_training_Y.dat"
#define AUTOTB_TVIN_testing_X "../tv/cdatafile/c.kNN_PredictAll.autotvin_testing_X.dat"
#define AUTOTB_TVOUT_testing_X "../tv/cdatafile/c.kNN_PredictAll.autotvout_testing_X.dat"
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
#define AUTOTB_TVOUT_PC_training_X_4 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_training_X_4.dat"
#define AUTOTB_TVOUT_PC_training_X_5 "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_training_X_5.dat"
#define AUTOTB_TVOUT_PC_training_Y "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_training_Y.dat"
#define AUTOTB_TVOUT_PC_testing_X "../tv/rtldatafile/rtl.kNN_PredictAll.autotvout_testing_X.dat"
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
  training_X_4_depth = 0;
  training_X_5_depth = 0;
  training_Y_depth = 0;
  testing_X_depth = 0;
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
  total_list << "{training_X_4 " << training_X_4_depth << "}\n";
  total_list << "{training_X_5 " << training_X_5_depth << "}\n";
  total_list << "{training_Y " << training_Y_depth << "}\n";
  total_list << "{testing_X " << testing_X_depth << "}\n";
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
    int training_X_4_depth;
    int training_X_5_depth;
    int training_Y_depth;
    int testing_X_depth;
    int testing_Y_depth;
    int min_depth;
    int max_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};


extern "C" void kNN_PredictAll_hw_stub_wrapper(volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *);

extern "C" void apatb_kNN_PredictAll_hw(volatile void * __xlx_apatb_param_training_X_0, volatile void * __xlx_apatb_param_training_X_1, volatile void * __xlx_apatb_param_training_X_2, volatile void * __xlx_apatb_param_training_X_3, volatile void * __xlx_apatb_param_training_X_4, volatile void * __xlx_apatb_param_training_X_5, volatile void * __xlx_apatb_param_training_Y, volatile void * __xlx_apatb_param_testing_X, volatile void * __xlx_apatb_param_testing_Y, volatile void * __xlx_apatb_param_min, volatile void * __xlx_apatb_param_max) {
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
transaction<64> tr(31089);
  __xlx_offset_byte_param_training_X_0 = 0*8;
  if (__xlx_apatb_param_training_X_0) {
tr.import<8>((char*)__xlx_apatb_param_training_X_0, 31089, 0);
  }
aesl_fh.write(AUTOTB_TVIN_training_X_0, tr.p, tr.tbytes);
}

  tcl_file.set_num(31089, &tcl_file.training_X_0_depth);
#else
// print training_X_0 Transactions
{
aesl_fh.write(AUTOTB_TVIN_training_X_0, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_training_X_0 = 0*8;
if (__xlx_apatb_param_training_X_0) {
for (size_t i = 0; i < 31089; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_training_X_0 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_training_X_0, s);
}
}
}

  tcl_file.set_num(31089, &tcl_file.training_X_0_depth);
aesl_fh.write(AUTOTB_TVIN_training_X_0, end_str());
}

#endif
unsigned __xlx_offset_byte_param_training_X_1 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_training_X_1, 'b');
transaction<64> tr(31089);
  __xlx_offset_byte_param_training_X_1 = 0*8;
  if (__xlx_apatb_param_training_X_1) {
tr.import<8>((char*)__xlx_apatb_param_training_X_1, 31089, 0);
  }
aesl_fh.write(AUTOTB_TVIN_training_X_1, tr.p, tr.tbytes);
}

  tcl_file.set_num(31089, &tcl_file.training_X_1_depth);
#else
// print training_X_1 Transactions
{
aesl_fh.write(AUTOTB_TVIN_training_X_1, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_training_X_1 = 0*8;
if (__xlx_apatb_param_training_X_1) {
for (size_t i = 0; i < 31089; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_training_X_1 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_training_X_1, s);
}
}
}

  tcl_file.set_num(31089, &tcl_file.training_X_1_depth);
aesl_fh.write(AUTOTB_TVIN_training_X_1, end_str());
}

#endif
unsigned __xlx_offset_byte_param_training_X_2 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_training_X_2, 'b');
transaction<64> tr(31089);
  __xlx_offset_byte_param_training_X_2 = 0*8;
  if (__xlx_apatb_param_training_X_2) {
tr.import<8>((char*)__xlx_apatb_param_training_X_2, 31089, 0);
  }
aesl_fh.write(AUTOTB_TVIN_training_X_2, tr.p, tr.tbytes);
}

  tcl_file.set_num(31089, &tcl_file.training_X_2_depth);
#else
// print training_X_2 Transactions
{
aesl_fh.write(AUTOTB_TVIN_training_X_2, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_training_X_2 = 0*8;
if (__xlx_apatb_param_training_X_2) {
for (size_t i = 0; i < 31089; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_training_X_2 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_training_X_2, s);
}
}
}

  tcl_file.set_num(31089, &tcl_file.training_X_2_depth);
aesl_fh.write(AUTOTB_TVIN_training_X_2, end_str());
}

#endif
unsigned __xlx_offset_byte_param_training_X_3 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_training_X_3, 'b');
transaction<64> tr(31089);
  __xlx_offset_byte_param_training_X_3 = 0*8;
  if (__xlx_apatb_param_training_X_3) {
tr.import<8>((char*)__xlx_apatb_param_training_X_3, 31089, 0);
  }
aesl_fh.write(AUTOTB_TVIN_training_X_3, tr.p, tr.tbytes);
}

  tcl_file.set_num(31089, &tcl_file.training_X_3_depth);
#else
// print training_X_3 Transactions
{
aesl_fh.write(AUTOTB_TVIN_training_X_3, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_training_X_3 = 0*8;
if (__xlx_apatb_param_training_X_3) {
for (size_t i = 0; i < 31089; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_training_X_3 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_training_X_3, s);
}
}
}

  tcl_file.set_num(31089, &tcl_file.training_X_3_depth);
aesl_fh.write(AUTOTB_TVIN_training_X_3, end_str());
}

#endif
unsigned __xlx_offset_byte_param_training_X_4 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_training_X_4, 'b');
transaction<64> tr(31089);
  __xlx_offset_byte_param_training_X_4 = 0*8;
  if (__xlx_apatb_param_training_X_4) {
tr.import<8>((char*)__xlx_apatb_param_training_X_4, 31089, 0);
  }
aesl_fh.write(AUTOTB_TVIN_training_X_4, tr.p, tr.tbytes);
}

  tcl_file.set_num(31089, &tcl_file.training_X_4_depth);
#else
// print training_X_4 Transactions
{
aesl_fh.write(AUTOTB_TVIN_training_X_4, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_training_X_4 = 0*8;
if (__xlx_apatb_param_training_X_4) {
for (size_t i = 0; i < 31089; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_training_X_4 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_training_X_4, s);
}
}
}

  tcl_file.set_num(31089, &tcl_file.training_X_4_depth);
aesl_fh.write(AUTOTB_TVIN_training_X_4, end_str());
}

#endif
unsigned __xlx_offset_byte_param_training_X_5 = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_training_X_5, 'b');
transaction<64> tr(31089);
  __xlx_offset_byte_param_training_X_5 = 0*8;
  if (__xlx_apatb_param_training_X_5) {
tr.import<8>((char*)__xlx_apatb_param_training_X_5, 31089, 0);
  }
aesl_fh.write(AUTOTB_TVIN_training_X_5, tr.p, tr.tbytes);
}

  tcl_file.set_num(31089, &tcl_file.training_X_5_depth);
#else
// print training_X_5 Transactions
{
aesl_fh.write(AUTOTB_TVIN_training_X_5, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_training_X_5 = 0*8;
if (__xlx_apatb_param_training_X_5) {
for (size_t i = 0; i < 31089; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_training_X_5 + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_training_X_5, s);
}
}
}

  tcl_file.set_num(31089, &tcl_file.training_X_5_depth);
aesl_fh.write(AUTOTB_TVIN_training_X_5, end_str());
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
unsigned __xlx_offset_byte_param_testing_X = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_testing_X, 'b');
transaction<64> tr(46526);
  __xlx_offset_byte_param_testing_X = 0*8;
  if (__xlx_apatb_param_testing_X) {
tr.import<8>((char*)__xlx_apatb_param_testing_X, 46526, 0);
  }
aesl_fh.write(AUTOTB_TVIN_testing_X, tr.p, tr.tbytes);
}

  tcl_file.set_num(46526, &tcl_file.testing_X_depth);
#else
// print testing_X Transactions
{
aesl_fh.write(AUTOTB_TVIN_testing_X, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_testing_X = 0*8;
if (__xlx_apatb_param_testing_X) {
for (size_t i = 0; i < 46526; ++i) {
unsigned char *pos = (unsigned char*)__xlx_apatb_param_testing_X + i * 8;
std::string s = formatData(pos, 64);
aesl_fh.write(AUTOTB_TVIN_testing_X, s);
}
}
}

  tcl_file.set_num(46526, &tcl_file.testing_X_depth);
aesl_fh.write(AUTOTB_TVIN_testing_X, end_str());
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
kNN_PredictAll_hw_stub_wrapper(__xlx_apatb_param_training_X_0, __xlx_apatb_param_training_X_1, __xlx_apatb_param_training_X_2, __xlx_apatb_param_training_X_3, __xlx_apatb_param_training_X_4, __xlx_apatb_param_training_X_5, __xlx_apatb_param_training_Y, __xlx_apatb_param_testing_X, __xlx_apatb_param_testing_Y, __xlx_apatb_param_min, __xlx_apatb_param_max);
CodeState = DUMP_OUTPUTS;
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
