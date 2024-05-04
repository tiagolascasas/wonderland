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
  signed int field2[1];
};

struct l_struct_OC_F2D {
  unsigned int field0;
  unsigned int field1;
  float field2[1];
};


/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void outlined_fun_18(l_struct_OC_I2D *llvm_cbe_range, signed int *llvm_cbe_disparity, signed int *llvm_cbe_rows, l_struct_OC_I2D *llvm_cbe_Iright_moved, signed int *llvm_cbe_cols, signed int *llvm_cbe_i);
void correlateSAD_2D(l_struct_OC_I2D *llvm_cbe_Ileft, l_struct_OC_I2D *llvm_cbe_Iright, l_struct_OC_I2D *llvm_cbe_Iright_moved, signed int llvm_cbe_win_sz, signed int llvm_cbe_disparity, l_struct_OC_F2D *llvm_cbe_SAD, l_struct_OC_F2D *llvm_cbe_integralImg, l_struct_OC_F2D *llvm_cbe_retSAD);
void iMallocHandle_rep1(signed int , signed int , l_struct_OC_I2D **);
void padarray4(l_struct_OC_I2D *, l_struct_OC_I2D *, signed int , l_struct_OC_I2D *);
void computeSAD(l_struct_OC_I2D *, l_struct_OC_I2D *, l_struct_OC_F2D *);
void integralImage2D2D(l_struct_OC_F2D *, l_struct_OC_F2D *);
void finalSAD(l_struct_OC_F2D *, signed int , l_struct_OC_F2D *);
void iFreeHandle_rep4(l_struct_OC_I2D *);
void foo(signed int *llvm_cbe_A, signed int llvm_cbe_size);


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

void outlined_fun_18(l_struct_OC_I2D *llvm_cbe_range, signed int *llvm_cbe_disparity, signed int *llvm_cbe_rows, l_struct_OC_I2D *llvm_cbe_Iright_moved, signed int *llvm_cbe_cols, signed int *llvm_cbe_i) {
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
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  signed int *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  signed int *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  signed int *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  signed int *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  signed int *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @outlined_fun_18\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.I2D* %%range, i64 0, i32 2, i64 0, !dbg !6 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__1 = (signed int *)(&llvm_cbe_range->field2[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%1, align 1, !dbg !6 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_24_count);
  *llvm_cbe_tmp__1 = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%disparity, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__2 = (unsigned int )*llvm_cbe_disparity;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.I2D* %%range, i64 0, i32 2, i64 1, !dbg !6 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__3 = (signed int *)(&llvm_cbe_range->field2[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%2, i32* %%3, align 1, !dbg !6 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_27_count);
  *llvm_cbe_tmp__3 = llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.I2D* %%Iright_moved, i64 0, i32 1, !dbg !6 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__4 = (signed int *)(&llvm_cbe_Iright_moved->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%4, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__5 = (unsigned int )*llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%5, i32* %%rows, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_30_count);
  *llvm_cbe_rows = llvm_cbe_tmp__5;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.I2D* %%Iright_moved, i64 0, i32 0, !dbg !7 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__6 = (signed int *)(&llvm_cbe_Iright_moved->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i32* %%6, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__7 = (unsigned int )*llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%7, i32* %%cols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_33_count);
  *llvm_cbe_cols = llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%i, align 4, !dbg !8 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_34_count);
  *llvm_cbe_i = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%rows, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__8 = (unsigned int )*llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i32* %%cols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__9 = (unsigned int )*llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = mul nsw i32 %%9, %%8, !dbg !7 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(llvm_cbe_tmp__9&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__8&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__10&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__10) > ((signed int )0u))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%15, %%.lr.ph ], [ 0, %%0  for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__14);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sext i32 %%storemerge1 to i64, !dbg !7 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__11 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.I2D* %%Iright_moved, i64 0, i32 2, i64 %%12, !dbg !7 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__12 = (signed int *)(&llvm_cbe_Iright_moved->field2[(((signed long long )llvm_cbe_tmp__11))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__11));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%13, align 1, !dbg !7 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_42_count);
  *llvm_cbe_tmp__12 = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%i, align 4, !dbg !8 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__13 = (unsigned int )*llvm_cbe_i;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%14, 1, !dbg !8 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__14 = (unsigned int )((unsigned int )(llvm_cbe_tmp__13&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__14&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%15, i32* %%i, align 4, !dbg !8 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_45_count);
  *llvm_cbe_i = llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i32* %%rows, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__15 = (unsigned int )*llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i32* %%cols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__16 = (unsigned int )*llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = mul nsw i32 %%17, %%16, !dbg !7 for 0x%llxth hint within @outlined_fun_18  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__17 = (unsigned int )((unsigned int )(llvm_cbe_tmp__16&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__15&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__17&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__14) < ((signed int )llvm_cbe_tmp__17))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__14;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @outlined_fun_18}\n");
  return;
}


