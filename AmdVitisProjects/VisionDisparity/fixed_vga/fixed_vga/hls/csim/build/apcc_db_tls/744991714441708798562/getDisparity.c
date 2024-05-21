/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;
/* Structure forward decls */
typedef struct l_struct_OC_I2D l_struct_OC_I2D;
typedef struct l_struct_OC_F2D l_struct_OC_F2D;

/* Structure contents */
struct l_struct_OC_I2D {
  unsigned int field0;
  unsigned int field1;
  signed int field2[307200];
};

struct l_struct_OC_F2D {
  unsigned int field0;
  unsigned int field1;
  float field2[307200];
};


/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void outlined_fun_0(signed int *llvm_cbe_nr, l_struct_OC_I2D *llvm_cbe_Ileft, signed int *llvm_cbe_nc, signed int *llvm_cbe_half_win_sz, signed int *llvm_cbe_win_sz);
void outlined_fun_1(signed int *llvm_cbe_decomp_0, signed int *llvm_cbe_win_sz);
void outlined_fun_2(signed int *llvm_cbe_rows, l_struct_OC_I2D *llvm_cbe_IleftPadded, signed int *llvm_cbe_cols);
void outlined_fun_3(l_struct_OC_I2D *llvm_cbe_IleftPadded, l_struct_OC_I2D *llvm_cbe_Ileft, l_struct_OC_I2D *llvm_cbe_IrightPadded, l_struct_OC_I2D *llvm_cbe_Iright);
void outlined_loop_0(l_struct_OC_I2D *llvm_cbe_IleftPadded, l_struct_OC_I2D *llvm_cbe_IrightPadded, l_struct_OC_I2D *llvm_cbe_Iright_moved, signed int *llvm_cbe_win_sz, signed int *llvm_cbe_k, l_struct_OC_F2D *llvm_cbe_SAD, l_struct_OC_F2D *llvm_cbe_integralImg, l_struct_OC_F2D *llvm_cbe_retSAD, l_struct_OC_F2D *llvm_cbe_minSAD, l_struct_OC_I2D *llvm_cbe_retDisp, signed int *llvm_cbe_nr, signed int *llvm_cbe_nc);
void correlateSAD_2D(l_struct_OC_I2D *, l_struct_OC_I2D *, l_struct_OC_I2D *, signed int , signed int , l_struct_OC_F2D *, l_struct_OC_F2D *, l_struct_OC_F2D *);
void findDisparity(l_struct_OC_F2D *, l_struct_OC_F2D *, l_struct_OC_I2D *, signed int , signed int , signed int );
void getDisparity(l_struct_OC_I2D *llvm_cbe_Ileft, l_struct_OC_I2D *llvm_cbe_Iright, signed int llvm_cbe_win_sz, signed int llvm_cbe_max_shift, l_struct_OC_I2D **llvm_cbe_rtr_val);
void fSetArray_rep0(signed int , signed int , float , l_struct_OC_F2D **);
void iSetArray_rep0(signed int , signed int , signed int , l_struct_OC_I2D **);
void iSetArray_rep1(signed int , signed int , signed int , l_struct_OC_I2D **);
void padarray2_rep0(l_struct_OC_I2D *, l_struct_OC_I2D *, l_struct_OC_I2D **);
void padarray2_rep1(l_struct_OC_I2D *, l_struct_OC_I2D *, l_struct_OC_I2D **);
void fSetArray_rep1(signed int , signed int , float , l_struct_OC_F2D **);
void fSetArray_rep2(signed int , signed int , float , l_struct_OC_F2D **);
void fMallocHandle_rep0(signed int , signed int , l_struct_OC_F2D **);
void iSetArray_rep2(signed int , signed int , signed int , l_struct_OC_I2D **);
void fFreeHandle_rep0(l_struct_OC_F2D *);
void fFreeHandle_rep1(l_struct_OC_F2D *);
void fFreeHandle_rep2(l_struct_OC_F2D *);
void fFreeHandle_rep3(l_struct_OC_F2D *);
void iFreeHandle_rep0(l_struct_OC_I2D *);
void iFreeHandle_rep1(l_struct_OC_I2D *);
void iFreeHandle_rep2(l_struct_OC_I2D *);
void iFreeHandle_rep3(l_struct_OC_I2D *);


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

