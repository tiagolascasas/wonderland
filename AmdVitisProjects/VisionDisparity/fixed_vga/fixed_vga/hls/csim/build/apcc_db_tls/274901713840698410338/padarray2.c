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

/* Structure contents */
struct l_struct_OC_I2D {
  unsigned int field0;
  unsigned int field1;
  signed int field2[1];
};


/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void padarray2(l_struct_OC_I2D *llvm_cbe_inMat, l_struct_OC_I2D *llvm_cbe_borderMat, l_struct_OC_I2D **llvm_cbe_rtr_val);
void iSetArray_rep3(signed int , signed int , signed int , l_struct_OC_I2D **);
void outlined_fun_12(signed int *llvm_cbe_rows, l_struct_OC_I2D *llvm_cbe_inMat, signed int *llvm_cbe_cols, signed int *llvm_cbe_bRows, l_struct_OC_I2D *llvm_cbe_borderMat, signed int *llvm_cbe_bCols, signed int *llvm_cbe_newRows, signed int *llvm_cbe_newCols);
void outlined_fun_13(signed int *llvm_cbe_i, signed int *llvm_cbe_rows, signed int *llvm_cbe_j, signed int *llvm_cbe_cols, l_struct_OC_I2D *llvm_cbe_paddedArray, signed int *llvm_cbe_bRows, signed int *llvm_cbe_bCols, l_struct_OC_I2D *llvm_cbe_inMat, l_struct_OC_I2D **llvm_cbe_rtr_val);
void padarray2_rep1(l_struct_OC_I2D *llvm_cbe_inMat, l_struct_OC_I2D *llvm_cbe_borderMat, l_struct_OC_I2D **llvm_cbe_rtr_val);
void outlined_fun_9(signed int *llvm_cbe_rows, l_struct_OC_I2D *llvm_cbe_inMat, signed int *llvm_cbe_cols, signed int *llvm_cbe_bRows, l_struct_OC_I2D *llvm_cbe_borderMat, signed int *llvm_cbe_bCols, signed int *llvm_cbe_newRows, signed int *llvm_cbe_newCols);
void outlined_fun_10(signed int *llvm_cbe_i, signed int *llvm_cbe_rows, signed int *llvm_cbe_j, signed int *llvm_cbe_cols, l_struct_OC_I2D *llvm_cbe_paddedArray, signed int *llvm_cbe_bRows, signed int *llvm_cbe_bCols, l_struct_OC_I2D *llvm_cbe_inMat, l_struct_OC_I2D **llvm_cbe_rtr_val);
void padarray2_rep0(l_struct_OC_I2D *llvm_cbe_inMat, l_struct_OC_I2D *llvm_cbe_borderMat, l_struct_OC_I2D **llvm_cbe_rtr_val);


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

