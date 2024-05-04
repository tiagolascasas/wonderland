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
void fSetArray(signed int llvm_cbe_rows, signed int llvm_cbe_cols, float llvm_cbe_val, l_struct_OC_F2D **llvm_cbe_rtr_val);
void fMallocHandle_rep1(signed int , signed int , l_struct_OC_F2D **);
void outlined_fun_15(signed int *llvm_cbe_i, signed int *llvm_cbe_rows, signed int *llvm_cbe_j, signed int *llvm_cbe_cols, l_struct_OC_F2D *llvm_cbe_out, float *llvm_cbe_val, l_struct_OC_F2D **llvm_cbe_rtr_val);
void fSetArray_rep2(signed int llvm_cbe_rows, signed int llvm_cbe_cols, float llvm_cbe_val, l_struct_OC_F2D **llvm_cbe_rtr_val);
void fMallocHandle(signed int , signed int , l_struct_OC_F2D **);
void outlined_fun_14(signed int *llvm_cbe_i, signed int *llvm_cbe_rows, signed int *llvm_cbe_j, signed int *llvm_cbe_cols, l_struct_OC_F2D *llvm_cbe_out, float *llvm_cbe_val, l_struct_OC_F2D **llvm_cbe_rtr_val);
void fSetArray_rep1(signed int llvm_cbe_rows, signed int llvm_cbe_cols, float llvm_cbe_val, l_struct_OC_F2D **llvm_cbe_rtr_val);
void outlined_fun_4(signed int *llvm_cbe_i, signed int *llvm_cbe_rows, signed int *llvm_cbe_j, signed int *llvm_cbe_cols, l_struct_OC_F2D *llvm_cbe_out, float *llvm_cbe_val, l_struct_OC_F2D **llvm_cbe_rtr_val);
void fSetArray_rep0(signed int llvm_cbe_rows, signed int llvm_cbe_cols, float llvm_cbe_val, l_struct_OC_F2D **llvm_cbe_rtr_val);


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

