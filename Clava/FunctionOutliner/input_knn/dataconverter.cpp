#include "scenarios.h"

void convertStructsToArrays(Point training_points[N_TRAINING],
                            Point test_points[N_TESTING],
                            DATA_TYPE training_X[N_TRAINING][N_FEATURES],
                            CLASS_TYPE training_Y[N_TRAINING],
                            DATA_TYPE testing_X[N_TESTING][N_FEATURES],
                            CLASS_TYPE actual_testing_Y[N_TESTING])
{
    for (int i = 0; i < N_TRAINING; i++)
    {
        Point curr = training_points[i];

        for (int j = 0; j < N_FEATURES; j++)
        {
            training_X[i][j] = curr.features[j];
        }
        training_Y[i] = curr.classification_id;
    }

    for (int i = 0; i < N_TESTING; i++)
    {
        Point curr = test_points[i];

        for (int j = 0; j < N_FEATURES; j++)
        {
            testing_X[i][j] = curr.features[j];
        }
        actual_testing_Y[i] = curr.classification_id;
    }
}