void padarray2(l_struct_OC_I2D *llvm_cbe_inMat, l_struct_OC_I2D *llvm_cbe_borderMat, l_struct_OC_I2D **llvm_cbe_rtr_val) {
  static  unsigned long long aesl_llvm_cbe_paddedArray_count = 0;
  l_struct_OC_I2D *llvm_cbe_paddedArray;    /* Address-exposed local */
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
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  signed int *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  signed int *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  signed int *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond6_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge12_2e_us;
  unsigned int llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  signed int *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  signed int *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  unsigned long long llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  signed int *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge3_2e_us;
  unsigned int llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @padarray2\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.I2D* %%inMat, i64 0, i32 1, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_12_count);
  llvm_cbe_tmp__1 = (signed int *)(&llvm_cbe_inMat->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_13_count);
  llvm_cbe_tmp__2 = (unsigned int )*llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.I2D* %%inMat, i64 0, i32 0, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__3 = (signed int *)(&llvm_cbe_inMat->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__4 = (unsigned int )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.I2D* %%borderMat, i64 0, i32 2, i64 0, !dbg !7 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_22_count);
  llvm_cbe_tmp__5 = (signed int *)(&llvm_cbe_borderMat->field2[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i32* %%5, align 1, !dbg !7 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__6 = (unsigned int )*llvm_cbe_tmp__5;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.I2D* %%borderMat, i64 0, i32 2, i64 1, !dbg !7 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__7 = (signed int *)(&llvm_cbe_borderMat->field2[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%7, align 1, !dbg !7 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__8 = (unsigned int )*llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = shl i32 %%6, 1, !dbg !8 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__9 = (unsigned int )llvm_cbe_tmp__6 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%9, %%2, !dbg !8 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(llvm_cbe_tmp__9&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__2&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__10&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = shl i32 %%8, 1, !dbg !8 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__11 = (unsigned int )llvm_cbe_tmp__8 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add nsw i32 %%11, %%4, !dbg !8 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__12 = (unsigned int )((unsigned int )(llvm_cbe_tmp__11&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__4&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__12&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  call void @iSetArray_rep3(i32 %%10, i32 %%12, i32 0, %%struct.I2D** %%paddedArray) nounwind, !dbg !9 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_40_count);
  iSetArray_rep3(llvm_cbe_tmp__10, llvm_cbe_tmp__12, 0u, (l_struct_OC_I2D **)(&llvm_cbe_paddedArray));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__10);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__12);
printf("\nArgument  = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_tmp__2) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe_tmp__31;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
  if ((((signed int )llvm_cbe_tmp__4) > ((signed int )0u))) {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge5;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3.us = phi i32 [ %%16, %%15 ], [ 0, %%.preheader.lr.ph  for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_storemerge3_2e_us_count);
  llvm_cbe_storemerge3_2e_us = (unsigned int )llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3.us = 0x%X",llvm_cbe_storemerge3_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__13);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add nsw i32 %%storemerge3.us, %%6, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__29 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__6&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__29&4294967295ull)));
  llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__32;

llvm_cbe_tmp__33:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add nsw i32 %%storemerge3.us, 1, !dbg !9 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__13 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__13&4294967295ull)));
  if (((llvm_cbe_tmp__13&4294967295U) == (llvm_cbe_tmp__2&4294967295U))) {
    goto llvm_cbe__2e__crit_edge5;
  } else {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__13;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__32:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.us = phi i32 [ 0, %%.lr.ph.us ], [ %%32, %%17  for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_storemerge12_2e_us_count);
  llvm_cbe_storemerge12_2e_us = (unsigned int )llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us = 0x%X",llvm_cbe_storemerge12_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__28);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i32* %%3, align 4, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__14 = (unsigned int )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = mul nsw i32 %%18, %%storemerge3.us, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__15 = (unsigned int )((unsigned int )(llvm_cbe_tmp__14&4294967295ull)) * ((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__15&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add nsw i32 %%19, %%storemerge12.us, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__16 = (unsigned int )((unsigned int )(llvm_cbe_tmp__15&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__16&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = sext i32 %%20 to i64, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__17 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.I2D* %%inMat, i64 0, i32 2, i64 %%21, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__18 = (signed int *)(&llvm_cbe_inMat->field2[(((signed long long )llvm_cbe_tmp__17))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__17));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i32* %%22, align 1, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__19 = (unsigned int )*llvm_cbe_tmp__18;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load %%struct.I2D** %%paddedArray, align 8, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__20 = (l_struct_OC_I2D *)*(&llvm_cbe_paddedArray);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.I2D* %%24, i64 0, i32 0, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__21 = (signed int *)(&llvm_cbe_tmp__20->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i32* %%25, align 4, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__22 = (unsigned int )*llvm_cbe_tmp__21;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = mul nsw i32 %%26, %%33, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__23 = (unsigned int )((unsigned int )(llvm_cbe_tmp__22&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__29&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__23&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add nsw i32 %%storemerge12.us, %%8, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__8&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__24&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add nsw i32 %%28, %%27, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_72_count);
  llvm_cbe_tmp__25 = (unsigned int )((unsigned int )(llvm_cbe_tmp__24&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__23&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__25&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = sext i32 %%29 to i64, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_73_count);
  llvm_cbe_tmp__26 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds %%struct.I2D* %%24, i64 0, i32 2, i64 %%30, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__27 = (signed int *)(&llvm_cbe_tmp__20->field2[(((signed long long )llvm_cbe_tmp__26))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__26));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%23, i32* %%31, align 1, !dbg !6 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_75_count);
  *llvm_cbe_tmp__27 = llvm_cbe_tmp__19;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add nsw i32 %%storemerge12.us, 1, !dbg !9 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__28 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__28&4294967295ull)));
  if (((llvm_cbe_tmp__28&4294967295U) == (llvm_cbe_tmp__4&4294967295U))) {
    goto llvm_cbe_tmp__33;
  } else {
    llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__28;   /* for PHI node */
    goto llvm_cbe_tmp__32;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe__2e__crit_edge5:
  goto llvm_cbe_tmp__31;

llvm_cbe_tmp__31:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load %%struct.I2D** %%paddedArray, align 8, !dbg !7 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__30 = (l_struct_OC_I2D *)*(&llvm_cbe_paddedArray);
if (AESL_DEBUG_TRACE)
printf("\n  store %%struct.I2D* %%35, %%struct.I2D** %%rtr_val, align 8, !dbg !7 for 0x%llxth hint within @padarray2  --> \n", ++aesl_llvm_cbe_97_count);
  *llvm_cbe_rtr_val = (l_struct_OC_I2D *)llvm_cbe_tmp__30;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @padarray2}\n");
  return;
}


