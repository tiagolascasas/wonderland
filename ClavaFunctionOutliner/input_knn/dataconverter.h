#pragma once

#include "scenarios.h"

void convertStructsToArrays(Point training_points[N_TRAINING],
                            Point test_points[N_TESTING],
                            DATA_TYPE training_X[N_TRAINING][N_FEATURES],
                            CLASS_TYPE training_Y[N_TRAINING],
                            DATA_TYPE testing_X[N_TESTING][N_FEATURES],
                            CLASS_TYPE actual_testing_Y[N_TESTING]);