void fSetArray(signed int llvm_cbe_rows, signed int llvm_cbe_cols, float llvm_cbe_val, l_struct_OC_F2D **llvm_cbe_rtr_val) {
  static  unsigned long long aesl_llvm_cbe_out_count = 0;
  l_struct_OC_F2D *llvm_cbe_out;    /* Address-exposed local */
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
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond6_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge12_2e_us;
  unsigned int llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  signed int *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  float *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge3_2e_us;
  unsigned int llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @fSetArray\n");
if (AESL_DEBUG_TRACE)
printf("\n  call void @fMallocHandle_rep1(i32 %%rows, i32 %%cols, %%struct.F2D** %%out) nounwind, !dbg !5 for 0x%llxth hint within @fSetArray  --> \n", ++aesl_llvm_cbe_12_count);
  fMallocHandle_rep1(llvm_cbe_rows, llvm_cbe_cols, (l_struct_OC_F2D **)(&llvm_cbe_out));
if (AESL_DEBUG_TRACE) {
printf("\nArgument rows = 0x%X",llvm_cbe_rows);
printf("\nArgument cols = 0x%X",llvm_cbe_cols);
}
  if ((((signed int )llvm_cbe_rows) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe_tmp__11;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
  if ((((signed int )llvm_cbe_cols) > ((signed int )0u))) {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge5;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3.us = phi i32 [ %%4, %%3 ], [ 0, %%.preheader.lr.ph  for 0x%llxth hint within @fSetArray  --> \n", ++aesl_llvm_cbe_storemerge3_2e_us_count);
  llvm_cbe_storemerge3_2e_us = (unsigned int )llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3.us = 0x%X",llvm_cbe_storemerge3_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__1);
printf("\n = 0x%X",0u);
}
  llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__12;

llvm_cbe_tmp__13:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add nsw i32 %%storemerge3.us, 1, !dbg !7 for 0x%llxth hint within @fSetArray  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__1 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__1&4294967295ull)));
  if (((llvm_cbe_tmp__1&4294967295U) == (llvm_cbe_rows&4294967295U))) {
    goto llvm_cbe__2e__crit_edge5;
  } else {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__1;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__12:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.us = phi i32 [ 0, %%.lr.ph.us ], [ %%13, %%5  for 0x%llxth hint within @fSetArray  --> \n", ++aesl_llvm_cbe_storemerge12_2e_us_count);
  llvm_cbe_storemerge12_2e_us = (unsigned int )llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us = 0x%X",llvm_cbe_storemerge12_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load %%struct.F2D** %%out, align 8, !dbg !7 for 0x%llxth hint within @fSetArray  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__2 = (l_struct_OC_F2D *)*(&llvm_cbe_out);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.F2D* %%6, i64 0, i32 0, !dbg !7 for 0x%llxth hint within @fSetArray  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__3 = (signed int *)(&llvm_cbe_tmp__2->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%7, align 4, !dbg !7 for 0x%llxth hint within @fSetArray  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__4 = (unsigned int )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul nsw i32 %%8, %%storemerge3.us, !dbg !7 for 0x%llxth hint within @fSetArray  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__5 = (unsigned int )((unsigned int )(llvm_cbe_tmp__4&4294967295ull)) * ((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__5&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%9, %%storemerge12.us, !dbg !7 for 0x%llxth hint within @fSetArray  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__6 = (unsigned int )((unsigned int )(llvm_cbe_tmp__5&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__6&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%10 to i64, !dbg !7 for 0x%llxth hint within @fSetArray  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__7 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.F2D* %%6, i64 0, i32 2, i64 %%11, !dbg !7 for 0x%llxth hint within @fSetArray  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__8 = (float *)(&llvm_cbe_tmp__2->field2[(((signed long long )llvm_cbe_tmp__7))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__7));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%val, float* %%12, align 4, !dbg !7 for 0x%llxth hint within @fSetArray  --> \n", ++aesl_llvm_cbe_38_count);
  *llvm_cbe_tmp__8 = llvm_cbe_val;
if (AESL_DEBUG_TRACE)
printf("\nval = %f\n", llvm_cbe_val);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add nsw i32 %%storemerge12.us, 1, !dbg !7 for 0x%llxth hint within @fSetArray  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__9 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__9&4294967295ull)));
  if (((llvm_cbe_tmp__9&4294967295U) == (llvm_cbe_cols&4294967295U))) {
    goto llvm_cbe_tmp__13;
  } else {
    llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__9;   /* for PHI node */
    goto llvm_cbe_tmp__12;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe__2e__crit_edge5:
  goto llvm_cbe_tmp__11;

llvm_cbe_tmp__11:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load %%struct.F2D** %%out, align 8, !dbg !7 for 0x%llxth hint within @fSetArray  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__10 = (l_struct_OC_F2D *)*(&llvm_cbe_out);
if (AESL_DEBUG_TRACE)
printf("\n  store %%struct.F2D* %%15, %%struct.F2D** %%rtr_val, align 8, !dbg !7 for 0x%llxth hint within @fSetArray  --> \n", ++aesl_llvm_cbe_57_count);
  *llvm_cbe_rtr_val = (l_struct_OC_F2D *)llvm_cbe_tmp__10;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @fSetArray}\n");
  return;
}


