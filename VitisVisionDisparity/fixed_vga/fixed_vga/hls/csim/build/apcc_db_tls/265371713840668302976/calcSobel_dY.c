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
typedef struct l_struct_OC_I2D l_struct_OC_I2D;

/* Structure contents */
struct l_struct_OC_F2D {
  unsigned int field0;
  unsigned int field1;
  float field2[1];
};

struct l_struct_OC_I2D {
  unsigned int field0;
  unsigned int field1;
  signed int field2[1];
};


/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
l_struct_OC_F2D *calcSobel_dY(l_struct_OC_F2D *llvm_cbe_imageIn);
void fSetArray(signed int , signed int , float , l_struct_OC_F2D **);
void iMallocHandle(signed int , signed int , l_struct_OC_I2D **);
void fFreeHandle(l_struct_OC_F2D *);
void iFreeHandle(l_struct_OC_I2D *);


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

l_struct_OC_F2D *calcSobel_dY(l_struct_OC_F2D *llvm_cbe_imageIn) {
  static  unsigned long long aesl_llvm_cbe_kernel_1_count = 0;
  l_struct_OC_I2D *llvm_cbe_kernel_1;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_kernel_2_count = 0;
  l_struct_OC_I2D *llvm_cbe_kernel_2;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_imageOut_count = 0;
  l_struct_OC_F2D *llvm_cbe_imageOut;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_tempOut_count = 0;
  l_struct_OC_F2D *llvm_cbe_tempOut;    /* Address-exposed local */
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
  signed int *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  signed int *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
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
  l_struct_OC_I2D *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  signed int *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  signed int *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  signed int *llvm_cbe_tmp__10;
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
  l_struct_OC_I2D *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  signed int *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  signed int *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  signed int *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  unsigned int llvm_cbe_tmp__17;
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
  unsigned int llvm_cbe_tmp__18;
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
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond22_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge417_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge417_2e_us;
  unsigned int llvm_cbe_storemerge417_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  unsigned long long llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  float *llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  float llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  signed int *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  float llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  float llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  float llvm_cbe_tmp__31;
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
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  unsigned long long llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  float *llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  float llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  signed int *llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  float llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  float llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  float llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  unsigned int llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  unsigned long long llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  float *llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  float llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  signed int *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  unsigned int llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  float llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  float llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  float llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  float llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  signed int *llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  unsigned int llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  unsigned long long llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  float *llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  unsigned int llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond21_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge19_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge19_2e_us;
  unsigned int llvm_cbe_storemerge19_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  unsigned int llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
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
  unsigned int llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond26_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge28_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge28_2e_us;
  unsigned int llvm_cbe_storemerge28_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  signed int *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  unsigned int llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  unsigned int llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  unsigned int llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  unsigned int llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  unsigned long long llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  float *llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  float llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  signed int *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  unsigned int llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  float llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  float llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  float llvm_cbe_tmp__78;
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
  unsigned int llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  unsigned long long llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  float *llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  float llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  signed int *llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  unsigned int llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  float llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  float llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  float llvm_cbe_tmp__87;
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
  unsigned int llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  unsigned int llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  unsigned long long llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  float *llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  float llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  signed int *llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  unsigned int llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  float llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  float llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  float llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  float llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  signed int *llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  unsigned int llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  unsigned int llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  unsigned int llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  unsigned long long llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  float *llvm_cbe_tmp__105;
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
  static  unsigned long long aesl_llvm_cbe_exitcond25_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge110_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge110_2e_us;
  unsigned int llvm_cbe_storemerge110_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @calcSobel_dY\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.F2D* %%imageIn, i64 0, i32 1, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_10_count);
  llvm_cbe_tmp__1 = (signed int *)(&llvm_cbe_imageIn->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__2 = (unsigned int )*llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.F2D* %%imageIn, i64 0, i32 0, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__3 = (signed int *)(&llvm_cbe_imageIn->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__4 = (unsigned int )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  call void @fSetArray(i32 %%2, i32 %%4, float 0.000000e+00, %%struct.F2D** %%imageOut) nounwind, !dbg !6 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_26_count);
  fSetArray(llvm_cbe_tmp__2, llvm_cbe_tmp__4, 0x0p0, (l_struct_OC_F2D **)(&llvm_cbe_imageOut));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__2);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__4);
