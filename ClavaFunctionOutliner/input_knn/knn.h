#pragma once

#include "scenarios.h"

void kNN_PredictAll(DATA_TYPE training_X[N_TRAINING][N_FEATURES],
                    CLASS_TYPE training_Y[N_TRAINING],
                    DATA_TYPE testing_X[N_TESTING][N_FEATURES],
                    CLASS_TYPE testing_Y[N_TESTING], DATA_TYPE min[N_FEATURES],
                    DATA_TYPE max[N_FEATURES]);