void outlined_fun_15(signed int *llvm_cbe_i, signed int *llvm_cbe_rows, signed int *llvm_cbe_j, signed int *llvm_cbe_cols, l_struct_OC_F2D *llvm_cbe_out, float *llvm_cbe_val, l_struct_OC_F2D **llvm_cbe_rtr_val) {
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
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  signed int *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  float llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  unsigned long long llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  float *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @outlined_fun_15\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_81_count);
  *llvm_cbe_i = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i32* %%rows, align 4, !dbg !5 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__14 = (unsigned int )*llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
  if ((((signed int )llvm_cbe_tmp__14) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge3;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.F2D* %%out, i64 0, i32 0, !dbg !6 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__15 = (signed int *)(&llvm_cbe_out->field0);
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%j, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_87_count);
  *llvm_cbe_j = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%cols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__16 = (unsigned int )*llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
  if ((((signed int )llvm_cbe_tmp__16) > ((signed int )0u))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__27 = (unsigned int )*llvm_cbe_i;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%17, 1, !dbg !6 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__28 = (unsigned int )((unsigned int )(llvm_cbe_tmp__27&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__28&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%18, i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_107_count);
  *llvm_cbe_i = llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i32* %%rows, align 4, !dbg !5 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__29 = (unsigned int )*llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
  if ((((signed int )llvm_cbe_tmp__28) < ((signed int )llvm_cbe_tmp__29))) {
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe__2e__crit_edge3;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ %%14, %%.lr.ph ], [ 0, %%.preheader  for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",llvm_cbe_tmp__25);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load float* %%val, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__17 = (float )*llvm_cbe_val;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__17, *(int*)(&llvm_cbe_tmp__17));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_92_count);
  llvm_cbe_tmp__18 = (unsigned int )*llvm_cbe_i;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%3, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_93_count);
  llvm_cbe_tmp__19 = (unsigned int )*llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul nsw i32 %%8, %%7, !dbg !6 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__20 = (unsigned int )((unsigned int )(llvm_cbe_tmp__19&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__18&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__20&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%9, %%storemerge12, !dbg !6 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_95_count);
  llvm_cbe_tmp__21 = (unsigned int )((unsigned int )(llvm_cbe_tmp__20&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge12&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__21&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%10 to i64, !dbg !6 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__22 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.F2D* %%out, i64 0, i32 2, i64 %%11, !dbg !6 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_97_count);
  llvm_cbe_tmp__23 = (float *)(&llvm_cbe_out->field2[(((signed long long )llvm_cbe_tmp__22))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__22));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%6, float* %%12, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_98_count);
  *llvm_cbe_tmp__23 = llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i32* %%j, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_99_count);
  llvm_cbe_tmp__24 = (unsigned int )*llvm_cbe_j;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add nsw i32 %%13, 1, !dbg !7 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_100_count);
  llvm_cbe_tmp__25 = (unsigned int )((unsigned int )(llvm_cbe_tmp__24&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__25&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%14, i32* %%j, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_101_count);
  *llvm_cbe_j = llvm_cbe_tmp__25;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* %%cols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__26 = (unsigned int )*llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__26);
  if ((((signed int )llvm_cbe_tmp__25) < ((signed int )llvm_cbe_tmp__26))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__25;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e__crit_edge3:
if (AESL_DEBUG_TRACE)
printf("\n  store %%struct.F2D* %%out, %%struct.F2D** %%rtr_val, align 8, !dbg !7 for 0x%llxth hint within @outlined_fun_15  --> \n", ++aesl_llvm_cbe_111_count);
  *llvm_cbe_rtr_val = (l_struct_OC_F2D *)llvm_cbe_out;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @outlined_fun_15}\n");
  return;
}


void fSetArray_rep2(signed int llvm_cbe_rows, signed int llvm_cbe_cols, float llvm_cbe_val, l_struct_OC_F2D **llvm_cbe_rtr_val) {
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  signed int llvm_cbe_tmp__30;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  signed int llvm_cbe_tmp__31;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  float llvm_cbe_tmp__32;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_i_count = 0;
  signed int llvm_cbe_i;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_j_count = 0;
  signed int llvm_cbe_j;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_out_count = 0;
  l_struct_OC_F2D *llvm_cbe_out;    /* Address-exposed local */
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
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @fSetArray_rep2\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%rows, i32* %%1, align  for 0x%llxth hint within @fSetArray_rep2  --> \n", ++aesl_llvm_cbe_122_count);
  *(&llvm_cbe_tmp__30) = llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\nrows = 0x%X\n", llvm_cbe_rows);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%cols, i32* %%2, align  for 0x%llxth hint within @fSetArray_rep2  --> \n", ++aesl_llvm_cbe_130_count);
  *(&llvm_cbe_tmp__31) = llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\ncols = 0x%X\n", llvm_cbe_cols);
if (AESL_DEBUG_TRACE)
printf("\n  store float %%val, float* %%3, align  for 0x%llxth hint within @fSetArray_rep2  --> \n", ++aesl_llvm_cbe_138_count);
  *(&llvm_cbe_tmp__32) = llvm_cbe_val;
if (AESL_DEBUG_TRACE)
printf("\nval = %f\n", llvm_cbe_val);
if (AESL_DEBUG_TRACE)
printf("\n  call void @fMallocHandle(i32 %%rows, i32 %%cols, %%struct.F2D** %%out) nounwind, !dbg !7 for 0x%llxth hint within @fSetArray_rep2  --> \n", ++aesl_llvm_cbe_147_count);
  fMallocHandle(llvm_cbe_rows, llvm_cbe_cols, (l_struct_OC_F2D **)(&llvm_cbe_out));
if (AESL_DEBUG_TRACE) {
printf("\nArgument rows = 0x%X",llvm_cbe_rows);
printf("\nArgument cols = 0x%X",llvm_cbe_cols);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load %%struct.F2D** %%out, align 8, !dbg !6 for 0x%llxth hint within @fSetArray_rep2  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__33 = (l_struct_OC_F2D *)*(&llvm_cbe_out);
if (AESL_DEBUG_TRACE)
printf("\n  call void @outlined_fun_15(i32* %%i, i32* %%1, i32* %%j, i32* %%2, %%struct.F2D* %%4, float* %%3, %%struct.F2D** %%rtr_val), !dbg !6 for 0x%llxth hint within @fSetArray_rep2  --> \n", ++aesl_llvm_cbe_155_count);
  outlined_fun_15((signed int *)(&llvm_cbe_i), (signed int *)(&llvm_cbe_tmp__30), (signed int *)(&llvm_cbe_j), (signed int *)(&llvm_cbe_tmp__31), (l_struct_OC_F2D *)llvm_cbe_tmp__33, (float *)(&llvm_cbe_tmp__32), (l_struct_OC_F2D **)llvm_cbe_rtr_val);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @fSetArray_rep2}\n");
  return;
}