printf("\nArgument  = %f",0x0p0);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @fSetArray(i32 %%2, i32 %%4, float 0.000000e+00, %%struct.F2D** %%tempOut) nounwind, !dbg !6 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_27_count);
  fSetArray(llvm_cbe_tmp__2, llvm_cbe_tmp__4, 0x0p0, (l_struct_OC_F2D **)(&llvm_cbe_tempOut));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__2);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__4);
printf("\nArgument  = %f",0x0p0);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @iMallocHandle(i32 1, i32 3, %%struct.I2D** %%kernel_1) nounwind, !dbg !7 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_28_count);
  iMallocHandle(1u, 3u, (l_struct_OC_I2D **)(&llvm_cbe_kernel_1));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
printf("\nArgument  = 0x%X",3u);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @iMallocHandle(i32 1, i32 3, %%struct.I2D** %%kernel_2) nounwind, !dbg !7 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_29_count);
  iMallocHandle(1u, 3u, (l_struct_OC_I2D **)(&llvm_cbe_kernel_2));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
printf("\nArgument  = 0x%X",3u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load %%struct.I2D** %%kernel_1, align 8, !dbg !7 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__5 = (l_struct_OC_I2D *)*(&llvm_cbe_kernel_1);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.I2D* %%5, i64 0, i32 2, i64 0, !dbg !7 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__6 = (signed int *)(&llvm_cbe_tmp__5->field2[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 1, i32* %%6, align 1, !dbg !7 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_38_count);
  *llvm_cbe_tmp__6 = 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 1u);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load %%struct.I2D** %%kernel_1, align 8, !dbg !7 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__7 = (l_struct_OC_I2D *)*(&llvm_cbe_kernel_1);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.I2D* %%7, i64 0, i32 2, i64 1, !dbg !7 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__8 = (signed int *)(&llvm_cbe_tmp__7->field2[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%8, align 1, !dbg !7 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_47_count);
  *llvm_cbe_tmp__8 = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load %%struct.I2D** %%kernel_1, align 8, !dbg !7 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__9 = (l_struct_OC_I2D *)*(&llvm_cbe_kernel_1);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.I2D* %%9, i64 0, i32 2, i64 2, !dbg !7 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__10 = (signed int *)(&llvm_cbe_tmp__9->field2[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 -1, i32* %%10, align 1, !dbg !7 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_56_count);
  *llvm_cbe_tmp__10 = 4294967295u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 4294967295u);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load %%struct.I2D** %%kernel_2, align 8, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__11 = (l_struct_OC_I2D *)*(&llvm_cbe_kernel_2);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.I2D* %%11, i64 0, i32 2, i64 0, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__12 = (signed int *)(&llvm_cbe_tmp__11->field2[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 1, i32* %%12, align 1, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_68_count);
  *llvm_cbe_tmp__12 = 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 1u);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load %%struct.I2D** %%kernel_2, align 8, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__13 = (l_struct_OC_I2D *)*(&llvm_cbe_kernel_2);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.I2D* %%13, i64 0, i32 2, i64 1, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__14 = (signed int *)(&llvm_cbe_tmp__13->field2[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 2, i32* %%14, align 1, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_77_count);
  *llvm_cbe_tmp__14 = 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 2u);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load %%struct.I2D** %%kernel_2, align 8, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__15 = (l_struct_OC_I2D *)*(&llvm_cbe_kernel_2);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.I2D* %%15, i64 0, i32 2, i64 2, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__16 = (signed int *)(&llvm_cbe_tmp__15->field2[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 1, i32* %%16, align 1, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_86_count);
  *llvm_cbe_tmp__16 = 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 1u);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add nsw i32 %%4, -1, !dbg !6 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_92_count);
  llvm_cbe_tmp__17 = (unsigned int )((unsigned int )(llvm_cbe_tmp__4&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__17&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%2, -1, !dbg !6 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__18 = (unsigned int )((unsigned int )(llvm_cbe_tmp__2&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__18&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__18) > ((signed int )1u))) {
    goto llvm_cbe__2e_preheader16_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e_preheader9_2e_thread;
  }

llvm_cbe__2e_preheader16_2e_lr_2e_ph:
  if ((((signed int )llvm_cbe_tmp__17) > ((signed int )1u))) {
    llvm_cbe_storemerge19_2e_us__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe__2e_preheader13_2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge12;
  }

  do {     /* Syntactic loop '.preheader13.lr.ph.us' to make GCC happy */
llvm_cbe__2e_preheader13_2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge19.us = phi i32 [ %%22, %%21 ], [ 1, %%.preheader16.lr.ph  for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_storemerge19_2e_us_count);
  llvm_cbe_storemerge19_2e_us = (unsigned int )llvm_cbe_storemerge19_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge19.us = 0x%X",llvm_cbe_storemerge19_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__19);
printf("\n = 0x%X",1u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = add nsw i32 %%storemerge19.us, -1, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_253_count);
  llvm_cbe_tmp__62 = (unsigned int )((unsigned int )(llvm_cbe_storemerge19_2e_us&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__62&4294967295ull)));
  llvm_cbe_storemerge417_2e_us__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe__2e_preheader13_2e_us;

llvm_cbe_tmp__110:
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add nsw i32 %%storemerge19.us, 1, !dbg !11 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__19 = (unsigned int )((unsigned int )(llvm_cbe_storemerge19_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__19&4294967295ull)));
  if (((llvm_cbe_tmp__19&4294967295U) == (llvm_cbe_tmp__18&4294967295U))) {
    goto llvm_cbe__2e_preheader9;
  } else {
    llvm_cbe_storemerge19_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__19;   /* for PHI node */
    goto llvm_cbe__2e_preheader13_2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '.preheader13.us' to make GCC happy */
llvm_cbe__2e_preheader13_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge417.us = phi i32 [ 1, %%.preheader13.lr.ph.us ], [ %%64, %%.preheader13.us  for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_storemerge417_2e_us_count);
  llvm_cbe_storemerge417_2e_us = (unsigned int )llvm_cbe_storemerge417_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge417.us = 0x%X",llvm_cbe_storemerge417_2e_us);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",llvm_cbe_tmp__61);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i32* %%3, align 4, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__20 = (unsigned int )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load %%struct.I2D** %%kernel_1, align 8, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_147_count);
  llvm_cbe_tmp__21 = (l_struct_OC_I2D *)*(&llvm_cbe_kernel_1);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = mul nsw i32 %%23, %%65, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_148_count);
  llvm_cbe_tmp__22 = (unsigned int )((unsigned int )(llvm_cbe_tmp__20&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__62&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__22&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add nsw i32 %%25, %%storemerge417.us, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_149_count);
  llvm_cbe_tmp__23 = (unsigned int )((unsigned int )(llvm_cbe_tmp__22&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge417_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__23&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = sext i32 %%26 to i64, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_150_count);
  llvm_cbe_tmp__24 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds %%struct.F2D* %%imageIn, i64 0, i32 2, i64 %%27, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__25 = (float *)(&llvm_cbe_imageIn->field2[(((signed long long )llvm_cbe_tmp__24))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__24));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load float* %%28, align 1, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_152_count);
  llvm_cbe_tmp__26 = (float )*llvm_cbe_tmp__25;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__26, *(int*)(&llvm_cbe_tmp__26));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct.I2D* %%24, i64 0, i32 2, i64 0, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_153_count);
  llvm_cbe_tmp__27 = (signed int *)(&llvm_cbe_tmp__21->field2[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i32* %%30, align 1, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__28 = (unsigned int )*llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = sitofp i32 %%31 to float, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__29 = (float )((float )(signed int )llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__29, *(int*)(&llvm_cbe_tmp__29));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = fmul float %%29, %%32, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_156_count);
  llvm_cbe_tmp__30 = (float )((float )(llvm_cbe_tmp__26 * llvm_cbe_tmp__29));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__30, *(int*)(&llvm_cbe_tmp__30));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = fadd float %%33, 0.000000e+00, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__31 = (float )((float )(llvm_cbe_tmp__30 + 0x0p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__31, *(int*)(&llvm_cbe_tmp__31));
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = mul nsw i32 %%23, %%storemerge19.us, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_172_count);
  llvm_cbe_tmp__32 = (unsigned int )((unsigned int )(llvm_cbe_tmp__20&4294967295ull)) * ((unsigned int )(llvm_cbe_storemerge19_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__32&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = add nsw i32 %%35, %%storemerge417.us, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_173_count);
  llvm_cbe_tmp__33 = (unsigned int )((unsigned int )(llvm_cbe_tmp__32&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge417_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__33&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = sext i32 %%36 to i64, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_174_count);
  llvm_cbe_tmp__34 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds %%struct.F2D* %%imageIn, i64 0, i32 2, i64 %%37, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__35 = (float *)(&llvm_cbe_imageIn->field2[(((signed long long )llvm_cbe_tmp__34))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__34));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load float* %%38, align 1, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_176_count);
  llvm_cbe_tmp__36 = (float )*llvm_cbe_tmp__35;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__36, *(int*)(&llvm_cbe_tmp__36));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds %%struct.I2D* %%24, i64 0, i32 2, i64 1, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_177_count);
  llvm_cbe_tmp__37 = (signed int *)(&llvm_cbe_tmp__21->field2[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = load i32* %%40, align 1, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__38 = (unsigned int )*llvm_cbe_tmp__37;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = sitofp i32 %%41 to float, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__39 = (float )((float )(signed int )llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__39, *(int*)(&llvm_cbe_tmp__39));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = fmul float %%39, %%42, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__40 = (float )((float )(llvm_cbe_tmp__36 * llvm_cbe_tmp__39));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__40, *(int*)(&llvm_cbe_tmp__40));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = fadd float %%34, %%43, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_181_count);
  llvm_cbe_tmp__41 = (float )((float )(llvm_cbe_tmp__31 + llvm_cbe_tmp__40));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__41, *(int*)(&llvm_cbe_tmp__41));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = add nsw i32 %%storemerge19.us, 1, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_196_count);
  llvm_cbe_tmp__42 = (unsigned int )((unsigned int )(llvm_cbe_storemerge19_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__42&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = mul nsw i32 %%23, %%45, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_197_count);
  llvm_cbe_tmp__43 = (unsigned int )((unsigned int )(llvm_cbe_tmp__20&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__42&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__43&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = add nsw i32 %%46, %%storemerge417.us, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_198_count);
  llvm_cbe_tmp__44 = (unsigned int )((unsigned int )(llvm_cbe_tmp__43&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge417_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__44&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = sext i32 %%47 to i64, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_199_count);
  llvm_cbe_tmp__45 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds %%struct.F2D* %%imageIn, i64 0, i32 2, i64 %%48, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_200_count);
  llvm_cbe_tmp__46 = (float *)(&llvm_cbe_imageIn->field2[(((signed long long )llvm_cbe_tmp__45))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__45));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = load float* %%49, align 1, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_201_count);
  llvm_cbe_tmp__47 = (float )*llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__47, *(int*)(&llvm_cbe_tmp__47));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds %%struct.I2D* %%24, i64 0, i32 2, i64 2, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_202_count);
  llvm_cbe_tmp__48 = (signed int *)(&llvm_cbe_tmp__21->field2[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load i32* %%51, align 1, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_203_count);
  llvm_cbe_tmp__49 = (unsigned int )*llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = sitofp i32 %%52 to float, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_204_count);
  llvm_cbe_tmp__50 = (float )((float )(signed int )llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__50, *(int*)(&llvm_cbe_tmp__50));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = fmul float %%50, %%53, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_205_count);
  llvm_cbe_tmp__51 = (float )((float )(llvm_cbe_tmp__47 * llvm_cbe_tmp__50));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__51, *(int*)(&llvm_cbe_tmp__51));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = fadd float %%44, %%54, !dbg !3 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_206_count);
  llvm_cbe_tmp__52 = (float )((float )(llvm_cbe_tmp__41 + llvm_cbe_tmp__51));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__52, *(int*)(&llvm_cbe_tmp__52));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = fmul float %%55, 5.000000e-01, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_221_count);
  llvm_cbe_tmp__53 = (float )((float )(llvm_cbe_tmp__52 * 0x1p-1));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__53, *(int*)(&llvm_cbe_tmp__53));
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = load %%struct.F2D** %%tempOut, align 8, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_226_count);
  llvm_cbe_tmp__54 = (l_struct_OC_F2D *)*(&llvm_cbe_tempOut);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds %%struct.F2D* %%57, i64 0, i32 0, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_227_count);
  llvm_cbe_tmp__55 = (signed int *)(&llvm_cbe_tmp__54->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load i32* %%58, align 4, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_228_count);
  llvm_cbe_tmp__56 = (unsigned int )*llvm_cbe_tmp__55;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = mul nsw i32 %%59, %%storemerge19.us, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_229_count);
  llvm_cbe_tmp__57 = (unsigned int )((unsigned int )(llvm_cbe_tmp__56&4294967295ull)) * ((unsigned int )(llvm_cbe_storemerge19_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__57&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = add nsw i32 %%60, %%storemerge417.us, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_230_count);
  llvm_cbe_tmp__58 = (unsigned int )((unsigned int )(llvm_cbe_tmp__57&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge417_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__58&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = sext i32 %%61 to i64, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_231_count);
  llvm_cbe_tmp__59 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds %%struct.F2D* %%57, i64 0, i32 2, i64 %%62, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_232_count);
  llvm_cbe_tmp__60 = (float *)(&llvm_cbe_tmp__54->field2[(((signed long long )llvm_cbe_tmp__59))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__59));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%56, float* %%63, align 1, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_233_count);
  *llvm_cbe_tmp__60 = llvm_cbe_tmp__53;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = add nsw i32 %%storemerge417.us, 1, !dbg !12 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_234_count);
  llvm_cbe_tmp__61 = (unsigned int )((unsigned int )(llvm_cbe_storemerge417_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__61&4294967295ull)));
  if (((llvm_cbe_tmp__61&4294967295U) == (llvm_cbe_tmp__17&4294967295U))) {
    goto llvm_cbe_tmp__110;
  } else {
    llvm_cbe_storemerge417_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__61;   /* for PHI node */
    goto llvm_cbe__2e_preheader13_2e_us;
  }

  } while (1); /* end of syntactic loop '.preheader13.us' */
  } while (1); /* end of syntactic loop '.preheader13.lr.ph.us' */