void outlined_fun_0(signed int *llvm_cbe_nr, l_struct_OC_I2D *llvm_cbe_Ileft, signed int *llvm_cbe_nc, signed int *llvm_cbe_half_win_sz, signed int *llvm_cbe_win_sz) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  signed int *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  signed int *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @outlined_fun_0\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.I2D* %%Ileft, i64 0, i32 1, !dbg !9 for 0x%llxth hint within @outlined_fun_0  --> \n", ++aesl_llvm_cbe_12_count);
  llvm_cbe_tmp__1 = (signed int *)(&llvm_cbe_Ileft->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !9 for 0x%llxth hint within @outlined_fun_0  --> \n", ++aesl_llvm_cbe_13_count);
  llvm_cbe_tmp__2 = (unsigned int )*llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%2, i32* %%nr, align 4, !dbg !9 for 0x%llxth hint within @outlined_fun_0  --> \n", ++aesl_llvm_cbe_14_count);
  *llvm_cbe_nr = llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.I2D* %%Ileft, i64 0, i32 0, !dbg !9 for 0x%llxth hint within @outlined_fun_0  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__3 = (signed int *)(&llvm_cbe_Ileft->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !9 for 0x%llxth hint within @outlined_fun_0  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__4 = (unsigned int )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%4, i32* %%nc, align 4, !dbg !9 for 0x%llxth hint within @outlined_fun_0  --> \n", ++aesl_llvm_cbe_17_count);
  *llvm_cbe_nc = llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%win_sz, align 4, !dbg !9 for 0x%llxth hint within @outlined_fun_0  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__5 = (unsigned int )*llvm_cbe_win_sz;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sdiv i32 %%5, 2, !dbg !9 for 0x%llxth hint within @outlined_fun_0  --> \n", ++aesl_llvm_cbe_19_count);
  llvm_cbe_tmp__6 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__5) / ((signed int )2u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__6));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%6, i32* %%half_win_sz, align 4, !dbg !9 for 0x%llxth hint within @outlined_fun_0  --> \n", ++aesl_llvm_cbe_20_count);
  *llvm_cbe_half_win_sz = llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @outlined_fun_0}\n");
  return;
}


void outlined_fun_1(signed int *llvm_cbe_decomp_0, signed int *llvm_cbe_win_sz) {
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @outlined_fun_1\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i32* %%win_sz, align 4, !dbg !9 for 0x%llxth hint within @outlined_fun_1  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__7 = (unsigned int )*llvm_cbe_win_sz;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i1 %%2 to i32, !dbg !9 for 0x%llxth hint within @outlined_fun_1  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__8 = (unsigned int )((unsigned int )(bool )(((signed int )llvm_cbe_tmp__7) > ((signed int )1u))&1U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%3, i32* %%decomp_0, align 4, !dbg !9 for 0x%llxth hint within @outlined_fun_1  --> \n", ++aesl_llvm_cbe_29_count);
  *llvm_cbe_decomp_0 = llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @outlined_fun_1}\n");
  return;
}


void outlined_fun_2(signed int *llvm_cbe_rows, l_struct_OC_I2D *llvm_cbe_IleftPadded, signed int *llvm_cbe_cols) {
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  signed int *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  signed int *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @outlined_fun_2\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.I2D* %%IleftPadded, i64 0, i32 1, !dbg !9 for 0x%llxth hint within @outlined_fun_2  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__9 = (signed int *)(&llvm_cbe_IleftPadded->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !9 for 0x%llxth hint within @outlined_fun_2  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__10 = (unsigned int )*llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%2, i32* %%rows, align 4, !dbg !9 for 0x%llxth hint within @outlined_fun_2  --> \n", ++aesl_llvm_cbe_40_count);
  *llvm_cbe_rows = llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.I2D* %%IleftPadded, i64 0, i32 0, !dbg !9 for 0x%llxth hint within @outlined_fun_2  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__11 = (signed int *)(&llvm_cbe_IleftPadded->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !9 for 0x%llxth hint within @outlined_fun_2  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__12 = (unsigned int )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%4, i32* %%cols, align 4, !dbg !9 for 0x%llxth hint within @outlined_fun_2  --> \n", ++aesl_llvm_cbe_43_count);
  *llvm_cbe_cols = llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__12);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @outlined_fun_2}\n");
  return;
}