void outlined_fun_14(signed int *llvm_cbe_i, signed int *llvm_cbe_rows, signed int *llvm_cbe_j, signed int *llvm_cbe_cols, l_struct_OC_F2D *llvm_cbe_out, float *llvm_cbe_val, l_struct_OC_F2D **llvm_cbe_rtr_val) {
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  signed int *llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  unsigned int llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  float llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  unsigned int llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  unsigned long long llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  float *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  unsigned int llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @outlined_fun_14\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_179_count);
  *llvm_cbe_i = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i32* %%rows, align 4, !dbg !5 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__34 = (unsigned int )*llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__34);
  if ((((signed int )llvm_cbe_tmp__34) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge3;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.F2D* %%out, i64 0, i32 0, !dbg !6 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_183_count);
  llvm_cbe_tmp__35 = (signed int *)(&llvm_cbe_out->field0);
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%j, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_185_count);
  *llvm_cbe_j = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%cols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_186_count);
  llvm_cbe_tmp__36 = (unsigned int )*llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__36);
  if ((((signed int )llvm_cbe_tmp__36) > ((signed int )0u))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_203_count);
  llvm_cbe_tmp__47 = (unsigned int )*llvm_cbe_i;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%17, 1, !dbg !6 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_204_count);
  llvm_cbe_tmp__48 = (unsigned int )((unsigned int )(llvm_cbe_tmp__47&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__48&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%18, i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_205_count);
  *llvm_cbe_i = llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i32* %%rows, align 4, !dbg !5 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_206_count);
  llvm_cbe_tmp__49 = (unsigned int )*llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__49);
  if ((((signed int )llvm_cbe_tmp__48) < ((signed int )llvm_cbe_tmp__49))) {
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe__2e__crit_edge3;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ %%14, %%.lr.ph ], [ 0, %%.preheader  for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",llvm_cbe_tmp__45);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load float* %%val, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_189_count);
  llvm_cbe_tmp__37 = (float )*llvm_cbe_val;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__37, *(int*)(&llvm_cbe_tmp__37));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_190_count);
  llvm_cbe_tmp__38 = (unsigned int )*llvm_cbe_i;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%3, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_191_count);
  llvm_cbe_tmp__39 = (unsigned int )*llvm_cbe_tmp__35;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul nsw i32 %%8, %%7, !dbg !6 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_192_count);
  llvm_cbe_tmp__40 = (unsigned int )((unsigned int )(llvm_cbe_tmp__39&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__38&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__40&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%9, %%storemerge12, !dbg !6 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_193_count);
  llvm_cbe_tmp__41 = (unsigned int )((unsigned int )(llvm_cbe_tmp__40&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge12&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__41&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%10 to i64, !dbg !6 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_194_count);
  llvm_cbe_tmp__42 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.F2D* %%out, i64 0, i32 2, i64 %%11, !dbg !6 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_195_count);
  llvm_cbe_tmp__43 = (float *)(&llvm_cbe_out->field2[(((signed long long )llvm_cbe_tmp__42))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__42));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%6, float* %%12, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_196_count);
  *llvm_cbe_tmp__43 = llvm_cbe_tmp__37;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i32* %%j, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_197_count);
  llvm_cbe_tmp__44 = (unsigned int )*llvm_cbe_j;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add nsw i32 %%13, 1, !dbg !7 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_198_count);
  llvm_cbe_tmp__45 = (unsigned int )((unsigned int )(llvm_cbe_tmp__44&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__45&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%14, i32* %%j, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_199_count);
  *llvm_cbe_j = llvm_cbe_tmp__45;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* %%cols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_200_count);
  llvm_cbe_tmp__46 = (unsigned int )*llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__46);
  if ((((signed int )llvm_cbe_tmp__45) < ((signed int )llvm_cbe_tmp__46))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__45;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e__crit_edge3:
if (AESL_DEBUG_TRACE)
printf("\n  store %%struct.F2D* %%out, %%struct.F2D** %%rtr_val, align 8, !dbg !7 for 0x%llxth hint within @outlined_fun_14  --> \n", ++aesl_llvm_cbe_209_count);
  *llvm_cbe_rtr_val = (l_struct_OC_F2D *)llvm_cbe_out;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @outlined_fun_14}\n");
  return;
}


