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
typedef struct l_struct_OC_F2D l_struct_OC_F2D;

/* Structure contents */
struct l_struct_OC_F2D {
  unsigned int field0;
  unsigned int field1;
  float field2[307200];
};


/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void outlined_fun_5(l_struct_OC_F2D *llvm_cbe_out, signed int *llvm_cbe_rows, signed int *llvm_cbe_cols, l_struct_OC_F2D **llvm_cbe_rtr_val);
void fMallocHandle(signed int llvm_cbe_rows, signed int llvm_cbe_cols, l_struct_OC_F2D **llvm_cbe_rtr_val);
void fMallocHandle_rep1(signed int llvm_cbe_rows, signed int llvm_cbe_cols, l_struct_OC_F2D **llvm_cbe_rtr_val);
void outlined_fun_16(l_struct_OC_F2D *llvm_cbe_out, signed int *llvm_cbe_rows, signed int *llvm_cbe_cols, l_struct_OC_F2D **llvm_cbe_rtr_val);
void fMallocHandle_rep0(signed int llvm_cbe_rows, signed int llvm_cbe_cols, l_struct_OC_F2D **llvm_cbe_rtr_val);


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

void outlined_fun_5(l_struct_OC_F2D *llvm_cbe_out, signed int *llvm_cbe_rows, signed int *llvm_cbe_cols, l_struct_OC_F2D **llvm_cbe_rtr_val) {
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
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  signed int *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  signed int *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @outlined_fun_5\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i32* %%rows, align 4, !dbg !5 for 0x%llxth hint within @outlined_fun_5  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__1 = (unsigned int )*llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.F2D* %%out, i64 0, i32 1, !dbg !5 for 0x%llxth hint within @outlined_fun_5  --> \n", ++aesl_llvm_cbe_12_count);
  llvm_cbe_tmp__2 = (signed int *)(&llvm_cbe_out->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%1, i32* %%2, align 4, !dbg !5 for 0x%llxth hint within @outlined_fun_5  --> \n", ++aesl_llvm_cbe_13_count);
  *llvm_cbe_tmp__2 = llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i32* %%cols, align 4, !dbg !5 for 0x%llxth hint within @outlined_fun_5  --> \n", ++aesl_llvm_cbe_14_count);
  llvm_cbe_tmp__3 = (unsigned int )*llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.F2D* %%out, i64 0, i32 0, !dbg !5 for 0x%llxth hint within @outlined_fun_5  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__4 = (signed int *)(&llvm_cbe_out->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%3, i32* %%4, align 4, !dbg !5 for 0x%llxth hint within @outlined_fun_5  --> \n", ++aesl_llvm_cbe_16_count);
  *llvm_cbe_tmp__4 = llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  store %%struct.F2D* %%out, %%struct.F2D** %%rtr_val, align 8, !dbg !5 for 0x%llxth hint within @outlined_fun_5  --> \n", ++aesl_llvm_cbe_17_count);
  *llvm_cbe_rtr_val = (l_struct_OC_F2D *)llvm_cbe_out;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @outlined_fun_5}\n");
  return;
}


void fMallocHandle(signed int llvm_cbe_rows, signed int llvm_cbe_cols, l_struct_OC_F2D **llvm_cbe_rtr_val) {
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  signed int llvm_cbe_tmp__5;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  signed int llvm_cbe_tmp__6;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  unsigned long long llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
   char *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @fMallocHandle\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%rows, i32* %%1, align  for 0x%llxth hint within @fMallocHandle  --> \n", ++aesl_llvm_cbe_27_count);
  *(&llvm_cbe_tmp__5) = llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\nrows = 0x%X\n", llvm_cbe_rows);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%cols, i32* %%2, align  for 0x%llxth hint within @fMallocHandle  --> \n", ++aesl_llvm_cbe_35_count);
  *(&llvm_cbe_tmp__6) = llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\ncols = 0x%X\n", llvm_cbe_cols);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%rows to i64, !dbg !6 for 0x%llxth hint within @fMallocHandle  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__7 = (unsigned long long )((signed long long )(signed int )llvm_cbe_rows);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = shl nsw i64 %%3, 2, !dbg !6 for 0x%llxth hint within @fMallocHandle  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__8 = (unsigned long long )llvm_cbe_tmp__7 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sext i32 %%cols to i64, !dbg !6 for 0x%llxth hint within @fMallocHandle  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__9 = (unsigned long long )((signed long long )(signed int )llvm_cbe_cols);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = mul i64 %%4, %%5, !dbg !6 for 0x%llxth hint within @fMallocHandle  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__10 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__8&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__9&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", ((unsigned long long )(llvm_cbe_tmp__10&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i64 %%6, 1228808, !dbg !6 for 0x%llxth hint within @fMallocHandle  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__11 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__10&18446744073709551615ull)) + ((unsigned long long )(1228808ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", ((unsigned long long )(llvm_cbe_tmp__11&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call noalias i8* @malloc(i64 %%7) nounwind, !dbg !6 for 0x%llxth hint within @fMallocHandle  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__12 = ( char *)( char *)malloc(llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",llvm_cbe_tmp__11);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = bitcast i8* %%8 to %%struct.F2D*, !dbg !6 for 0x%llxth hint within @fMallocHandle  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__13 = (l_struct_OC_F2D *)((l_struct_OC_F2D *)llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  call void @outlined_fun_5(%%struct.F2D* %%9, i32* %%1, i32* %%2, %%struct.F2D** %%rtr_val), !dbg !5 for 0x%llxth hint within @fMallocHandle  --> \n", ++aesl_llvm_cbe_50_count);
  outlined_fun_5((l_struct_OC_F2D *)llvm_cbe_tmp__13, (signed int *)(&llvm_cbe_tmp__5), (signed int *)(&llvm_cbe_tmp__6), (l_struct_OC_F2D **)llvm_cbe_rtr_val);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @fMallocHandle}\n");
  return;
}


void fMallocHandle_rep1(signed int llvm_cbe_rows, signed int llvm_cbe_cols, l_struct_OC_F2D **llvm_cbe_rtr_val) {
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  unsigned long long llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  unsigned long long llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned long long llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  unsigned long long llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
   char *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  signed int *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  signed int *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @fMallocHandle_rep1\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = sext i32 %%rows to i64, !dbg !5 for 0x%llxth hint within @fMallocHandle_rep1  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__14 = (unsigned long long )((signed long long )(signed int )llvm_cbe_rows);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = shl nsw i64 %%1, 2, !dbg !5 for 0x%llxth hint within @fMallocHandle_rep1  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__15 = (unsigned long long )llvm_cbe_tmp__14 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%cols to i64, !dbg !5 for 0x%llxth hint within @fMallocHandle_rep1  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__16 = (unsigned long long )((signed long long )(signed int )llvm_cbe_cols);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = mul i64 %%2, %%3, !dbg !5 for 0x%llxth hint within @fMallocHandle_rep1  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__17 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__15&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__16&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", ((unsigned long long )(llvm_cbe_tmp__17&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add i64 %%4, 1228808, !dbg !5 for 0x%llxth hint within @fMallocHandle_rep1  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__18 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__17&18446744073709551615ull)) + ((unsigned long long )(1228808ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", ((unsigned long long )(llvm_cbe_tmp__18&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = tail call noalias i8* @malloc(i64 %%5) nounwind, !dbg !5 for 0x%llxth hint within @fMallocHandle_rep1  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__19 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",llvm_cbe_tmp__18);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__19);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = bitcast i8* %%6 to %%struct.F2D*, !dbg !5 for 0x%llxth hint within @fMallocHandle_rep1  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__20 = (l_struct_OC_F2D *)((l_struct_OC_F2D *)llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.F2D* %%7, i64 0, i32 1, !dbg !5 for 0x%llxth hint within @fMallocHandle_rep1  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__21 = (signed int *)(&llvm_cbe_tmp__20->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%rows, i32* %%8, align 4, !dbg !5 for 0x%llxth hint within @fMallocHandle_rep1  --> \n", ++aesl_llvm_cbe_72_count);
  *llvm_cbe_tmp__21 = llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\nrows = 0x%X\n", llvm_cbe_rows);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = bitcast i8* %%6 to i32*, !dbg !5 for 0x%llxth hint within @fMallocHandle_rep1  --> \n", ++aesl_llvm_cbe_73_count);
  llvm_cbe_tmp__22 = (signed int *)((signed int *)llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%cols, i32* %%9, align 4, !dbg !5 for 0x%llxth hint within @fMallocHandle_rep1  --> \n", ++aesl_llvm_cbe_74_count);
  *llvm_cbe_tmp__22 = llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\ncols = 0x%X\n", llvm_cbe_cols);
if (AESL_DEBUG_TRACE)
printf("\n  store %%struct.F2D* %%7, %%struct.F2D** %%rtr_val, align 8, !dbg !6 for 0x%llxth hint within @fMallocHandle_rep1  --> \n", ++aesl_llvm_cbe_75_count);
  *llvm_cbe_rtr_val = (l_struct_OC_F2D *)llvm_cbe_tmp__20;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @fMallocHandle_rep1}\n");
  return;
}


void outlined_fun_16(l_struct_OC_F2D *llvm_cbe_out, signed int *llvm_cbe_rows, signed int *llvm_cbe_cols, l_struct_OC_F2D **llvm_cbe_rtr_val) {
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  signed int *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  signed int *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @outlined_fun_16\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i32* %%rows, align 4, !dbg !5 for 0x%llxth hint within @outlined_fun_16  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__23 = (unsigned int )*llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.F2D* %%out, i64 0, i32 1, !dbg !5 for 0x%llxth hint within @outlined_fun_16  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__24 = (signed int *)(&llvm_cbe_out->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%1, i32* %%2, align 4, !dbg !5 for 0x%llxth hint within @outlined_fun_16  --> \n", ++aesl_llvm_cbe_89_count);
  *llvm_cbe_tmp__24 = llvm_cbe_tmp__23;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i32* %%cols, align 4, !dbg !5 for 0x%llxth hint within @outlined_fun_16  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__25 = (unsigned int )*llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.F2D* %%out, i64 0, i32 0, !dbg !5 for 0x%llxth hint within @outlined_fun_16  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__26 = (signed int *)(&llvm_cbe_out->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%3, i32* %%4, align 4, !dbg !5 for 0x%llxth hint within @outlined_fun_16  --> \n", ++aesl_llvm_cbe_92_count);
  *llvm_cbe_tmp__26 = llvm_cbe_tmp__25;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  store %%struct.F2D* %%out, %%struct.F2D** %%rtr_val, align 8, !dbg !5 for 0x%llxth hint within @outlined_fun_16  --> \n", ++aesl_llvm_cbe_93_count);
  *llvm_cbe_rtr_val = (l_struct_OC_F2D *)llvm_cbe_out;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @outlined_fun_16}\n");
  return;
}


void fMallocHandle_rep0(signed int llvm_cbe_rows, signed int llvm_cbe_cols, l_struct_OC_F2D **llvm_cbe_rtr_val) {
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  signed int llvm_cbe_tmp__27;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  signed int llvm_cbe_tmp__28;    /* Address-exposed local */
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
  unsigned long long llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned long long llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  unsigned long long llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  unsigned long long llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned long long llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
   char *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @fMallocHandle_rep0\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%rows, i32* %%1, align  for 0x%llxth hint within @fMallocHandle_rep0  --> \n", ++aesl_llvm_cbe_103_count);
  *(&llvm_cbe_tmp__27) = llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\nrows = 0x%X\n", llvm_cbe_rows);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%cols, i32* %%2, align  for 0x%llxth hint within @fMallocHandle_rep0  --> \n", ++aesl_llvm_cbe_111_count);
  *(&llvm_cbe_tmp__28) = llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\ncols = 0x%X\n", llvm_cbe_cols);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%rows to i64, !dbg !6 for 0x%llxth hint within @fMallocHandle_rep0  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__29 = (unsigned long long )((signed long long )(signed int )llvm_cbe_rows);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = shl nsw i64 %%3, 2, !dbg !6 for 0x%llxth hint within @fMallocHandle_rep0  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__30 = (unsigned long long )llvm_cbe_tmp__29 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sext i32 %%cols to i64, !dbg !6 for 0x%llxth hint within @fMallocHandle_rep0  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__31 = (unsigned long long )((signed long long )(signed int )llvm_cbe_cols);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = mul i64 %%4, %%5, !dbg !6 for 0x%llxth hint within @fMallocHandle_rep0  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__32 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__30&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__31&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", ((unsigned long long )(llvm_cbe_tmp__32&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i64 %%6, 1228808, !dbg !6 for 0x%llxth hint within @fMallocHandle_rep0  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__33 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__32&18446744073709551615ull)) + ((unsigned long long )(1228808ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", ((unsigned long long )(llvm_cbe_tmp__33&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call noalias i8* @malloc(i64 %%7) nounwind, !dbg !6 for 0x%llxth hint within @fMallocHandle_rep0  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__34 = ( char *)( char *)malloc(llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",llvm_cbe_tmp__33);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__34);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = bitcast i8* %%8 to %%struct.F2D*, !dbg !6 for 0x%llxth hint within @fMallocHandle_rep0  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__35 = (l_struct_OC_F2D *)((l_struct_OC_F2D *)llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  call void @outlined_fun_16(%%struct.F2D* %%9, i32* %%1, i32* %%2, %%struct.F2D** %%rtr_val), !dbg !5 for 0x%llxth hint within @fMallocHandle_rep0  --> \n", ++aesl_llvm_cbe_126_count);
  outlined_fun_16((l_struct_OC_F2D *)llvm_cbe_tmp__35, (signed int *)(&llvm_cbe_tmp__27), (signed int *)(&llvm_cbe_tmp__28), (l_struct_OC_F2D **)llvm_cbe_rtr_val);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @fMallocHandle_rep0}\n");
  return;
}