void outlined_fun_12(signed int *llvm_cbe_rows, l_struct_OC_I2D *llvm_cbe_inMat, signed int *llvm_cbe_cols, signed int *llvm_cbe_bRows, l_struct_OC_I2D *llvm_cbe_borderMat, signed int *llvm_cbe_bCols, signed int *llvm_cbe_newRows, signed int *llvm_cbe_newCols) {
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
  signed int *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  signed int *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  unsigned int llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  signed int *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  signed int *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  unsigned int llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  unsigned int llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @outlined_fun_12\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.I2D* %%inMat, i64 0, i32 1, !dbg !6 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__34 = (signed int *)(&llvm_cbe_inMat->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__35 = (unsigned int )*llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%2, i32* %%rows, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_123_count);
  *llvm_cbe_rows = llvm_cbe_tmp__35;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.I2D* %%inMat, i64 0, i32 0, !dbg !6 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_124_count);
  llvm_cbe_tmp__36 = (signed int *)(&llvm_cbe_inMat->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__37 = (unsigned int )*llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%4, i32* %%cols, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_126_count);
  *llvm_cbe_cols = llvm_cbe_tmp__37;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.I2D* %%borderMat, i64 0, i32 2, i64 0, !dbg !7 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_127_count);
  llvm_cbe_tmp__38 = (signed int *)(&llvm_cbe_borderMat->field2[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i32* %%5, align 1, !dbg !7 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__39 = (unsigned int )*llvm_cbe_tmp__38;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%6, i32* %%bRows, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_129_count);
  *llvm_cbe_bRows = llvm_cbe_tmp__39;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.I2D* %%borderMat, i64 0, i32 2, i64 1, !dbg !7 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__40 = (signed int *)(&llvm_cbe_borderMat->field2[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%7, align 1, !dbg !7 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__41 = (unsigned int )*llvm_cbe_tmp__40;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%8, i32* %%bCols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_132_count);
  *llvm_cbe_bCols = llvm_cbe_tmp__41;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i32* %%rows, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_133_count);
  llvm_cbe_tmp__42 = (unsigned int )*llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i32* %%bRows, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_134_count);
  llvm_cbe_tmp__43 = (unsigned int )*llvm_cbe_bRows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = shl i32 %%10, 1, !dbg !6 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_135_count);
  llvm_cbe_tmp__44 = (unsigned int )llvm_cbe_tmp__43 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add nsw i32 %%11, %%9, !dbg !6 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__45 = (unsigned int )((unsigned int )(llvm_cbe_tmp__44&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__42&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__45&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%12, i32* %%newRows, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_137_count);
  *llvm_cbe_newRows = llvm_cbe_tmp__45;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i32* %%cols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__46 = (unsigned int )*llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%bCols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__47 = (unsigned int )*llvm_cbe_bCols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = shl i32 %%14, 1, !dbg !7 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__48 = (unsigned int )llvm_cbe_tmp__47 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add nsw i32 %%15, %%13, !dbg !7 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__49 = (unsigned int )((unsigned int )(llvm_cbe_tmp__48&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__46&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__49&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%16, i32* %%newCols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_12  --> \n", ++aesl_llvm_cbe_142_count);
  *llvm_cbe_newCols = llvm_cbe_tmp__49;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__49);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @outlined_fun_12}\n");
  return;
}