llvm_cbe__2e_preheader9:
  if ((((signed int )llvm_cbe_tmp__18) > ((signed int )1u))) {
    goto llvm_cbe__2e_preheader7_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e_preheader9_2e_thread;
  }

llvm_cbe__2e_preheader7_2e_lr_2e_ph:
  if ((((signed int )llvm_cbe_tmp__17) > ((signed int )1u))) {
    llvm_cbe_storemerge110_2e_us__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge12;
  }

  do {     /* Syntactic loop '.preheader.lr.ph.us' to make GCC happy */
llvm_cbe__2e_preheader_2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge110.us = phi i32 [ %%68, %%67 ], [ 1, %%.preheader7.lr.ph  for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_storemerge110_2e_us_count);
  llvm_cbe_storemerge110_2e_us = (unsigned int )llvm_cbe_storemerge110_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge110.us = 0x%X",llvm_cbe_storemerge110_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__63);
printf("\n = 0x%X",1u);
}
  llvm_cbe_storemerge28_2e_us__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe__2e_preheader_2e_us;

llvm_cbe_tmp__111:
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = add nsw i32 %%storemerge110.us, 1, !dbg !11 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_266_count);
  llvm_cbe_tmp__63 = (unsigned int )((unsigned int )(llvm_cbe_storemerge110_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__63&4294967295ull)));
  if (((llvm_cbe_tmp__63&4294967295U) == (llvm_cbe_tmp__18&4294967295U))) {
    goto llvm_cbe__2e__crit_edge12;
  } else {
    llvm_cbe_storemerge110_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__63;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '.preheader.us' to make GCC happy */
llvm_cbe__2e_preheader_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge28.us = phi i32 [ 1, %%.preheader.lr.ph.us ], [ %%93, %%.preheader.us  for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_storemerge28_2e_us_count);
  llvm_cbe_storemerge28_2e_us = (unsigned int )llvm_cbe_storemerge28_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge28.us = 0x%X",llvm_cbe_storemerge28_2e_us);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",llvm_cbe_tmp__88);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = load %%struct.F2D** %%tempOut, align 8, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_289_count);
  llvm_cbe_tmp__64 = (l_struct_OC_F2D *)*(&llvm_cbe_tempOut);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = getelementptr inbounds %%struct.F2D* %%69, i64 0, i32 0, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_290_count);
  llvm_cbe_tmp__65 = (signed int *)(&llvm_cbe_tmp__64->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = load i32* %%70, align 4, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_291_count);
  llvm_cbe_tmp__66 = (unsigned int )*llvm_cbe_tmp__65;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = mul nsw i32 %%71, %%storemerge110.us, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_292_count);
  llvm_cbe_tmp__67 = (unsigned int )((unsigned int )(llvm_cbe_tmp__66&4294967295ull)) * ((unsigned int )(llvm_cbe_storemerge110_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__67&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = load %%struct.I2D** %%kernel_2, align 8, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_297_count);
  llvm_cbe_tmp__68 = (l_struct_OC_I2D *)*(&llvm_cbe_kernel_2);
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = add nsw i32 %%storemerge28.us, -1, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_298_count);
  llvm_cbe_tmp__69 = (unsigned int )((unsigned int )(llvm_cbe_storemerge28_2e_us&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__69&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = add nsw i32 %%74, %%72, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_299_count);
  llvm_cbe_tmp__70 = (unsigned int )((unsigned int )(llvm_cbe_tmp__69&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__67&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__70&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = sext i32 %%75 to i64, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_300_count);
  llvm_cbe_tmp__71 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = getelementptr inbounds %%struct.F2D* %%69, i64 0, i32 2, i64 %%76, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_301_count);
  llvm_cbe_tmp__72 = (float *)(&llvm_cbe_tmp__64->field2[(((signed long long )llvm_cbe_tmp__71))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__71));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = load float* %%77, align 1, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_302_count);
  llvm_cbe_tmp__73 = (float )*llvm_cbe_tmp__72;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__73, *(int*)(&llvm_cbe_tmp__73));
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = getelementptr inbounds %%struct.I2D* %%73, i64 0, i32 2, i64 0, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_303_count);
  llvm_cbe_tmp__74 = (signed int *)(&llvm_cbe_tmp__68->field2[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = load i32* %%79, align 1, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_304_count);
  llvm_cbe_tmp__75 = (unsigned int )*llvm_cbe_tmp__74;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = sitofp i32 %%80 to float, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_305_count);
  llvm_cbe_tmp__76 = (float )((float )(signed int )llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__76, *(int*)(&llvm_cbe_tmp__76));
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = fmul float %%78, %%81, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_306_count);
  llvm_cbe_tmp__77 = (float )((float )(llvm_cbe_tmp__73 * llvm_cbe_tmp__76));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__77, *(int*)(&llvm_cbe_tmp__77));
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = fadd float %%82, 0.000000e+00, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_307_count);
  llvm_cbe_tmp__78 = (float )((float )(llvm_cbe_tmp__77 + 0x0p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__78, *(int*)(&llvm_cbe_tmp__78));
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = add nsw i32 %%storemerge28.us, %%72, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_322_count);
  llvm_cbe_tmp__79 = (unsigned int )((unsigned int )(llvm_cbe_storemerge28_2e_us&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__67&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__79&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = sext i32 %%84 to i64, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_323_count);
  llvm_cbe_tmp__80 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__79);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = getelementptr inbounds %%struct.F2D* %%69, i64 0, i32 2, i64 %%85, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_324_count);
  llvm_cbe_tmp__81 = (float *)(&llvm_cbe_tmp__64->field2[(((signed long long )llvm_cbe_tmp__80))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__80));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = load float* %%86, align 1, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_325_count);
  llvm_cbe_tmp__82 = (float )*llvm_cbe_tmp__81;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__82, *(int*)(&llvm_cbe_tmp__82));
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = getelementptr inbounds %%struct.I2D* %%73, i64 0, i32 2, i64 1, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_326_count);
  llvm_cbe_tmp__83 = (signed int *)(&llvm_cbe_tmp__68->field2[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = load i32* %%88, align 1, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_327_count);
  llvm_cbe_tmp__84 = (unsigned int )*llvm_cbe_tmp__83;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = sitofp i32 %%89 to float, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_328_count);
  llvm_cbe_tmp__85 = (float )((float )(signed int )llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__85, *(int*)(&llvm_cbe_tmp__85));
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = fmul float %%87, %%90, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_329_count);
  llvm_cbe_tmp__86 = (float )((float )(llvm_cbe_tmp__82 * llvm_cbe_tmp__85));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__86, *(int*)(&llvm_cbe_tmp__86));
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = fadd float %%83, %%91, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_330_count);
  llvm_cbe_tmp__87 = (float )((float )(llvm_cbe_tmp__78 + llvm_cbe_tmp__86));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__87, *(int*)(&llvm_cbe_tmp__87));
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = add nsw i32 %%storemerge28.us, 1, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_345_count);
  llvm_cbe_tmp__88 = (unsigned int )((unsigned int )(llvm_cbe_storemerge28_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__88&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = add nsw i32 %%93, %%72, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_346_count);
  llvm_cbe_tmp__89 = (unsigned int )((unsigned int )(llvm_cbe_tmp__88&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__67&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__89&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = sext i32 %%94 to i64, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_347_count);
  llvm_cbe_tmp__90 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = getelementptr inbounds %%struct.F2D* %%69, i64 0, i32 2, i64 %%95, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_348_count);
  llvm_cbe_tmp__91 = (float *)(&llvm_cbe_tmp__64->field2[(((signed long long )llvm_cbe_tmp__90))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__90));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = load float* %%96, align 1, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_349_count);
  llvm_cbe_tmp__92 = (float )*llvm_cbe_tmp__91;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__92, *(int*)(&llvm_cbe_tmp__92));
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = getelementptr inbounds %%struct.I2D* %%73, i64 0, i32 2, i64 2, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_350_count);
  llvm_cbe_tmp__93 = (signed int *)(&llvm_cbe_tmp__68->field2[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = load i32* %%98, align 1, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_351_count);
  llvm_cbe_tmp__94 = (unsigned int )*llvm_cbe_tmp__93;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n  %%100 = sitofp i32 %%99 to float, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_352_count);
  llvm_cbe_tmp__95 = (float )((float )(signed int )llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__95, *(int*)(&llvm_cbe_tmp__95));