void outlined_fun_3(l_struct_OC_I2D *llvm_cbe_IleftPadded, l_struct_OC_I2D *llvm_cbe_Ileft, l_struct_OC_I2D *llvm_cbe_IrightPadded, l_struct_OC_I2D *llvm_cbe_Iright) {
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @outlined_fun_3\n");
  if (AESL_DEBUG_TRACE)
      printf("\nEND @outlined_fun_3}\n");
  return;
}


void outlined_loop_0(l_struct_OC_I2D *llvm_cbe_IleftPadded, l_struct_OC_I2D *llvm_cbe_IrightPadded, l_struct_OC_I2D *llvm_cbe_Iright_moved, signed int *llvm_cbe_win_sz, signed int *llvm_cbe_k, l_struct_OC_F2D *llvm_cbe_SAD, l_struct_OC_F2D *llvm_cbe_integralImg, l_struct_OC_F2D *llvm_cbe_retSAD, l_struct_OC_F2D *llvm_cbe_minSAD, l_struct_OC_I2D *llvm_cbe_retDisp, signed int *llvm_cbe_nr, signed int *llvm_cbe_nc) {
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @outlined_loop_0\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i32* %%win_sz, align 4, !dbg !9 for 0x%llxth hint within @outlined_loop_0  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__13 = (unsigned int )*llvm_cbe_win_sz;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%k, align 4, !dbg !9 for 0x%llxth hint within @outlined_loop_0  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__14 = (unsigned int )*llvm_cbe_k;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @correlateSAD_2D(%%struct.I2D* %%IleftPadded, %%struct.I2D* %%IrightPadded, %%struct.I2D* %%Iright_moved, i32 %%1, i32 %%2, %%struct.F2D* %%SAD, %%struct.F2D* %%integralImg, %%struct.F2D* %%retSAD) nounwind, !dbg !9 for 0x%llxth hint within @outlined_loop_0  --> \n", ++aesl_llvm_cbe_80_count);
   /*tail*/ correlateSAD_2D((l_struct_OC_I2D *)llvm_cbe_IleftPadded, (l_struct_OC_I2D *)llvm_cbe_IrightPadded, (l_struct_OC_I2D *)llvm_cbe_Iright_moved, llvm_cbe_tmp__13, llvm_cbe_tmp__14, (l_struct_OC_F2D *)llvm_cbe_SAD, (l_struct_OC_F2D *)llvm_cbe_integralImg, (l_struct_OC_F2D *)llvm_cbe_retSAD);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__13);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__14);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i32* %%k, align 4, !dbg !10 for 0x%llxth hint within @outlined_loop_0  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__15 = (unsigned int )*llvm_cbe_k;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%nr, align 4, !dbg !10 for 0x%llxth hint within @outlined_loop_0  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__16 = (unsigned int )*llvm_cbe_nr;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%nc, align 4, !dbg !10 for 0x%llxth hint within @outlined_loop_0  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__17 = (unsigned int )*llvm_cbe_nc;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @findDisparity(%%struct.F2D* %%retSAD, %%struct.F2D* %%minSAD, %%struct.I2D* %%retDisp, i32 %%3, i32 %%4, i32 %%5) nounwind, !dbg !10 for 0x%llxth hint within @outlined_loop_0  --> \n", ++aesl_llvm_cbe_84_count);
   /*tail*/ findDisparity((l_struct_OC_F2D *)llvm_cbe_retSAD, (l_struct_OC_F2D *)llvm_cbe_minSAD, (l_struct_OC_I2D *)llvm_cbe_retDisp, llvm_cbe_tmp__15, llvm_cbe_tmp__16, llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__15);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__16);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__17);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @outlined_loop_0}\n");
  return;
}