void outlined_fun_13(signed int *llvm_cbe_i, signed int *llvm_cbe_rows, signed int *llvm_cbe_j, signed int *llvm_cbe_cols, l_struct_OC_I2D *llvm_cbe_paddedArray, signed int *llvm_cbe_bRows, signed int *llvm_cbe_bCols, l_struct_OC_I2D *llvm_cbe_inMat, l_struct_OC_I2D **llvm_cbe_rtr_val) {
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
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
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
  unsigned int llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  signed int *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  signed int *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  unsigned long long llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  signed int *llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  unsigned int llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  unsigned int llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  unsigned int llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  unsigned int llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  unsigned int llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  unsigned int llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  unsigned int llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  unsigned int llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  unsigned long long llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  signed int *llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  unsigned int llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  unsigned int llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  unsigned int llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  unsigned int llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  unsigned int llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  unsigned int llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @outlined_fun_13\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_173_count);
  *llvm_cbe_i = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i32* %%rows, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_174_count);
  llvm_cbe_tmp__50 = (unsigned int )*llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__50);
  if ((((signed int )llvm_cbe_tmp__50) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge3;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.I2D* %%inMat, i64 0, i32 0, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_177_count);
  llvm_cbe_tmp__51 = (signed int *)(&llvm_cbe_inMat->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.I2D* %%paddedArray, i64 0, i32 0, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__52 = (signed int *)(&llvm_cbe_paddedArray->field0);
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%j, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_180_count);
  *llvm_cbe_j = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%cols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_181_count);
  llvm_cbe_tmp__53 = (unsigned int )*llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__53);
  if ((((signed int )llvm_cbe_tmp__53) > ((signed int )0u))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_207_count);
  llvm_cbe_tmp__73 = (unsigned int )*llvm_cbe_i;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__73);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add nsw i32 %%27, 1, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_208_count);
  llvm_cbe_tmp__74 = (unsigned int )((unsigned int )(llvm_cbe_tmp__73&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__74&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%28, i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_209_count);
  *llvm_cbe_i = llvm_cbe_tmp__74;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__74);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i32* %%rows, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__75 = (unsigned int )*llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
  if ((((signed int )llvm_cbe_tmp__74) < ((signed int )llvm_cbe_tmp__75))) {
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe__2e__crit_edge3;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ %%24, %%.lr.ph ], [ 0, %%.preheader  for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",llvm_cbe_tmp__71);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__54 = (unsigned int )*llvm_cbe_i;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%3, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__55 = (unsigned int )*llvm_cbe_tmp__51;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul nsw i32 %%8, %%7, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_186_count);
  llvm_cbe_tmp__56 = (unsigned int )((unsigned int )(llvm_cbe_tmp__55&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__54&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__56&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%9, %%storemerge12, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_187_count);
  llvm_cbe_tmp__57 = (unsigned int )((unsigned int )(llvm_cbe_tmp__56&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge12&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__57&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%10 to i64, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_188_count);
  llvm_cbe_tmp__58 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.I2D* %%inMat, i64 0, i32 2, i64 %%11, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_189_count);
  llvm_cbe_tmp__59 = (signed int *)(&llvm_cbe_inMat->field2[(((signed long long )llvm_cbe_tmp__58))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__58));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i32* %%12, align 1, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_190_count);
  llvm_cbe_tmp__60 = (unsigned int )*llvm_cbe_tmp__59;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%bRows, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_191_count);
  llvm_cbe_tmp__61 = (unsigned int )*llvm_cbe_bRows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%14, %%7, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_192_count);
  llvm_cbe_tmp__62 = (unsigned int )((unsigned int )(llvm_cbe_tmp__61&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__54&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__62&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i32* %%4, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_193_count);
  llvm_cbe_tmp__63 = (unsigned int )*llvm_cbe_tmp__52;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = mul nsw i32 %%15, %%16, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_194_count);
  llvm_cbe_tmp__64 = (unsigned int )((unsigned int )(llvm_cbe_tmp__62&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__63&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__64&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i32* %%bCols, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_195_count);
  llvm_cbe_tmp__65 = (unsigned int )*llvm_cbe_bCols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add nsw i32 %%18, %%storemerge12, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_196_count);
  llvm_cbe_tmp__66 = (unsigned int )((unsigned int )(llvm_cbe_tmp__65&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge12&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__66&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add nsw i32 %%19, %%17, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_197_count);
  llvm_cbe_tmp__67 = (unsigned int )((unsigned int )(llvm_cbe_tmp__66&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__64&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__67&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = sext i32 %%20 to i64, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_198_count);
  llvm_cbe_tmp__68 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__67);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.I2D* %%paddedArray, i64 0, i32 2, i64 %%21, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_199_count);
  llvm_cbe_tmp__69 = (signed int *)(&llvm_cbe_paddedArray->field2[(((signed long long )llvm_cbe_tmp__68))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__68));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%13, i32* %%22, align 1, !dbg !6 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_200_count);
  *llvm_cbe_tmp__69 = llvm_cbe_tmp__60;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i32* %%j, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_201_count);
  llvm_cbe_tmp__70 = (unsigned int )*llvm_cbe_j;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add nsw i32 %%23, 1, !dbg !7 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_202_count);
  llvm_cbe_tmp__71 = (unsigned int )((unsigned int )(llvm_cbe_tmp__70&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__71&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%24, i32* %%j, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_203_count);
  *llvm_cbe_j = llvm_cbe_tmp__71;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i32* %%cols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_204_count);
  llvm_cbe_tmp__72 = (unsigned int )*llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__72);
  if ((((signed int )llvm_cbe_tmp__71) < ((signed int )llvm_cbe_tmp__72))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__71;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e__crit_edge3:
if (AESL_DEBUG_TRACE)
printf("\n  store %%struct.I2D* %%paddedArray, %%struct.I2D** %%rtr_val, align 8, !dbg !8 for 0x%llxth hint within @outlined_fun_13  --> \n", ++aesl_llvm_cbe_213_count);
  *llvm_cbe_rtr_val = (l_struct_OC_I2D *)llvm_cbe_paddedArray;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @outlined_fun_13}\n");
  return;
}