void fSetArray_rep1(signed int llvm_cbe_rows, signed int llvm_cbe_cols, float llvm_cbe_val, l_struct_OC_F2D **llvm_cbe_rtr_val) {
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  signed int llvm_cbe_tmp__50;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  signed int llvm_cbe_tmp__51;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  float llvm_cbe_tmp__52;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_i_count = 0;
  signed int llvm_cbe_i;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_j_count = 0;
  signed int llvm_cbe_j;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_out_count = 0;
  l_struct_OC_F2D *llvm_cbe_out;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @fSetArray_rep1\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%rows, i32* %%1, align  for 0x%llxth hint within @fSetArray_rep1  --> \n", ++aesl_llvm_cbe_220_count);
  *(&llvm_cbe_tmp__50) = llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\nrows = 0x%X\n", llvm_cbe_rows);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%cols, i32* %%2, align  for 0x%llxth hint within @fSetArray_rep1  --> \n", ++aesl_llvm_cbe_228_count);
  *(&llvm_cbe_tmp__51) = llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\ncols = 0x%X\n", llvm_cbe_cols);
if (AESL_DEBUG_TRACE)
printf("\n  store float %%val, float* %%3, align  for 0x%llxth hint within @fSetArray_rep1  --> \n", ++aesl_llvm_cbe_236_count);
  *(&llvm_cbe_tmp__52) = llvm_cbe_val;
if (AESL_DEBUG_TRACE)
printf("\nval = %f\n", llvm_cbe_val);
if (AESL_DEBUG_TRACE)
printf("\n  call void @fMallocHandle(i32 %%rows, i32 %%cols, %%struct.F2D** %%out) nounwind, !dbg !7 for 0x%llxth hint within @fSetArray_rep1  --> \n", ++aesl_llvm_cbe_245_count);
  fMallocHandle(llvm_cbe_rows, llvm_cbe_cols, (l_struct_OC_F2D **)(&llvm_cbe_out));
if (AESL_DEBUG_TRACE) {
printf("\nArgument rows = 0x%X",llvm_cbe_rows);
printf("\nArgument cols = 0x%X",llvm_cbe_cols);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load %%struct.F2D** %%out, align 8, !dbg !6 for 0x%llxth hint within @fSetArray_rep1  --> \n", ++aesl_llvm_cbe_252_count);
  llvm_cbe_tmp__53 = (l_struct_OC_F2D *)*(&llvm_cbe_out);
if (AESL_DEBUG_TRACE)
printf("\n  call void @outlined_fun_14(i32* %%i, i32* %%1, i32* %%j, i32* %%2, %%struct.F2D* %%4, float* %%3, %%struct.F2D** %%rtr_val), !dbg !6 for 0x%llxth hint within @fSetArray_rep1  --> \n", ++aesl_llvm_cbe_253_count);
  outlined_fun_14((signed int *)(&llvm_cbe_i), (signed int *)(&llvm_cbe_tmp__50), (signed int *)(&llvm_cbe_j), (signed int *)(&llvm_cbe_tmp__51), (l_struct_OC_F2D *)llvm_cbe_tmp__53, (float *)(&llvm_cbe_tmp__52), (l_struct_OC_F2D **)llvm_cbe_rtr_val);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @fSetArray_rep1}\n");
  return;
}


