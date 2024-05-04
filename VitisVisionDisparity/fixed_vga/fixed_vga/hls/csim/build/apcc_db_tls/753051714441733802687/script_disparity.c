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
typedef struct l_struct_OC_timespec l_struct_OC_timespec;
typedef struct l_struct_OC__IO_FILE l_struct_OC__IO_FILE;

/* Structure contents */
struct l_struct_OC_I2D {
  unsigned int field0;
  unsigned int field1;
  signed int field2[307200];
};

struct l_struct_OC_timespec {
  unsigned long long field0;
  unsigned long long field1;
};

struct l_struct_OC__IO_FILE {
  unsigned int field0;
   char *field1;
   char *field2;
   char *field3;
   char *field4;
   char *field5;
   char *field6;
   char *field7;
   char *field8;
   char *field9;
   char *field10;
   char *field11;
  l_struct_OC_I2D *field12;
  l_struct_OC__IO_FILE *field13;
  unsigned int field14;
  unsigned int field15;
  unsigned long long field16;
  unsigned short field17;
  unsigned char field18;
   char field19[1];
   char *field20;
  unsigned long long field21;
  l_struct_OC_I2D *field22;
  l_struct_OC_I2D *field23;
  l_struct_OC__IO_FILE *field24;
   char *field25;
  unsigned long long field26;
  unsigned int field27;
   char field28[20];
};


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int main(signed int llvm_cbe_argc,  char **llvm_cbe_argv);
l_struct_OC_I2D *readImage( char *);
signed int *photonStartTiming();
void getDisparity(l_struct_OC_I2D *, l_struct_OC_I2D *, signed int , signed int , l_struct_OC_I2D **);
signed int *photonEndTiming();
signed int *photonReportTiming(signed int *, signed int *);
void photonPrintTiming(signed int *);
void iFreeHandle(l_struct_OC_I2D *);


/* Global Variable Definitions and Initialization */
static  char aesl_internal_str[37] = "Error opening file app_exec_time.csv";
static  char aesl_internal__OC_str1[3] = "w+";
static  char aesl_internal__OC_str7[23] = "Input size\t\t- (%dx%d)\n";
static  char aesl_internal__OC_str[18] = "app_exec_time.csv";
static  char aesl_internal__OC_str4[9] = "%s/1.bmp";
static  char aesl_internal_str1[41] = "We need input image path and output path";
static  char aesl_internal__OC_str6[6] = "%fus\n";
static  char aesl_internal__OC_str5[9] = "%s/2.bmp";


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