void padarray2_rep1(l_struct_OC_I2D *llvm_cbe_inMat, l_struct_OC_I2D *llvm_cbe_borderMat, l_struct_OC_I2D **llvm_cbe_rtr_val) {
  static  unsigned long long aesl_llvm_cbe_j_count = 0;
  signed int llvm_cbe_j;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_i_count = 0;
  signed int llvm_cbe_i;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_paddedArray_count = 0;
  l_struct_OC_I2D *llvm_cbe_paddedArray;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_newCols_count = 0;
  signed int llvm_cbe_newCols;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_newRows_count = 0;
  signed int llvm_cbe_newRows;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_bCols_count = 0;
  signed int llvm_cbe_bCols;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_bRows_count = 0;
  signed int llvm_cbe_bRows;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_cols_count = 0;
  signed int llvm_cbe_cols;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_rows_count = 0;
  signed int llvm_cbe_rows;    /* Address-exposed local */
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
  unsigned int llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  unsigned int llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @padarray2_rep1\n");
if (AESL_DEBUG_TRACE)
printf("\n  call void @outlined_fun_12(i32* %%rows, %%struct.I2D* %%inMat, i32* %%cols, i32* %%bRows, %%struct.I2D* %%borderMat, i32* %%bCols, i32* %%newRows, i32* %%newCols), !dbg !6 for 0x%llxth hint within @padarray2_rep1  --> \n", ++aesl_llvm_cbe_231_count);
  outlined_fun_12((signed int *)(&llvm_cbe_rows), (l_struct_OC_I2D *)llvm_cbe_inMat, (signed int *)(&llvm_cbe_cols), (signed int *)(&llvm_cbe_bRows), (l_struct_OC_I2D *)llvm_cbe_borderMat, (signed int *)(&llvm_cbe_bCols), (signed int *)(&llvm_cbe_newRows), (signed int *)(&llvm_cbe_newCols));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i32* %%newRows, align 4, !dbg !8 for 0x%llxth hint within @padarray2_rep1  --> \n", ++aesl_llvm_cbe_238_count);
  llvm_cbe_tmp__76 = (unsigned int )*(&llvm_cbe_newRows);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%newCols, align 4, !dbg !8 for 0x%llxth hint within @padarray2_rep1  --> \n", ++aesl_llvm_cbe_245_count);
  llvm_cbe_tmp__77 = (unsigned int )*(&llvm_cbe_newCols);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__77);
if (AESL_DEBUG_TRACE)
printf("\n  call void @iSetArray_rep3(i32 %%1, i32 %%2, i32 0, %%struct.I2D** %%paddedArray) nounwind, !dbg !8 for 0x%llxth hint within @padarray2_rep1  --> \n", ++aesl_llvm_cbe_246_count);
  iSetArray_rep3(llvm_cbe_tmp__76, llvm_cbe_tmp__77, 0u, (l_struct_OC_I2D **)(&llvm_cbe_paddedArray));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__76);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__77);
printf("\nArgument  = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load %%struct.I2D** %%paddedArray, align 8, !dbg !6 for 0x%llxth hint within @padarray2_rep1  --> \n", ++aesl_llvm_cbe_253_count);
  llvm_cbe_tmp__78 = (l_struct_OC_I2D *)*(&llvm_cbe_paddedArray);
if (AESL_DEBUG_TRACE)
printf("\n  call void @outlined_fun_13(i32* %%i, i32* %%rows, i32* %%j, i32* %%cols, %%struct.I2D* %%3, i32* %%bRows, i32* %%bCols, %%struct.I2D* %%inMat, %%struct.I2D** %%rtr_val), !dbg !6 for 0x%llxth hint within @padarray2_rep1  --> \n", ++aesl_llvm_cbe_254_count);
  outlined_fun_13((signed int *)(&llvm_cbe_i), (signed int *)(&llvm_cbe_rows), (signed int *)(&llvm_cbe_j), (signed int *)(&llvm_cbe_cols), (l_struct_OC_I2D *)llvm_cbe_tmp__78, (signed int *)(&llvm_cbe_bRows), (signed int *)(&llvm_cbe_bCols), (l_struct_OC_I2D *)llvm_cbe_inMat, (l_struct_OC_I2D **)llvm_cbe_rtr_val);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @padarray2_rep1}\n");
  return;
}