void correlateSAD_2D(l_struct_OC_I2D *llvm_cbe_Ileft, l_struct_OC_I2D *llvm_cbe_Iright, l_struct_OC_I2D *llvm_cbe_Iright_moved, signed int llvm_cbe_win_sz, signed int llvm_cbe_disparity, l_struct_OC_F2D *llvm_cbe_SAD, l_struct_OC_F2D *llvm_cbe_integralImg, l_struct_OC_F2D *llvm_cbe_retSAD) {
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  signed int llvm_cbe_tmp__18;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_rows_count = 0;
  signed int llvm_cbe_rows;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_cols_count = 0;
  signed int llvm_cbe_cols;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_i_count = 0;
  signed int llvm_cbe_i;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_range_count = 0;
  l_struct_OC_I2D *llvm_cbe_range;    /* Address-exposed local */
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
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__20;
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
  l_struct_OC_I2D *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @correlateSAD_2D\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%disparity, i32* %%1, align  for 0x%llxth hint within @correlateSAD_2D  --> \n", ++aesl_llvm_cbe_69_count);
  *(&llvm_cbe_tmp__18) = llvm_cbe_disparity;
if (AESL_DEBUG_TRACE)
printf("\ndisparity = 0x%X\n", llvm_cbe_disparity);
if (AESL_DEBUG_TRACE)
printf("\n  call void @iMallocHandle_rep1(i32 1, i32 2, %%struct.I2D** %%range) nounwind, !dbg !9 for 0x%llxth hint within @correlateSAD_2D  --> \n", ++aesl_llvm_cbe_83_count);
  iMallocHandle_rep1(1u, 2u, (l_struct_OC_I2D **)(&llvm_cbe_range));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
printf("\nArgument  = 0x%X",2u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load %%struct.I2D** %%range, align 8, !dbg !6 for 0x%llxth hint within @correlateSAD_2D  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__19 = (l_struct_OC_I2D *)*(&llvm_cbe_range);
if (AESL_DEBUG_TRACE)
printf("\n  call void @outlined_fun_18(%%struct.I2D* %%2, i32* %%1, i32* %%rows, %%struct.I2D* %%Iright_moved, i32* %%cols, i32* %%i), !dbg !6 for 0x%llxth hint within @correlateSAD_2D  --> \n", ++aesl_llvm_cbe_91_count);
  outlined_fun_18((l_struct_OC_I2D *)llvm_cbe_tmp__19, (signed int *)(&llvm_cbe_tmp__18), (signed int *)(&llvm_cbe_rows), (l_struct_OC_I2D *)llvm_cbe_Iright_moved, (signed int *)(&llvm_cbe_cols), (signed int *)(&llvm_cbe_i));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load %%struct.I2D** %%range, align 8, !dbg !6 for 0x%llxth hint within @correlateSAD_2D  --> \n", ++aesl_llvm_cbe_98_count);
  llvm_cbe_tmp__20 = (l_struct_OC_I2D *)*(&llvm_cbe_range);
if (AESL_DEBUG_TRACE)
printf("\n  call void @padarray4(%%struct.I2D* %%Iright, %%struct.I2D* %%3, i32 -1, %%struct.I2D* %%Iright_moved) nounwind, !dbg !6 for 0x%llxth hint within @correlateSAD_2D  --> \n", ++aesl_llvm_cbe_99_count);
  padarray4((l_struct_OC_I2D *)llvm_cbe_Iright, (l_struct_OC_I2D *)llvm_cbe_tmp__20, 4294967295u, (l_struct_OC_I2D *)llvm_cbe_Iright_moved);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",4294967295u);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @computeSAD(%%struct.I2D* %%Ileft, %%struct.I2D* %%Iright_moved, %%struct.F2D* %%SAD) nounwind, !dbg !6 for 0x%llxth hint within @correlateSAD_2D  --> \n", ++aesl_llvm_cbe_100_count);
  computeSAD((l_struct_OC_I2D *)llvm_cbe_Ileft, (l_struct_OC_I2D *)llvm_cbe_Iright_moved, (l_struct_OC_F2D *)llvm_cbe_SAD);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @integralImage2D2D(%%struct.F2D* %%SAD, %%struct.F2D* %%integralImg) nounwind, !dbg !7 for 0x%llxth hint within @correlateSAD_2D  --> \n", ++aesl_llvm_cbe_101_count);
  integralImage2D2D((l_struct_OC_F2D *)llvm_cbe_SAD, (l_struct_OC_F2D *)llvm_cbe_integralImg);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @finalSAD(%%struct.F2D* %%integralImg, i32 %%win_sz, %%struct.F2D* %%retSAD) nounwind, !dbg !7 for 0x%llxth hint within @correlateSAD_2D  --> \n", ++aesl_llvm_cbe_102_count);
  finalSAD((l_struct_OC_F2D *)llvm_cbe_integralImg, llvm_cbe_win_sz, (l_struct_OC_F2D *)llvm_cbe_retSAD);
if (AESL_DEBUG_TRACE) {
printf("\nArgument win_sz = 0x%X",llvm_cbe_win_sz);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load %%struct.I2D** %%range, align 8, !dbg !9 for 0x%llxth hint within @correlateSAD_2D  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__21 = (l_struct_OC_I2D *)*(&llvm_cbe_range);
if (AESL_DEBUG_TRACE)
printf("\n  call void @iFreeHandle_rep4(%%struct.I2D* %%4) nounwind, !dbg !9 for 0x%llxth hint within @correlateSAD_2D  --> \n", ++aesl_llvm_cbe_110_count);
  iFreeHandle_rep4((l_struct_OC_I2D *)llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @correlateSAD_2D}\n");
  return;
}


void foo(signed int *llvm_cbe_A, signed int llvm_cbe_size) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  unsigned long long llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  signed int *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @foo\n");
  if ((((signed int )llvm_cbe_size) > ((signed int )0u))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%8, %%.lr.ph ], [ 0, %%0  for 0x%llxth hint within @foo  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__28);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge1 to i64, !dbg !6 for 0x%llxth hint within @foo  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__22 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i32* %%A, i64 %%2, !dbg !6 for 0x%llxth hint within @foo  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__23 = (signed int *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__22))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__22));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !6 for 0x%llxth hint within @foo  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__24 = (unsigned int )*llvm_cbe_tmp__23;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add i32 %%4, 45, !dbg !6 for 0x%llxth hint within @foo  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__25 = (unsigned int )((unsigned int )(llvm_cbe_tmp__24&4294967295ull)) + ((unsigned int )(45u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__25&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = mul i32 %%5, %%4, !dbg !6 for 0x%llxth hint within @foo  --> \n", ++aesl_llvm_cbe_132_count);
  llvm_cbe_tmp__26 = (unsigned int )((unsigned int )(llvm_cbe_tmp__25&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__24&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__26&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%6, 3, !dbg !6 for 0x%llxth hint within @foo  --> \n", ++aesl_llvm_cbe_133_count);
  llvm_cbe_tmp__27 = (unsigned int )((unsigned int )(llvm_cbe_tmp__26&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__27&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%7, i32* %%3, align 4, !dbg !6 for 0x%llxth hint within @foo  --> \n", ++aesl_llvm_cbe_134_count);
  *llvm_cbe_tmp__23 = llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add nsw i32 %%storemerge1, 1, !dbg !7 for 0x%llxth hint within @foo  --> \n", ++aesl_llvm_cbe_135_count);
  llvm_cbe_tmp__28 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__28&4294967295ull)));
  if (((llvm_cbe_tmp__28&4294967295U) == (llvm_cbe_size&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__28;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @foo}\n");
  return;
}