void getDisparity(l_struct_OC_I2D *llvm_cbe_Ileft, l_struct_OC_I2D *llvm_cbe_Iright, signed int llvm_cbe_win_sz, signed int llvm_cbe_max_shift, l_struct_OC_I2D **llvm_cbe_rtr_val) {
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  signed int llvm_cbe_tmp__18;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_Iright_moved_count = 0;
  l_struct_OC_I2D *llvm_cbe_Iright_moved;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_IleftPadded_count = 0;
  l_struct_OC_I2D *llvm_cbe_IleftPadded;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_IrightPadded_count = 0;
  l_struct_OC_I2D *llvm_cbe_IrightPadded;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_integralImg_count = 0;
  l_struct_OC_F2D *llvm_cbe_integralImg;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_SAD_count = 0;
  l_struct_OC_F2D *llvm_cbe_SAD;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_minSAD_count = 0;
  l_struct_OC_F2D *llvm_cbe_minSAD;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_retSAD_count = 0;
  l_struct_OC_F2D *llvm_cbe_retSAD;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_cols_count = 0;
  signed int llvm_cbe_cols;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_rows_count = 0;
  signed int llvm_cbe_rows;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_half_win_sz_count = 0;
  signed int llvm_cbe_half_win_sz;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_halfWin_count = 0;
  l_struct_OC_I2D *llvm_cbe_halfWin;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_k_count = 0;
  signed int llvm_cbe_k;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_nc_count = 0;
  signed int llvm_cbe_nc;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_nr_count = 0;
  signed int llvm_cbe_nr;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_retDisp_count = 0;
  l_struct_OC_I2D *llvm_cbe_retDisp;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_decomp_0_count = 0;
  signed int llvm_cbe_decomp_0;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @getDisparity\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%win_sz, i32* %%1, align  for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_104_count);
  *(&llvm_cbe_tmp__18) = llvm_cbe_win_sz;
if (AESL_DEBUG_TRACE)
printf("\nwin_sz = 0x%X\n", llvm_cbe_win_sz);
if (AESL_DEBUG_TRACE)
printf("\n  call void @outlined_fun_0(i32* %%nr, %%struct.I2D* %%Ileft, i32* %%nc, i32* %%half_win_sz, i32* %%1), !dbg !9 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_126_count);
  outlined_fun_0((signed int *)(&llvm_cbe_nr), (l_struct_OC_I2D *)llvm_cbe_Ileft, (signed int *)(&llvm_cbe_nc), (signed int *)(&llvm_cbe_half_win_sz), (signed int *)(&llvm_cbe_tmp__18));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%nr, align 4, !dbg !13 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_133_count);
  llvm_cbe_tmp__19 = (unsigned int )*(&llvm_cbe_nr);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i32* %%nc, align 4, !dbg !13 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__20 = (unsigned int )*(&llvm_cbe_nc);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  call void @fSetArray_rep0(i32 %%2, i32 %%3, float 6.502500e+04, %%struct.F2D** %%minSAD) nounwind, !dbg !13 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_141_count);
  fSetArray_rep0(llvm_cbe_tmp__19, llvm_cbe_tmp__20, 0x1.fc02p15, (l_struct_OC_F2D **)(&llvm_cbe_minSAD));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__19);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__20);
printf("\nArgument  = %f",0x1.fc02p15);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%nr, align 4, !dbg !10 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_148_count);
  llvm_cbe_tmp__21 = (unsigned int )*(&llvm_cbe_nr);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%nc, align 4, !dbg !10 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__22 = (unsigned int )*(&llvm_cbe_nc);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  call void @iSetArray_rep0(i32 %%4, i32 %%5, i32 %%max_shift, %%struct.I2D** %%retDisp) nounwind, !dbg !10 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_156_count);
  iSetArray_rep0(llvm_cbe_tmp__21, llvm_cbe_tmp__22, llvm_cbe_max_shift, (l_struct_OC_I2D **)(&llvm_cbe_retDisp));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__21);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__22);
printf("\nArgument max_shift = 0x%X",llvm_cbe_max_shift);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i32* %%half_win_sz, align 4, !dbg !14 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__23 = (unsigned int )*(&llvm_cbe_half_win_sz);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  call void @iSetArray_rep1(i32 1, i32 2, i32 %%6, %%struct.I2D** %%halfWin) nounwind, !dbg !14 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_164_count);
  iSetArray_rep1(1u, 2u, llvm_cbe_tmp__23, (l_struct_OC_I2D **)(&llvm_cbe_halfWin));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
