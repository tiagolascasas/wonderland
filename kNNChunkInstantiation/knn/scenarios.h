/**
 * FEUP.DEI, v0.6 November 2021
 * Vitis HLS version Feburary 2023
 */
#pragma once

#include <cfloat>
#include <cstdint>
#include "design_params.h"

///////////////////////////////////////////////////////////////////////////////
//                    TURN ON SIMPLIFIED VITIS HLS VERSION                   //
///////////////////////////////////////////////////////////////////////////////

#define VITIS_HLS

///////////////////////////////////////////////////////////////////////////////
//                                 SETTINGS                                  //
///////////////////////////////////////////////////////////////////////////////
#define WI_K3_F 1
#define WI_K3_D 2
#define WI_K20_F 3
#define WI_K20_D 4
#define GA_K20_F 5
#define GA_K20_D 6
#define GB_K20_F 7
#define GB_K20_D 8

#if SCENARIO == WI_K3_F
#define N_TRAINING 4336
#define N_TESTING 1082
#define N_FEATURES 43
#define N_CLASSES 6
#define TRAINING_DATA_FILE "wisdm-train.dat"
#define TEST_DATA_FILE "wisdm-test.dat"
#define TIMMING 1
#define ACCURACY 1
#define NORMALIZE 1
#define K 3
#define DATA_TYPE float
#define VERIFY 1
#define VERIFICATION_DATA_FILE "key-wisdm-k3.dat"
#elif SCENARIO == WI_K3_D
#define N_TRAINING 4336
#define N_TESTING 1082
#define N_FEATURES 43
#define N_CLASSES 6
#define TRAINING_DATA_FILE "wisdm-train.dat"
#define TEST_DATA_FILE "wisdm-test.dat"
#define TIMMING 1
#define ACCURACY 1
#define NORMALIZE 1
#define K 3
#define DATA_TYPE double
#define VERIFY 1
#define VERIFICATION_DATA_FILE "key-wisdm-k3.dat"
#elif SCENARIO == WI_K20_F
#define N_TRAINING 4336
#define N_TESTING 1082
#define N_FEATURES 43
#define N_CLASSES 6
#define TRAINING_DATA_FILE "wisdm-train.dat"
#define TEST_DATA_FILE "wisdm-test.dat"
#define TIMMING 1
#define ACCURACY 1
#define NORMALIZE 1
#define K 20
#define DATA_TYPE float
#define VERIFY 1
#define VERIFICATION_DATA_FILE "key-wisdm-k20.dat"
#elif SCENARIO == WI_K20_D
#define N_TRAINING 4336
#define N_TESTING 1082
#define N_FEATURES 43
#define N_CLASSES 6
#define TRAINING_DATA_FILE "wisdm-train.dat"
#define TEST_DATA_FILE "wisdm-test.dat"
#define TIMMING 1
#define ACCURACY 1
#define NORMALIZE 1
#define K 20
#define DATA_TYPE double
#define VERIFY 1
#define VERIFICATION_DATA_FILE "key-wisdm-k20.dat"
#elif SCENARIO == GA_K20_F
#define N_TRAINING 8004
#define N_TESTING 1996
#define N_FEATURES 100
#define N_CLASSES 8
#define TRAINING_DATA_FILE "ga-train.dat"
#define TEST_DATA_FILE "ga-test.dat"
#define TIMMING 1
#define ACCURACY 1
#define NORMALIZE 1
#define K 20
#define DATA_TYPE float
#define VERIFY 1
#define VERIFICATION_DATA_FILE "key-ga-k20.dat"
#elif SCENARIO == GA_K20_D
#define N_TRAINING 8004
#define N_TESTING 1996
#define N_FEATURES 100
#define N_CLASSES 8
#define TRAINING_DATA_FILE "ga-train.dat"
#define TEST_DATA_FILE "ga-test.dat"
#define TIMMING 1
#define ACCURACY 1
#define NORMALIZE 1
#define K 20
#define DATA_TYPE double
#define VERIFY 1
#define VERIFICATION_DATA_FILE "key-ga-k20.dat"
#elif SCENARIO == GB_K20_F
#define N_TRAINING 40002
#define N_TESTING 9998
#define N_FEATURES 100
#define N_CLASSES 8
#define TRAINING_DATA_FILE "gb-train.dat"
#define TEST_DATA_FILE "gb-test.dat"
#define TIMMING 1
#define ACCURACY 1
#define NORMALIZE 1
#define K 20
#define DATA_TYPE float
#define VERIFY 1
#define VERIFICATION_DATA_FILE "key-gb-k20.dat"
#elif SCENARIO == GB_K20_D
#define N_TRAINING 40002
#define N_TESTING 9998
#define N_FEATURES 100
#define N_CLASSES 8
#define TRAINING_DATA_FILE "gb-train.dat"
#define TEST_DATA_FILE "gb-test.dat"
#define TIMMING 1
#define ACCURACY 1
#define NORMALIZE 1
#define K 20
#define DATA_TYPE double
#define VERIFY 1
#define VERIFICATION_DATA_FILE "key-gb-k20.dat"
#endif

///////////////////////////////////////////////////////////////////////////////
//                                 DEFAULTS                                  //
///////////////////////////////////////////////////////////////////////////////

#ifndef DATA_TYPE
#warning("DATATYPE not set by scenario.")
#define DATA_TYPE float
#endif
typedef DATA_TYPE datatype;

#define FP_TYPE_float 1
#define FP_TYPE_double 2

#define _FP_TYPE(x) FP_TYPE_##x
#define FP_TYPE(x) _FP_TYPE(x)

#if FP_TYPE(DATA_TYPE) == FP_TYPE_double
#define MAX_FP_VAL DBL_MAX
#define MIN_FP_VAL -DBL_MAX
#elif FP_TYPE(DATA_TYPE) == FP_TYPE_float
#define MAX_FP_VAL FLT_MAX
#define MIN_FP_VAL -FLT_MAX
#else
#error("Unrecognized DATATYPE")
#define MAX_FP_VAL unknown
#define MIN_FP_VAL unknown
#endif

#ifndef TIMMING
#warning("TIMING not set by scenario.")
/**
 * 0: without
 * 1: Linux/Windows
 * 2: specific timers (not implemented)
 */
#define TIMMING 1
#endif

#ifndef VERIFY
#warning("VERIFY not set by scenario.")
/**
 * 0: none verification;
 * 1: to verify if the results are according to the ones expected only for READ
 * 	= 1, scenario A1, or READ = 2
 */
#define VERIFY 0
#endif

#ifndef ACCURACY
#warning("ACCURACY not set by scenario.")
/**
 * 0: no
 * 1: to report the accuracy of the classification only used for READ = 1 or
 * 	READ = 2
 */
#define ACCURACY 1
#endif

#ifndef NORMALIZE
#warning("NORMALIZE not set by scenario.")
/**
 * 0: nothing
 * 1: minmax normalization of features
 */
#define NORMALIZE 1
#endif

#if N_CLASSES > 128
#define CLASS_TYPE short // consider 0..32767 classes and -1 for unknown
#else
#define CLASS_TYPE char // consider 0..127 classes and -1 for unknown
#endif

typedef struct Point Point;
typedef struct BestPoint BestPoint;

struct Point
{
    DATA_TYPE features[N_FEATURES];
    CLASS_TYPE classification_id;
};

struct BestPoint
{
    CLASS_TYPE classification_id;
    DATA_TYPE distance;
};