void outlined_fun_4(signed int *llvm_cbe_i, signed int *llvm_cbe_rows, signed int *llvm_cbe_j, signed int *llvm_cbe_cols, l_struct_OC_F2D *llvm_cbe_out, float *llvm_cbe_val, l_struct_OC_F2D **llvm_cbe_rtr_val) {
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  signed int *llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  float llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  unsigned int llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  unsigned int llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  unsigned int llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  unsigned long long llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  float *llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  unsigned int llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  unsigned int llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  unsigned int llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  unsigned int llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  unsigned int llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  unsigned int llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @outlined_fun_4\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_277_count);
  *llvm_cbe_i = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i32* %%rows, align 4, !dbg !5 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_278_count);
  llvm_cbe_tmp__54 = (unsigned int )*llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__54);
  if ((((signed int )llvm_cbe_tmp__54) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge3;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.F2D* %%out, i64 0, i32 0, !dbg !6 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_281_count);
  llvm_cbe_tmp__55 = (signed int *)(&llvm_cbe_out->field0);
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%j, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_283_count);
  *llvm_cbe_j = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%cols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_284_count);
  llvm_cbe_tmp__56 = (unsigned int )*llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__56);
  if ((((signed int )llvm_cbe_tmp__56) > ((signed int )0u))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_301_count);
  llvm_cbe_tmp__67 = (unsigned int )*llvm_cbe_i;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__67);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%17, 1, !dbg !6 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_302_count);
  llvm_cbe_tmp__68 = (unsigned int )((unsigned int )(llvm_cbe_tmp__67&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__68&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%18, i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_303_count);
  *llvm_cbe_i = llvm_cbe_tmp__68;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i32* %%rows, align 4, !dbg !5 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_304_count);
  llvm_cbe_tmp__69 = (unsigned int )*llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__69);
  if ((((signed int )llvm_cbe_tmp__68) < ((signed int )llvm_cbe_tmp__69))) {
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe__2e__crit_edge3;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ %%14, %%.lr.ph ], [ 0, %%.preheader  for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",llvm_cbe_tmp__65);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load float* %%val, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_287_count);
  llvm_cbe_tmp__57 = (float )*llvm_cbe_val;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__57, *(int*)(&llvm_cbe_tmp__57));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_288_count);
  llvm_cbe_tmp__58 = (unsigned int )*llvm_cbe_i;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%3, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_289_count);
  llvm_cbe_tmp__59 = (unsigned int )*llvm_cbe_tmp__55;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul nsw i32 %%8, %%7, !dbg !6 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_290_count);
  llvm_cbe_tmp__60 = (unsigned int )((unsigned int )(llvm_cbe_tmp__59&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__58&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__60&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%9, %%storemerge12, !dbg !6 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_291_count);
  llvm_cbe_tmp__61 = (unsigned int )((unsigned int )(llvm_cbe_tmp__60&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge12&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__61&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%10 to i64, !dbg !6 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_292_count);
  llvm_cbe_tmp__62 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.F2D* %%out, i64 0, i32 2, i64 %%11, !dbg !6 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_293_count);
  llvm_cbe_tmp__63 = (float *)(&llvm_cbe_out->field2[(((signed long long )llvm_cbe_tmp__62))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__62));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%6, float* %%12, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_294_count);
  *llvm_cbe_tmp__63 = llvm_cbe_tmp__57;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i32* %%j, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_295_count);
  llvm_cbe_tmp__64 = (unsigned int )*llvm_cbe_j;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add nsw i32 %%13, 1, !dbg !7 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_296_count);
  llvm_cbe_tmp__65 = (unsigned int )((unsigned int )(llvm_cbe_tmp__64&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__65&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%14, i32* %%j, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_297_count);
  *llvm_cbe_j = llvm_cbe_tmp__65;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* %%cols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_298_count);
  llvm_cbe_tmp__66 = (unsigned int )*llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__66);
  if ((((signed int )llvm_cbe_tmp__65) < ((signed int )llvm_cbe_tmp__66))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__65;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e__crit_edge3:
if (AESL_DEBUG_TRACE)
printf("\n  store %%struct.F2D* %%out, %%struct.F2D** %%rtr_val, align 8, !dbg !7 for 0x%llxth hint within @outlined_fun_4  --> \n", ++aesl_llvm_cbe_307_count);
  *llvm_cbe_rtr_val = (l_struct_OC_F2D *)llvm_cbe_out;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @outlined_fun_4}\n");
  return;
}