printf("\nArgument  = 0x%X",2u);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__23);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @outlined_fun_1(i32* %%decomp_0, i32* %%1), !dbg !14 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_166_count);
  outlined_fun_1((signed int *)(&llvm_cbe_decomp_0), (signed int *)(&llvm_cbe_tmp__18));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i32* %%decomp_0, align 4, !dbg !14 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_173_count);
  llvm_cbe_tmp__24 = (unsigned int )*(&llvm_cbe_decomp_0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__24);
  if (((llvm_cbe_tmp__24&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__55;
  } else {
    goto llvm_cbe_tmp__56;
  }

llvm_cbe_tmp__56:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load %%struct.I2D** %%halfWin, align 8, !dbg !9 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__25 = (l_struct_OC_I2D *)*(&llvm_cbe_halfWin);
if (AESL_DEBUG_TRACE)
printf("\n  call void @padarray2_rep0(%%struct.I2D* %%Ileft, %%struct.I2D* %%10, %%struct.I2D** %%IleftPadded) nounwind, !dbg !9 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_183_count);
  padarray2_rep0((l_struct_OC_I2D *)llvm_cbe_Ileft, (l_struct_OC_I2D *)llvm_cbe_tmp__25, (l_struct_OC_I2D **)(&llvm_cbe_IleftPadded));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load %%struct.I2D** %%halfWin, align 8, !dbg !10 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_190_count);
  llvm_cbe_tmp__26 = (l_struct_OC_I2D *)*(&llvm_cbe_halfWin);
if (AESL_DEBUG_TRACE)
printf("\n  call void @padarray2_rep1(%%struct.I2D* %%Iright, %%struct.I2D* %%11, %%struct.I2D** %%IrightPadded) nounwind, !dbg !10 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_191_count);
  padarray2_rep1((l_struct_OC_I2D *)llvm_cbe_Iright, (l_struct_OC_I2D *)llvm_cbe_tmp__26, (l_struct_OC_I2D **)(&llvm_cbe_IrightPadded));
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe_tmp__55;

llvm_cbe_tmp__55:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load %%struct.I2D** %%IleftPadded, align 8, !dbg !14 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_199_count);
  llvm_cbe_tmp__27 = (l_struct_OC_I2D *)*(&llvm_cbe_IleftPadded);
if (AESL_DEBUG_TRACE)
printf("\n  call void @outlined_fun_2(i32* %%rows, %%struct.I2D* %%13, i32* %%cols), !dbg !14 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_200_count);
  outlined_fun_2((signed int *)(&llvm_cbe_rows), (l_struct_OC_I2D *)llvm_cbe_tmp__27, (signed int *)(&llvm_cbe_cols));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%rows, align 4, !dbg !14 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_207_count);
  llvm_cbe_tmp__28 = (unsigned int )*(&llvm_cbe_rows);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* %%cols, align 4, !dbg !14 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__29 = (unsigned int )*(&llvm_cbe_cols);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  call void @fSetArray_rep1(i32 %%14, i32 %%15, float 2.550000e+02, %%struct.F2D** %%SAD) nounwind, !dbg !14 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_215_count);
  fSetArray_rep1(llvm_cbe_tmp__28, llvm_cbe_tmp__29, 0x1.fep7, (l_struct_OC_F2D **)(&llvm_cbe_SAD));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__28);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__29);
printf("\nArgument  = %f",0x1.fep7);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i32* %%cols, align 4, !dbg !14 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_225_count);
  llvm_cbe_tmp__30 = (unsigned int )*(&llvm_cbe_cols);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  call void @fSetArray_rep2(i32 %%14, i32 %%16, float 0.000000e+00, %%struct.F2D** %%integralImg) nounwind, !dbg !14 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_226_count);
  fSetArray_rep2(llvm_cbe_tmp__28, llvm_cbe_tmp__30, 0x0p0, (l_struct_OC_F2D **)(&llvm_cbe_integralImg));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__28);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__30);