if (AESL_DEBUG_TRACE)
printf("\n  %%101 = fmul float %%97, %%100, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_353_count);
  llvm_cbe_tmp__96 = (float )((float )(llvm_cbe_tmp__92 * llvm_cbe_tmp__95));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__96, *(int*)(&llvm_cbe_tmp__96));
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = fadd float %%92, %%101, !dbg !10 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_354_count);
  llvm_cbe_tmp__97 = (float )((float )(llvm_cbe_tmp__87 + llvm_cbe_tmp__96));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__97, *(int*)(&llvm_cbe_tmp__97));
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = fmul float %%102, 2.500000e-01, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_369_count);
  llvm_cbe_tmp__98 = (float )((float )(llvm_cbe_tmp__97 * 0x1p-2));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__98, *(int*)(&llvm_cbe_tmp__98));
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = load %%struct.F2D** %%imageOut, align 8, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_374_count);
  llvm_cbe_tmp__99 = (l_struct_OC_F2D *)*(&llvm_cbe_imageOut);
if (AESL_DEBUG_TRACE)
printf("\n  %%105 = getelementptr inbounds %%struct.F2D* %%104, i64 0, i32 0, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_375_count);
  llvm_cbe_tmp__100 = (signed int *)(&llvm_cbe_tmp__99->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = load i32* %%105, align 4, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_376_count);
  llvm_cbe_tmp__101 = (unsigned int )*llvm_cbe_tmp__100;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__101);
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = mul nsw i32 %%106, %%storemerge110.us, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_377_count);
  llvm_cbe_tmp__102 = (unsigned int )((unsigned int )(llvm_cbe_tmp__101&4294967295ull)) * ((unsigned int )(llvm_cbe_storemerge110_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__102&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%108 = add nsw i32 %%107, %%storemerge28.us, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_378_count);
  llvm_cbe_tmp__103 = (unsigned int )((unsigned int )(llvm_cbe_tmp__102&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge28_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__103&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = sext i32 %%108 to i64, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_379_count);
  llvm_cbe_tmp__104 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__103);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__104);