void outlined_fun_9(signed int *llvm_cbe_rows, l_struct_OC_I2D *llvm_cbe_inMat, signed int *llvm_cbe_cols, signed int *llvm_cbe_bRows, l_struct_OC_I2D *llvm_cbe_borderMat, signed int *llvm_cbe_bCols, signed int *llvm_cbe_newRows, signed int *llvm_cbe_newCols) {
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
  signed int *llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  unsigned int llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  signed int *llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  unsigned int llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  signed int *llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  unsigned int llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  signed int *llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  unsigned int llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  unsigned int llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  unsigned int llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  unsigned int llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  unsigned int llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  unsigned int llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  unsigned int llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  unsigned int llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  unsigned int llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @outlined_fun_9\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.I2D* %%inMat, i64 0, i32 1, !dbg !6 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_278_count);
  llvm_cbe_tmp__79 = (signed int *)(&llvm_cbe_inMat->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_279_count);
  llvm_cbe_tmp__80 = (unsigned int )*llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%2, i32* %%rows, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_280_count);
  *llvm_cbe_rows = llvm_cbe_tmp__80;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.I2D* %%inMat, i64 0, i32 0, !dbg !6 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_281_count);
  llvm_cbe_tmp__81 = (signed int *)(&llvm_cbe_inMat->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_282_count);
  llvm_cbe_tmp__82 = (unsigned int )*llvm_cbe_tmp__81;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__82);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%4, i32* %%cols, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_283_count);
  *llvm_cbe_cols = llvm_cbe_tmp__82;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__82);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.I2D* %%borderMat, i64 0, i32 2, i64 0, !dbg !7 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_284_count);
  llvm_cbe_tmp__83 = (signed int *)(&llvm_cbe_borderMat->field2[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i32* %%5, align 1, !dbg !7 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_285_count);
  llvm_cbe_tmp__84 = (unsigned int )*llvm_cbe_tmp__83;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%6, i32* %%bRows, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_286_count);
  *llvm_cbe_bRows = llvm_cbe_tmp__84;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.I2D* %%borderMat, i64 0, i32 2, i64 1, !dbg !7 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_287_count);
  llvm_cbe_tmp__85 = (signed int *)(&llvm_cbe_borderMat->field2[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%7, align 1, !dbg !7 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_288_count);
  llvm_cbe_tmp__86 = (unsigned int )*llvm_cbe_tmp__85;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%8, i32* %%bCols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_289_count);
  *llvm_cbe_bCols = llvm_cbe_tmp__86;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i32* %%rows, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_290_count);
  llvm_cbe_tmp__87 = (unsigned int )*llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i32* %%bRows, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_291_count);
  llvm_cbe_tmp__88 = (unsigned int )*llvm_cbe_bRows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__88);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = shl i32 %%10, 1, !dbg !6 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_292_count);
  llvm_cbe_tmp__89 = (unsigned int )llvm_cbe_tmp__88 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add nsw i32 %%11, %%9, !dbg !6 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_293_count);
  llvm_cbe_tmp__90 = (unsigned int )((unsigned int )(llvm_cbe_tmp__89&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__87&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__90&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%12, i32* %%newRows, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_294_count);
  *llvm_cbe_newRows = llvm_cbe_tmp__90;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i32* %%cols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_295_count);
  llvm_cbe_tmp__91 = (unsigned int )*llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__91);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%bCols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_296_count);
  llvm_cbe_tmp__92 = (unsigned int )*llvm_cbe_bCols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__92);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = shl i32 %%14, 1, !dbg !7 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_297_count);
  llvm_cbe_tmp__93 = (unsigned int )llvm_cbe_tmp__92 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__93);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add nsw i32 %%15, %%13, !dbg !7 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_298_count);
  llvm_cbe_tmp__94 = (unsigned int )((unsigned int )(llvm_cbe_tmp__93&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__91&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__94&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%16, i32* %%newCols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_9  --> \n", ++aesl_llvm_cbe_299_count);
  *llvm_cbe_newCols = llvm_cbe_tmp__94;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__94);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @outlined_fun_9}\n");
  return;
}


