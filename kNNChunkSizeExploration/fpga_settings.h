#ifndef SCENARIO
#define SCENARIO SCENARIO_gen100x8x10000_K20_FLOAT
#endif

#define SCENARIO_WISDM_K3_FLOAT 1
#define SCENARIO_WISDM_K3_DOUBLE 2
#define SCENARIO_WISDM_K20_FLOAT 3
#define SCENARIO_WISDM_K20_DOUBLE 4
#define SCENARIO_gen100x8x10000_K20_FLOAT 5
#define SCENARIO_gen100x8x10000_K20_DOUBLE 6
#define SCENARIO_gen100x8x50000_K20_FLOAT 7
#define SCENARIO_gen100x8x50000_K20_DOUBLE 8

#if SCENARIO == SCENARIO_WISDM_K3_FLOAT
#define N_TRAINING 4336
#define N_TESTING 1082
#define N_FEATURES 43
#define N_CLASSES 6
#define K 3
#define DATATYPE float
#endif

#if SCENARIO == SCENARIO_WISDM_K3_DOUBLE
#define N_TRAINING 4336
#define N_TESTING 1082
#define N_FEATURES 43
#define N_CLASSES 6
#define K 3
#define DATATYPE double
#endif

#if SCENARIO == SCENARIO_WISDM_K20_FLOAT
#define N_TRAINING 4336
#define N_TESTING 1082
#define N_FEATURES 43
#define N_CLASSES 6
#define K 20
#define DATATYPE float
#endif

#if SCENARIO == SCENARIO_WISDM_K20_DOUBLE
#define N_TRAINING 4336
#define N_TESTING 1082
#define N_FEATURES 43
#define N_CLASSES 6
#define K 20
#define DATATYPE double
#endif

#if SCENARIO == SCENARIO_gen100x8x10000_K20_FLOAT
#define N_TRAINING 8004
#define N_TESTING 1996	//previous: 1996
#define N_FEATURES 100
#define N_CLASSES 8
#define K 20
#define DATATYPE float
#endif

#if SCENARIO == SCENARIO_gen100x8x10000_K20_DOUBLE
#define N_TRAINING 8004
#define N_TESTING 1996
#define N_FEATURES 100
#define N_CLASSES 8
#define K 20
#define DATATYPE double
#endif

#if SCENARIO == SCENARIO_gen100x8x50000_K20_FLOAT
#define N_TRAINING 40002
#define N_TESTING 9998
#define N_FEATURES 100
#define N_CLASSES 8
#define K 20
#define DATATYPE float
#endif

#if SCENARIO == SCENARIO_gen100x8x50000_K20_DOUBLE
#define N_TRAINING 40002
#define N_TESTING 9998
#define N_FEATURES 100
#define N_CLASSES 8
#define K 20
#define DATATYPE double
#endif

#if NUM_CLASSES > 128
#define class_t short // consider 0..32767 classes and -1 for unknown
#else
#define class_t char // consider 0..127 classes and -1 for unknown
#endif
typedef DATATYPE datatype;
#define CLASS_TYPE class_t
#define DATA_TYPE datatype
