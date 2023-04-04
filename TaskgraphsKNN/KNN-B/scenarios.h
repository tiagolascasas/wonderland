/**
 * FEUP.DEI, v0.6 November 2021
 * Vitis HLS version Feburary 2023
 */
#ifndef __SCENARIOS_H__
#define __SCENARIOS_H__

///////////////////////////////////////////////////////////////////////////////
//                    TURN ON SIMPLIFIED VITIS HLS VERSION                   //
///////////////////////////////////////////////////////////////////////////////

//#define VITIS_HLS

///////////////////////////////////////////////////////////////////////////////
//                         CHOOSE YOUR SCENARIO HERE                         //
///////////////////////////////////////////////////////////////////////////////

#ifndef SCENARIO
#define SCENARIO GB_K20_F
#endif

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

#ifdef VITIS_HLS
#if SCENARIO == WI_K3_F
#define N_TRAINING 4336
#define N_TESTING 1082
#define N_FEATURES 43
#define N_CLASSES 6
#define K 3
#define DATA_TYPE float
#endif
#if SCENARIO == WI_K3_D
#define N_TRAINING 4336
#define N_TESTING 1082
#define N_FEATURES 43
#define N_CLASSES 6
#define K 3
#define DATA_TYPE double
#endif
#if SCENARIO == WI_K20_F
#define N_TRAINING 4336
#define N_TESTING 1082
#define N_FEATURES 43
#define N_CLASSES 6
#define K 20
#define DATA_TYPE float
#endif
#if SCENARIO == WI_K20_D
#define N_TRAINING 4336
#define N_TESTING 1082
#define N_FEATURES 43
#define N_CLASSES 6
#define K 20
#define DATA_TYPE double
#endif
#if SCENARIO == GA_K20_F
#define N_TRAINING 8004
#define N_TESTING 100 // prev: 1996
#define N_FEATURES 100
#define N_CLASSES 8
#define K 20
#define DATA_TYPE float
#endif
#if SCENARIO == GA_K20_D
#define N_TRAINING 8004
#define N_TESTING 1996
#define N_FEATURES 100
#define N_CLASSES 8
#define K 20
#define DATA_TYPE double
#endif
#if SCENARIO == GB_K20_F
#define N_TRAINING 40002
#define N_TESTING 9998
#define N_FEATURES 100
#define N_CLASSES 8
#define K 20
#define DATA_TYPE float
#endif
#if SCENARIO == GB_K20_D
#define N_TRAINING 40002
#define N_TESTING 9998
#define N_FEATURES 100
#define N_CLASSES 8
#define K 20
#define DATA_TYPE double
#endif

#if N_CLASSES > 128
#define class_t short // consider 0..32767 classes and -1 for unknown
#else
#define class_t char // consider 0..127 classes and -1 for unknown
#endif
#define CLASS_TYPE class_t

#else
// clang-format off
#define DATASETS_DIRECTORY ./datasets

#if SCENARIO == WI_K3_F
#define SCENARIO_FILE params-k3-float.h
#define SCENARIO_DIRECTORY scenario-wisdm
#elif SCENARIO == WI_K3_D
#define SCENARIO_FILE params-k3-double.h
#define SCENARIO_DIRECTORY scenario-wisdm
#elif SCENARIO == WI_K20_F
#define SCENARIO_FILE params-k20-float.h
#define SCENARIO_DIRECTORY scenario-wisdm
#elif SCENARIO == WI_K20_D
#define SCENARIO_FILE params-k20-double.h
#define SCENARIO_DIRECTORY scenario-wisdm
#elif SCENARIO == GA_K20_F
#define SCENARIO_FILE params-k20-float.h
#define SCENARIO_DIRECTORY scenario-gen100x8x10000
#elif SCENARIO == GA_K20_D
#define SCENARIO_FILE params-k20-double.h
#define SCENARIO_DIRECTORY scenario-gen100x8x10000
#elif SCENARIO == GB_K20_F
#define SCENARIO_FILE params-k20-float.h
#define SCENARIO_DIRECTORY scenario-gen100x8x50000
#elif SCENARIO == GB_K20_D
#define SCENARIO_FILE params-k20-double.h
#define SCENARIO_DIRECTORY scenario-gen100x8x50000
#endif

// clang-format on

///////////////////////////////////////////////////////////////////////////////
//                                 DEFAULTS                                  //
///////////////////////////////////////////////////////////////////////////////
#include <float.h>
#include <stdint.h>

// clang-format off
#define STR(x) #x
#define PATH_BUILDER(directory, scenarioDirectory, scenarioFile) STR(directory/scenarioDirectory/scenarioFile)
#define SCENARIO_PARAMS PATH_BUILDER(DATASETS_DIRECTORY, SCENARIO_DIRECTORY, SCENARIO_FILE)
// clang-format on

#include SCENARIO_PARAMS

#ifndef DATATYPE
#warning("DATATYPE not set by scenario.")
#define DATATYPE float
#endif
typedef DATATYPE datatype;

#define FP_TYPE_float 1
#define FP_TYPE_double 2

#define _FP_TYPE(x) FP_TYPE_##x
#define FP_TYPE(x) _FP_TYPE(x)

#if FP_TYPE(DATATYPE) == FP_TYPE_double
#define MAX_FP_VAL DBL_MAX
#define MIN_FP_VAL -DBL_MAX
#elif FP_TYPE(DATATYPE) == FP_TYPE_float
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

#if TIMMING == 1
#include "timer.h"
#endif

#if NUM_CLASSES > 128
#define class_t short // consider 0..32767 classes and -1 for unknown
#else
#define class_t char // consider 0..127 classes and -1 for unknown
#endif

typedef struct
{
    datatype features[NUM_FEATURES];
    class_t classification_id;
} Point;

typedef struct
{
    class_t classification_id;
    datatype distance;
} BestPoint;

#define TRAINING_DATA_FILE                               \
    PATH_BUILDER(DATASETS_DIRECTORY, SCENARIO_DIRECTORY, \
                 TRAINING_DATA_FILE_NAME)

#define TEST_DATA_FILE \
    PATH_BUILDER(DATASETS_DIRECTORY, SCENARIO_DIRECTORY, TEST_DATA_FILE_NAME)

#define VERIFICATION_DATA_FILE                           \
    PATH_BUILDER(DATASETS_DIRECTORY, SCENARIO_DIRECTORY, \
                 VERIFICATION_DATA_FILE_NAME)

// these are just some aliases for the macros used in knn_arrays
// hopefully they will not cause any issues
#define N_TRAINING NUM_TRAINING_SAMPLES
#define N_FEATURES NUM_FEATURES
#define N_TESTING NUM_TESTING_SAMPLES
#define N_CLASSES NUM_CLASSES

#define CLASS_TYPE class_t
#define DATA_TYPE datatype

#endif

#endif