signed int main(signed int llvm_cbe_argc,  char **llvm_cbe_argv) {
  static  unsigned long long aesl_llvm_cbe_retDisparity_count = 0;
  l_struct_OC_I2D *llvm_cbe_retDisparity;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_im1_count = 0;
   char llvm_cbe_im1[100];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_im2_count = 0;
   char llvm_cbe_im2[100];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_clava_timing_start_0_count = 0;
  l_struct_OC_timespec llvm_cbe_clava_timing_start_0;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_clava_timing_end_0_count = 0;
  l_struct_OC_timespec llvm_cbe_clava_timing_end_0;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  l_struct_OC__IO_FILE *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
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
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts1_count = 0;
  unsigned int llvm_cbe_puts1;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
   char *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
   char **llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
   char *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
   char *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
   char *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  signed int *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  signed int *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  signed int *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  signed long long *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned long long llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  double llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  signed long long *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned long long llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  double llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  double llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  double llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  signed long long *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  unsigned long long llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  double llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  signed long long *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  unsigned long long llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  double llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  double llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  double llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  double llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  double llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned int llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  signed int *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  signed int *llvm_cbe_tmp__40;
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
  l_struct_OC_I2D *llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
   char *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
   char *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
   char *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  unsigned int llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call noalias %%struct._IO_FILE* @fopen(i8* getelementptr inbounds ([18 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* getelementptr inbounds ([3 x i8]* @aesl_internal_.str1, i64 0, i64 0)) nounwind, !dbg !9 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_6_count);
  llvm_cbe_tmp__1 = (l_struct_OC__IO_FILE *)aesl_fopen(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 18
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1);
}
  if (((llvm_cbe_tmp__1) == (((l_struct_OC__IO_FILE *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__46;
  } else {
    goto llvm_cbe_tmp__47;
  }

llvm_cbe_tmp__46:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([37 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 37
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @exit(i32 1) noreturn nounwind, !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_14_count);
  exit(1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__47:
  if ((((signed int )llvm_cbe_argc) < ((signed int )2u))) {
    goto llvm_cbe_tmp__48;
  } else {
    goto llvm_cbe_tmp__49;
  }

llvm_cbe_tmp__48:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts1 = call i32 @puts(i8* getelementptr inbounds ([41 x i8]* @aesl_internal_str1, i64 0, i64 0)), !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_puts1_count);
  puts(( char *)((&aesl_internal_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 41
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts1 = 0x%X",llvm_cbe_puts1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = call i32 @fclose(%%struct._IO_FILE* %%1) nounwind, !dbg !9 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_29_count);
  fclose((l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
  goto llvm_cbe_tmp__50;

llvm_cbe_tmp__49:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds [100 x i8]* %%im1, i64 0, i64 0, !dbg !9 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__3 = ( char *)(&llvm_cbe_im1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 100
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i8** %%argv, i64 1, !dbg !9 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__4 = ( char **)(&llvm_cbe_argv[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i8** %%10, align 8, !dbg !9 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__5 = ( char *)*llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = call i32 (i8*, i8*, ...)* @sprintf(i8* %%9, i8* getelementptr inbounds ([9 x i8]* @aesl_internal_.str4, i64 0, i64 0), i8* %%11) nounwind, !dbg !9 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_34_count);
  sprintf(( char *)llvm_cbe_tmp__3, ( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
])), ( char *)llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [100 x i8]* %%im2, i64 0, i64 0, !dbg !9 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__7 = ( char *)(&llvm_cbe_im2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 100
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i8** %%10, align 8, !dbg !9 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__8 = ( char *)*llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = call i32 (i8*, i8*, ...)* @sprintf(i8* %%13, i8* getelementptr inbounds ([9 x i8]* @aesl_internal_.str5, i64 0, i64 0), i8* %%14) nounwind, !dbg !9 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_37_count);
  sprintf(( char *)llvm_cbe_tmp__7, ( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
])), ( char *)llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = call %%struct.I2D* @readImage(i8* %%9) nounwind, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__10 = (l_struct_OC_I2D *)readImage(( char *)llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__10);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = call %%struct.I2D* @readImage(i8* %%13) nounwind, !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__11 = (l_struct_OC_I2D *)readImage(( char *)llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__11);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds %%struct.I2D* %%16, i64 0, i32 1, !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__12 = (signed int *)(&llvm_cbe_tmp__10->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i32* %%18, align 4, !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__13 = (unsigned int )*llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds %%struct.I2D* %%16, i64 0, i32 0, !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__14 = (signed int *)(&llvm_cbe_tmp__10->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i32* %%20, align 4, !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_53_count);
  llvm_cbe_tmp__15 = (unsigned int )*llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = call i32* (...)* @photonStartTiming() nounwind, !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__16 = (signed int *)photonStartTiming();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__16);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = call i32 @clock_gettime(i32 1, %%struct.timespec* %%clava_timing_start_0) nounwind, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_62_count);
  clock_gettime(1u, (l_struct_OC_timespec *)(&llvm_cbe_clava_timing_start_0));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__17);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @getDisparity(%%struct.I2D* %%16, %%struct.I2D* %%17, i32 8, i32 64, %%struct.I2D** %%retDisparity) nounwind, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_63_count);
  getDisparity((l_struct_OC_I2D *)llvm_cbe_tmp__10, (l_struct_OC_I2D *)llvm_cbe_tmp__11, 8u, 64u, (l_struct_OC_I2D **)(&llvm_cbe_retDisparity));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",8u);
printf("\nArgument  = 0x%X",64u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = call i32 @clock_gettime(i32 1, %%struct.timespec* %%clava_timing_end_0) nounwind, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_64_count);
  clock_gettime(1u, (l_struct_OC_timespec *)(&llvm_cbe_clava_timing_end_0));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__18);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.timespec* %%clava_timing_end_0, i64 0, i32 0, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__19 = (signed long long *)(&llvm_cbe_clava_timing_end_0.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i64* %%25, align 8, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__20 = (unsigned long long )*llvm_cbe_tmp__19;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = sitofp i64 %%26 to double, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__21 = (double )((double )(signed long long )llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__21, *(long long*)(&llvm_cbe_tmp__21));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds %%struct.timespec* %%clava_timing_end_0, i64 0, i32 1, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__22 = (signed long long *)(&llvm_cbe_clava_timing_end_0.field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i64* %%28, align 8, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__23 = (unsigned long long )*llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = sitofp i64 %%29 to double, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__24 = (double )((double )(signed long long )llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__24, *(long long*)(&llvm_cbe_tmp__24));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = fdiv double %%30, 1.000000e+09, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__25 = (double )llvm_cbe_tmp__24 / 0x1.dcd65p29;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__25, *(long long*)(&llvm_cbe_tmp__25));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = fadd double %%27, %%31, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_72_count);
  llvm_cbe_tmp__26 = (double )llvm_cbe_tmp__21 + llvm_cbe_tmp__25;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__26, *(long long*)(&llvm_cbe_tmp__26));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds %%struct.timespec* %%clava_timing_start_0, i64 0, i32 0, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_73_count);
  llvm_cbe_tmp__27 = (signed long long *)(&llvm_cbe_clava_timing_start_0.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i64* %%33, align 8, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__28 = (unsigned long long )*llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = sitofp i64 %%34 to double, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__29 = (double )((double )(signed long long )llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__29, *(long long*)(&llvm_cbe_tmp__29));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds %%struct.timespec* %%clava_timing_start_0, i64 0, i32 1, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__30 = (signed long long *)(&llvm_cbe_clava_timing_start_0.field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load i64* %%36, align 8, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__31 = (unsigned long long )*llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = sitofp i64 %%37 to double, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__32 = (double )((double )(signed long long )llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__32, *(long long*)(&llvm_cbe_tmp__32));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = fdiv double %%38, 1.000000e+09, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__33 = (double )llvm_cbe_tmp__32 / 0x1.dcd65p29;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__33, *(long long*)(&llvm_cbe_tmp__33));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = fadd double %%35, %%39, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__34 = (double )llvm_cbe_tmp__29 + llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__34, *(long long*)(&llvm_cbe_tmp__34));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = fsub double %%32, %%40, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__35 = (double )llvm_cbe_tmp__26 - llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__35, *(long long*)(&llvm_cbe_tmp__35));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = fmul double %%41, 1.000000e+06, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__36 = (double )llvm_cbe_tmp__35 * 0x1.e848p19;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__36, *(long long*)(&llvm_cbe_tmp__36));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = call i32 (%%struct._IO_FILE*, i8*, ...)* @fprintf(%%struct._IO_FILE* %%1, i8* getelementptr inbounds ([6 x i8]* @aesl_internal_.str6, i64 0, i64 0), double %%42) nounwind, !dbg !9 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_85_count);
  fprintf((l_struct_OC__IO_FILE *)llvm_cbe_tmp__1, ( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])), llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__36, *(long long*)(&llvm_cbe_tmp__36));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = call i32* (...)* @photonEndTiming() nounwind, !dbg !16 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__38 = (signed int *)photonEndTiming();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__38);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([23 x i8]* @aesl_internal_.str7, i64 0, i64 0), i32 %%19, i32 %%21) nounwind, !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_90_count);
  printf(( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 23
#endif
])), llvm_cbe_tmp__13, llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__13);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__15);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__39);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = call i32* @photonReportTiming(i32* %%22, i32* %%44) nounwind, !dbg !15 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__40 = (signed int *)photonReportTiming((signed int *)llvm_cbe_tmp__16, (signed int *)llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__40);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @photonPrintTiming(i32* %%46) nounwind, !dbg !17 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_95_count);
  photonPrintTiming((signed int *)llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @iFreeHandle(%%struct.I2D* %%16) nounwind, !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_96_count);
  iFreeHandle((l_struct_OC_I2D *)llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @iFreeHandle(%%struct.I2D* %%17) nounwind, !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_97_count);
  iFreeHandle((l_struct_OC_I2D *)llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load %%struct.I2D** %%retDisparity, align 8, !dbg !17 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__41 = (l_struct_OC_I2D *)*(&llvm_cbe_retDisparity);
if (AESL_DEBUG_TRACE)
printf("\n  call void @iFreeHandle(%%struct.I2D* %%47) nounwind, !dbg !17 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_105_count);
  iFreeHandle((l_struct_OC_I2D *)llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = bitcast i32* %%22 to i8*, !dbg !15 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__42 = ( char *)(( char *)llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  call void @free(i8* %%48) nounwind, !dbg !15 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_107_count);
  free(( char *)llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = bitcast i32* %%44 to i8*, !dbg !17 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__43 = ( char *)(( char *)llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  call void @free(i8* %%49) nounwind, !dbg !17 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_109_count);
  free(( char *)llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = bitcast i32* %%46 to i8*, !dbg !17 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_110_count);
  llvm_cbe_tmp__44 = ( char *)(( char *)llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE)
printf("\n  call void @free(i8* %%50) nounwind, !dbg !17 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_111_count);
  free(( char *)llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = call i32 @fclose(%%struct._IO_FILE* %%1) nounwind, !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_112_count);
  fclose((l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__45);
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__50;

llvm_cbe_tmp__50:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i32 [ -1, %%6 ], [ 0, %%8  for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_storemerge;
}