printf("\nArgument  = %f",0x0p0);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i32* %%1, align 4, !dbg !14 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_236_count);
  llvm_cbe_tmp__31 = (unsigned int )*(&llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = sub nsw i32 %%14, %%17, !dbg !14 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_237_count);
  llvm_cbe_tmp__32 = (unsigned int )((unsigned int )(llvm_cbe_tmp__28&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__31&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__32&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i32* %%cols, align 4, !dbg !14 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_244_count);
  llvm_cbe_tmp__33 = (unsigned int )*(&llvm_cbe_cols);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = sub nsw i32 %%19, %%17, !dbg !14 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__34 = (unsigned int )((unsigned int )(llvm_cbe_tmp__33&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__31&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__34&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  call void @fMallocHandle_rep0(i32 %%18, i32 %%20, %%struct.F2D** %%retSAD) nounwind, !dbg !14 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_247_count);
  fMallocHandle_rep0(llvm_cbe_tmp__32, llvm_cbe_tmp__34, (l_struct_OC_F2D **)(&llvm_cbe_retSAD));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__32);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__34);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i32* %%cols, align 4, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_257_count);
  llvm_cbe_tmp__35 = (unsigned int )*(&llvm_cbe_cols);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  call void @iSetArray_rep2(i32 %%14, i32 %%21, i32 0, %%struct.I2D** %%Iright_moved) nounwind, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_258_count);
  iSetArray_rep2(llvm_cbe_tmp__28, llvm_cbe_tmp__35, 0u, (l_struct_OC_I2D **)(&llvm_cbe_Iright_moved));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__28);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__35);
printf("\nArgument  = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%k, align 4, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_265_count);
  *(&llvm_cbe_k) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  if ((((signed int )llvm_cbe_max_shift) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load %%struct.I2D** %%IleftPadded, align 8, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_274_count);
  llvm_cbe_tmp__36 = (l_struct_OC_I2D *)*(&llvm_cbe_IleftPadded);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load %%struct.I2D** %%IrightPadded, align 8, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_281_count);
  llvm_cbe_tmp__37 = (l_struct_OC_I2D *)*(&llvm_cbe_IrightPadded);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load %%struct.I2D** %%Iright_moved, align 8, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_288_count);
  llvm_cbe_tmp__38 = (l_struct_OC_I2D *)*(&llvm_cbe_Iright_moved);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load %%struct.F2D** %%SAD, align 8, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_295_count);
  llvm_cbe_tmp__39 = (l_struct_OC_F2D *)*(&llvm_cbe_SAD);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load %%struct.F2D** %%integralImg, align 8, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_302_count);
  llvm_cbe_tmp__40 = (l_struct_OC_F2D *)*(&llvm_cbe_integralImg);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load %%struct.F2D** %%retSAD, align 8, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_309_count);
  llvm_cbe_tmp__41 = (l_struct_OC_F2D *)*(&llvm_cbe_retSAD);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load %%struct.F2D** %%minSAD, align 8, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_316_count);
  llvm_cbe_tmp__42 = (l_struct_OC_F2D *)*(&llvm_cbe_minSAD);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load %%struct.I2D** %%retDisp, align 8, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_323_count);
  llvm_cbe_tmp__43 = (l_struct_OC_I2D *)*(&llvm_cbe_retDisp);
if (AESL_DEBUG_TRACE)
printf("\n  call void @outlined_loop_0(%%struct.I2D* %%23, %%struct.I2D* %%24, %%struct.I2D* %%25, i32* %%1, i32* %%k, %%struct.F2D* %%26, %%struct.F2D* %%27, %%struct.F2D* %%28, %%struct.F2D* %%29, %%struct.I2D* %%30, i32* %%nr, i32* %%nc), !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_324_count);
  outlined_loop_0((l_struct_OC_I2D *)llvm_cbe_tmp__36, (l_struct_OC_I2D *)llvm_cbe_tmp__37, (l_struct_OC_I2D *)llvm_cbe_tmp__38, (signed int *)(&llvm_cbe_tmp__18), (signed int *)(&llvm_cbe_k), (l_struct_OC_F2D *)llvm_cbe_tmp__39, (l_struct_OC_F2D *)llvm_cbe_tmp__40, (l_struct_OC_F2D *)llvm_cbe_tmp__41, (l_struct_OC_F2D *)llvm_cbe_tmp__42, (l_struct_OC_I2D *)llvm_cbe_tmp__43, (signed int *)(&llvm_cbe_nr), (signed int *)(&llvm_cbe_nc));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i32* %%k, align 4, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_331_count);
  llvm_cbe_tmp__44 = (unsigned int )*(&llvm_cbe_k);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add nsw i32 %%31, 1, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_332_count);
  llvm_cbe_tmp__45 = (unsigned int )((unsigned int )(llvm_cbe_tmp__44&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__45&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%32, i32* %%k, align 4, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_339_count);
  *(&llvm_cbe_k) = llvm_cbe_tmp__45;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__45);
  if ((((signed int )llvm_cbe_tmp__45) < ((signed int )llvm_cbe_max_shift))) {
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load %%struct.F2D** %%retSAD, align 8, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_349_count);
  llvm_cbe_tmp__46 = (l_struct_OC_F2D *)*(&llvm_cbe_retSAD);