void outlined_fun_10(signed int *llvm_cbe_i, signed int *llvm_cbe_rows, signed int *llvm_cbe_j, signed int *llvm_cbe_cols, l_struct_OC_I2D *llvm_cbe_paddedArray, signed int *llvm_cbe_bRows, signed int *llvm_cbe_bCols, l_struct_OC_I2D *llvm_cbe_inMat, l_struct_OC_I2D **llvm_cbe_rtr_val) {
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
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
  unsigned int llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  signed int *llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  signed int *llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  unsigned int llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  unsigned int llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  unsigned int llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  unsigned int llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  unsigned int llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  unsigned long long llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  signed int *llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  unsigned int llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  unsigned int llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  unsigned int llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  unsigned int llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  unsigned int llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  unsigned int llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  unsigned int llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  unsigned int llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  unsigned long long llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  signed int *llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  unsigned int llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  unsigned int llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  unsigned int llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  unsigned int llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  unsigned int llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  unsigned int llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @outlined_fun_10\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_330_count);
  *llvm_cbe_i = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i32* %%rows, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_331_count);
  llvm_cbe_tmp__95 = (unsigned int )*llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__95);
  if ((((signed int )llvm_cbe_tmp__95) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge3;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.I2D* %%inMat, i64 0, i32 0, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_334_count);
  llvm_cbe_tmp__96 = (signed int *)(&llvm_cbe_inMat->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.I2D* %%paddedArray, i64 0, i32 0, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_335_count);
  llvm_cbe_tmp__97 = (signed int *)(&llvm_cbe_paddedArray->field0);
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%j, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_337_count);
  *llvm_cbe_j = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%cols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_338_count);
  llvm_cbe_tmp__98 = (unsigned int )*llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__98);
  if ((((signed int )llvm_cbe_tmp__98) > ((signed int )0u))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_364_count);
  llvm_cbe_tmp__118 = (unsigned int )*llvm_cbe_i;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__118);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add nsw i32 %%27, 1, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_365_count);
  llvm_cbe_tmp__119 = (unsigned int )((unsigned int )(llvm_cbe_tmp__118&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__119&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%28, i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_366_count);
  *llvm_cbe_i = llvm_cbe_tmp__119;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__119);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i32* %%rows, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_367_count);
  llvm_cbe_tmp__120 = (unsigned int )*llvm_cbe_rows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__120);
  if ((((signed int )llvm_cbe_tmp__119) < ((signed int )llvm_cbe_tmp__120))) {
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe__2e__crit_edge3;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ %%24, %%.lr.ph ], [ 0, %%.preheader  for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",llvm_cbe_tmp__116);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i32* %%i, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_341_count);
  llvm_cbe_tmp__99 = (unsigned int )*llvm_cbe_i;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%3, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_342_count);
  llvm_cbe_tmp__100 = (unsigned int )*llvm_cbe_tmp__96;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul nsw i32 %%8, %%7, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_343_count);
  llvm_cbe_tmp__101 = (unsigned int )((unsigned int )(llvm_cbe_tmp__100&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__99&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__101&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%9, %%storemerge12, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_344_count);
  llvm_cbe_tmp__102 = (unsigned int )((unsigned int )(llvm_cbe_tmp__101&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge12&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__102&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%10 to i64, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_345_count);
  llvm_cbe_tmp__103 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__103);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.I2D* %%inMat, i64 0, i32 2, i64 %%11, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_346_count);
  llvm_cbe_tmp__104 = (signed int *)(&llvm_cbe_inMat->field2[(((signed long long )llvm_cbe_tmp__103))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__103));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i32* %%12, align 1, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_347_count);
  llvm_cbe_tmp__105 = (unsigned int )*llvm_cbe_tmp__104;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__105);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%bRows, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_348_count);
  llvm_cbe_tmp__106 = (unsigned int )*llvm_cbe_bRows;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__106);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%14, %%7, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_349_count);
  llvm_cbe_tmp__107 = (unsigned int )((unsigned int )(llvm_cbe_tmp__106&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__99&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__107&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i32* %%4, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_350_count);
  llvm_cbe_tmp__108 = (unsigned int )*llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__108);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = mul nsw i32 %%15, %%16, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_351_count);
  llvm_cbe_tmp__109 = (unsigned int )((unsigned int )(llvm_cbe_tmp__107&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__108&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__109&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i32* %%bCols, align 4, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_352_count);
  llvm_cbe_tmp__110 = (unsigned int )*llvm_cbe_bCols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__110);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add nsw i32 %%18, %%storemerge12, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_353_count);
  llvm_cbe_tmp__111 = (unsigned int )((unsigned int )(llvm_cbe_tmp__110&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge12&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__111&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add nsw i32 %%19, %%17, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_354_count);
  llvm_cbe_tmp__112 = (unsigned int )((unsigned int )(llvm_cbe_tmp__111&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__109&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__112&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = sext i32 %%20 to i64, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_355_count);
  llvm_cbe_tmp__113 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__112);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__113);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.I2D* %%paddedArray, i64 0, i32 2, i64 %%21, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_356_count);
  llvm_cbe_tmp__114 = (signed int *)(&llvm_cbe_paddedArray->field2[(((signed long long )llvm_cbe_tmp__113))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__113));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%13, i32* %%22, align 1, !dbg !6 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_357_count);
  *llvm_cbe_tmp__114 = llvm_cbe_tmp__105;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__105);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i32* %%j, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_358_count);
  llvm_cbe_tmp__115 = (unsigned int )*llvm_cbe_j;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__115);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add nsw i32 %%23, 1, !dbg !7 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_359_count);
  llvm_cbe_tmp__116 = (unsigned int )((unsigned int )(llvm_cbe_tmp__115&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__116&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%24, i32* %%j, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_360_count);
  *llvm_cbe_j = llvm_cbe_tmp__116;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__116);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i32* %%cols, align 4, !dbg !7 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_361_count);
  llvm_cbe_tmp__117 = (unsigned int )*llvm_cbe_cols;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__117);
  if ((((signed int )llvm_cbe_tmp__116) < ((signed int )llvm_cbe_tmp__117))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__116;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e__crit_edge3:
if (AESL_DEBUG_TRACE)
printf("\n  store %%struct.I2D* %%paddedArray, %%struct.I2D** %%rtr_val, align 8, !dbg !8 for 0x%llxth hint within @outlined_fun_10  --> \n", ++aesl_llvm_cbe_370_count);
  *llvm_cbe_rtr_val = (l_struct_OC_I2D *)llvm_cbe_paddedArray;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @outlined_fun_10}\n");
  return;
}