void fSetArray_rep0(signed int llvm_cbe_rows, signed int llvm_cbe_cols, float llvm_cbe_val, l_struct_OC_F2D **llvm_cbe_rtr_val) {
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  signed int llvm_cbe_tmp__70;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  signed int llvm_cbe_tmp__71;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  float llvm_cbe_tmp__72;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_i_count = 0;
  signed int llvm_cbe_i;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_j_count = 0;
  signed int llvm_cbe_j;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_out_count = 0;
  l_struct_OC_F2D *llvm_cbe_out;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @fSetArray_rep0\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%rows, i32* %%1, align  for 0x%llxth hint within @fSetArray_rep0  --> \n", ++aesl_llvm_cbe_318_count);
  *(&llvm_cbe_tmp__70) = llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\nrows = 0x%X\n", llvm_cbe_rows);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%cols, i32* %%2, align  for 0x%llxth hint within @fSetArray_rep0  --> \n", ++aesl_llvm_cbe_326_count);
  *(&llvm_cbe_tmp__71) = llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\ncols = 0x%X\n", llvm_cbe_cols);
if (AESL_DEBUG_TRACE)
printf("\n  store float %%val, float* %%3, align  for 0x%llxth hint within @fSetArray_rep0  --> \n", ++aesl_llvm_cbe_334_count);
  *(&llvm_cbe_tmp__72) = llvm_cbe_val;
if (AESL_DEBUG_TRACE)
printf("\nval = %f\n", llvm_cbe_val);
if (AESL_DEBUG_TRACE)
printf("\n  call void @fMallocHandle(i32 %%rows, i32 %%cols, %%struct.F2D** %%out) nounwind, !dbg !7 for 0x%llxth hint within @fSetArray_rep0  --> \n", ++aesl_llvm_cbe_343_count);
  fMallocHandle(llvm_cbe_rows, llvm_cbe_cols, (l_struct_OC_F2D **)(&llvm_cbe_out));
if (AESL_DEBUG_TRACE) {
printf("\nArgument rows = 0x%X",llvm_cbe_rows);
printf("\nArgument cols = 0x%X",llvm_cbe_cols);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load %%struct.F2D** %%out, align 8, !dbg !6 for 0x%llxth hint within @fSetArray_rep0  --> \n", ++aesl_llvm_cbe_350_count);
  llvm_cbe_tmp__73 = (l_struct_OC_F2D *)*(&llvm_cbe_out);
if (AESL_DEBUG_TRACE)
printf("\n  call void @outlined_fun_4(i32* %%i, i32* %%1, i32* %%j, i32* %%2, %%struct.F2D* %%4, float* %%3, %%struct.F2D** %%rtr_val), !dbg !6 for 0x%llxth hint within @fSetArray_rep0  --> \n", ++aesl_llvm_cbe_351_count);
  outlined_fun_4((signed int *)(&llvm_cbe_i), (signed int *)(&llvm_cbe_tmp__70), (signed int *)(&llvm_cbe_j), (signed int *)(&llvm_cbe_tmp__71), (l_struct_OC_F2D *)llvm_cbe_tmp__73, (float *)(&llvm_cbe_tmp__72), (l_struct_OC_F2D **)llvm_cbe_rtr_val);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @fSetArray_rep0}\n");
  return;
}