if (AESL_DEBUG_TRACE)
printf("\n  %%110 = getelementptr inbounds %%struct.F2D* %%104, i64 0, i32 2, i64 %%109, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_380_count);
  llvm_cbe_tmp__105 = (float *)(&llvm_cbe_tmp__99->field2[(((signed long long )llvm_cbe_tmp__104))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__104));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%103, float* %%110, align 1, !dbg !8 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_381_count);
  *llvm_cbe_tmp__105 = llvm_cbe_tmp__98;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__98);
  if (((llvm_cbe_tmp__88&4294967295U) == (llvm_cbe_tmp__17&4294967295U))) {
    goto llvm_cbe_tmp__111;
  } else {
    llvm_cbe_storemerge28_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__88;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_us;
  }

  } while (1); /* end of syntactic loop '.preheader.us' */
  } while (1); /* end of syntactic loop '.preheader.lr.ph.us' */
llvm_cbe__2e__crit_edge12:
  goto llvm_cbe__2e_preheader9_2e_thread;

llvm_cbe__2e_preheader9_2e_thread:
if (AESL_DEBUG_TRACE)
printf("\n  %%111 = load %%struct.F2D** %%tempOut, align 8, !dbg !12 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_408_count);
  llvm_cbe_tmp__106 = (l_struct_OC_F2D *)*(&llvm_cbe_tempOut);
if (AESL_DEBUG_TRACE)
printf("\n  call void @fFreeHandle(%%struct.F2D* %%111) nounwind, !dbg !12 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_409_count);
  fFreeHandle((l_struct_OC_F2D *)llvm_cbe_tmp__106);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%112 = load %%struct.I2D** %%kernel_1, align 8, !dbg !12 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_416_count);
  llvm_cbe_tmp__107 = (l_struct_OC_I2D *)*(&llvm_cbe_kernel_1);
if (AESL_DEBUG_TRACE)
printf("\n  call void @iFreeHandle(%%struct.I2D* %%112) nounwind, !dbg !12 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_417_count);
  iFreeHandle((l_struct_OC_I2D *)llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%113 = load %%struct.I2D** %%kernel_2, align 8, !dbg !12 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_424_count);
  llvm_cbe_tmp__108 = (l_struct_OC_I2D *)*(&llvm_cbe_kernel_2);
if (AESL_DEBUG_TRACE)
printf("\n  call void @iFreeHandle(%%struct.I2D* %%113) nounwind, !dbg !12 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_425_count);
  iFreeHandle((l_struct_OC_I2D *)llvm_cbe_tmp__108);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%114 = load %%struct.F2D** %%imageOut, align 8, !dbg !12 for 0x%llxth hint within @calcSobel_dY  --> \n", ++aesl_llvm_cbe_432_count);
  llvm_cbe_tmp__109 = (l_struct_OC_F2D *)*(&llvm_cbe_imageOut);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @calcSobel_dY}\n");
  return llvm_cbe_tmp__109;
}