if (AESL_DEBUG_TRACE)
printf("\n  call void @fFreeHandle_rep0(%%struct.F2D* %%34) nounwind, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_350_count);
  fFreeHandle_rep0((l_struct_OC_F2D *)llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load %%struct.F2D** %%minSAD, align 8, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_357_count);
  llvm_cbe_tmp__47 = (l_struct_OC_F2D *)*(&llvm_cbe_minSAD);
if (AESL_DEBUG_TRACE)
printf("\n  call void @fFreeHandle_rep1(%%struct.F2D* %%35) nounwind, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_358_count);
  fFreeHandle_rep1((l_struct_OC_F2D *)llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load %%struct.F2D** %%SAD, align 8, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_365_count);
  llvm_cbe_tmp__48 = (l_struct_OC_F2D *)*(&llvm_cbe_SAD);
if (AESL_DEBUG_TRACE)
printf("\n  call void @fFreeHandle_rep2(%%struct.F2D* %%36) nounwind, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_366_count);
  fFreeHandle_rep2((l_struct_OC_F2D *)llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load %%struct.F2D** %%integralImg, align 8, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_373_count);
  llvm_cbe_tmp__49 = (l_struct_OC_F2D *)*(&llvm_cbe_integralImg);
if (AESL_DEBUG_TRACE)
printf("\n  call void @fFreeHandle_rep3(%%struct.F2D* %%37) nounwind, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_374_count);
  fFreeHandle_rep3((l_struct_OC_F2D *)llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load %%struct.I2D** %%halfWin, align 8, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_381_count);
  llvm_cbe_tmp__50 = (l_struct_OC_I2D *)*(&llvm_cbe_halfWin);
if (AESL_DEBUG_TRACE)
printf("\n  call void @iFreeHandle_rep0(%%struct.I2D* %%38) nounwind, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_382_count);
  iFreeHandle_rep0((l_struct_OC_I2D *)llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load %%struct.I2D** %%IrightPadded, align 8, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_389_count);
  llvm_cbe_tmp__51 = (l_struct_OC_I2D *)*(&llvm_cbe_IrightPadded);
if (AESL_DEBUG_TRACE)
printf("\n  call void @iFreeHandle_rep1(%%struct.I2D* %%39) nounwind, !dbg !15 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_390_count);
  iFreeHandle_rep1((l_struct_OC_I2D *)llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load %%struct.I2D** %%IleftPadded, align 8, !dbg !16 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_397_count);
  llvm_cbe_tmp__52 = (l_struct_OC_I2D *)*(&llvm_cbe_IleftPadded);
if (AESL_DEBUG_TRACE)
printf("\n  call void @iFreeHandle_rep2(%%struct.I2D* %%40) nounwind, !dbg !16 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_398_count);
  iFreeHandle_rep2((l_struct_OC_I2D *)llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = load %%struct.I2D** %%Iright_moved, align 8, !dbg !16 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_405_count);
  llvm_cbe_tmp__53 = (l_struct_OC_I2D *)*(&llvm_cbe_Iright_moved);
if (AESL_DEBUG_TRACE)
printf("\n  call void @iFreeHandle_rep3(%%struct.I2D* %%41) nounwind, !dbg !16 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_406_count);
  iFreeHandle_rep3((l_struct_OC_I2D *)llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load %%struct.I2D** %%retDisp, align 8, !dbg !11 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_413_count);
  llvm_cbe_tmp__54 = (l_struct_OC_I2D *)*(&llvm_cbe_retDisp);
if (AESL_DEBUG_TRACE)
printf("\n  store %%struct.I2D* %%42, %%struct.I2D** %%rtr_val, align 8, !dbg !11 for 0x%llxth hint within @getDisparity  --> \n", ++aesl_llvm_cbe_414_count);
  *llvm_cbe_rtr_val = (l_struct_OC_I2D *)llvm_cbe_tmp__54;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @getDisparity}\n");
  return;
}