void padarray2_rep0(l_struct_OC_I2D *llvm_cbe_inMat, l_struct_OC_I2D *llvm_cbe_borderMat, l_struct_OC_I2D **llvm_cbe_rtr_val) {
  static  unsigned long long aesl_llvm_cbe_j_count = 0;
  signed int llvm_cbe_j;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_i_count = 0;
  signed int llvm_cbe_i;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_paddedArray_count = 0;
  l_struct_OC_I2D *llvm_cbe_paddedArray;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_newCols_count = 0;
  signed int llvm_cbe_newCols;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_newRows_count = 0;
  signed int llvm_cbe_newRows;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_bCols_count = 0;
  signed int llvm_cbe_bCols;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_bRows_count = 0;
  signed int llvm_cbe_bRows;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_cols_count = 0;
  signed int llvm_cbe_cols;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_rows_count = 0;
  signed int llvm_cbe_rows;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  unsigned int llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  unsigned int llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @padarray2_rep0\n");
if (AESL_DEBUG_TRACE)
printf("\n  call void @outlined_fun_9(i32* %%rows, %%struct.I2D* %%inMat, i32* %%cols, i32* %%bRows, %%struct.I2D* %%borderMat, i32* %%bCols, i32* %%newRows, i32* %%newCols), !dbg !6 for 0x%llxth hint within @padarray2_rep0  --> \n", ++aesl_llvm_cbe_388_count);
  outlined_fun_9((signed int *)(&llvm_cbe_rows), (l_struct_OC_I2D *)llvm_cbe_inMat, (signed int *)(&llvm_cbe_cols), (signed int *)(&llvm_cbe_bRows), (l_struct_OC_I2D *)llvm_cbe_borderMat, (signed int *)(&llvm_cbe_bCols), (signed int *)(&llvm_cbe_newRows), (signed int *)(&llvm_cbe_newCols));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i32* %%newRows, align 4, !dbg !8 for 0x%llxth hint within @padarray2_rep0  --> \n", ++aesl_llvm_cbe_395_count);
  llvm_cbe_tmp__121 = (unsigned int )*(&llvm_cbe_newRows);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__121);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%newCols, align 4, !dbg !8 for 0x%llxth hint within @padarray2_rep0  --> \n", ++aesl_llvm_cbe_402_count);
  llvm_cbe_tmp__122 = (unsigned int )*(&llvm_cbe_newCols);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__122);
if (AESL_DEBUG_TRACE)
printf("\n  call void @iSetArray_rep3(i32 %%1, i32 %%2, i32 0, %%struct.I2D** %%paddedArray) nounwind, !dbg !8 for 0x%llxth hint within @padarray2_rep0  --> \n", ++aesl_llvm_cbe_403_count);
  iSetArray_rep3(llvm_cbe_tmp__121, llvm_cbe_tmp__122, 0u, (l_struct_OC_I2D **)(&llvm_cbe_paddedArray));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__121);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__122);
printf("\nArgument  = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load %%struct.I2D** %%paddedArray, align 8, !dbg !6 for 0x%llxth hint within @padarray2_rep0  --> \n", ++aesl_llvm_cbe_410_count);
  llvm_cbe_tmp__123 = (l_struct_OC_I2D *)*(&llvm_cbe_paddedArray);
if (AESL_DEBUG_TRACE)
printf("\n  call void @outlined_fun_10(i32* %%i, i32* %%rows, i32* %%j, i32* %%cols, %%struct.I2D* %%3, i32* %%bRows, i32* %%bCols, %%struct.I2D* %%inMat, %%struct.I2D** %%rtr_val), !dbg !6 for 0x%llxth hint within @padarray2_rep0  --> \n", ++aesl_llvm_cbe_411_count);
  outlined_fun_10((signed int *)(&llvm_cbe_i), (signed int *)(&llvm_cbe_rows), (signed int *)(&llvm_cbe_j), (signed int *)(&llvm_cbe_cols), (l_struct_OC_I2D *)llvm_cbe_tmp__123, (signed int *)(&llvm_cbe_bRows), (signed int *)(&llvm_cbe_bCols), (l_struct_OC_I2D *)llvm_cbe_inMat, (l_struct_OC_I2D **)llvm_cbe_rtr_val);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @padarray2_rep0}\n");
  return;
}

