/**
 * FEUP.DEI, v0.6 November 2021
 * Array version: May 2022
 */

#include <stdio.h>

#include "scenarios.h"
#include "dataconverter.h"
#include "utils.h"
#include "knn.h"

//{{{1,2,3,4,5},'a'}};
Point training_points[NUM_TRAINING_SAMPLES] = {
#include TRAINING_DATA_FILE
};

//{{{1,2,3,4,5},'a'}};
Point test_points[NUM_TESTING_SAMPLES] = {
#include TEST_DATA_FILE
};

#if VERIFY == 1 // verify if classifications are still the original
unsigned char key[NUM_TESTING_SAMPLES] = {
#include VERIFICATION_DATA_FILE
};
#endif

int main(int argc, char **argv)
{
    printf("Data points initialized with dataset...\n");

#if NORMALIZE == 1 // minmax normalization
    datatype min[NUM_FEATURES];
    datatype max[NUM_FEATURES];

    // determine min and max from known points
    minmax(min, max, NUM_TRAINING_SAMPLES, training_points, NUM_FEATURES);

    // normalize known points
    minmax_normalize(min, max, NUM_TRAINING_SAMPLES, training_points,
                     NUM_FEATURES);
#endif

#if ACCURACY == 1
    int fail = 0; // count the number of test instances incorrectly classified
#endif

    DATA_TYPE training_X[N_TRAINING][N_FEATURES] = {0};
    CLASS_TYPE training_Y[N_TRAINING] = {0};
    DATA_TYPE testing_X[N_TESTING][N_FEATURES] = {0};
    CLASS_TYPE actual_testing_Y[N_TESTING] = {0};
    CLASS_TYPE predicted_testing_Y[N_TESTING] = {0};

    printf("Converting structs to arrays...\n");
    convertStructsToArrays(training_points, test_points, training_X, training_Y,
                           testing_X, actual_testing_Y);
    printf("Finished converting structs to arrays\n");

    printf("Executing kNN with arrays...\n");
    Timer *timer = timer_init();

    // kNN itself
    timer_start(timer);
    kNN_PredictAll(training_X, training_Y, testing_X, predicted_testing_Y, min, max);
    timer_stop(timer);

#if ACCURACY == 1
    for (int i = 0; i < N_TESTING; i++)
    {
        if (actual_testing_Y[i] != predicted_testing_Y[i])
        {
            fail++;
        }
    }
#endif

    printf("kNN done.\n\n");

    printf("kNN: number of classes = %d\n", NUM_CLASSES);
    printf("kNN: number of training instances = %d\n", NUM_TRAINING_SAMPLES);
    printf("kNN: number of features = %d\n", NUM_FEATURES);
    printf("kNN: k = %d\n", K);

    printf("kNN: number of classified instances = %d\n", NUM_TESTING_SAMPLES);

#if ACCURACY == 1
    printf("kNN: number of classifications wrong = %d\n", fail);
    printf("kNN: number of classifications right = %d\n",
           NUM_TESTING_SAMPLES - fail);
    printf("kNN: accuracy = %.2f %c\n\n",
           100 * (float)(NUM_TESTING_SAMPLES - fail) / (float)NUM_TESTING_SAMPLES, '%');
#endif

#if VERIFY == 1
    verify_results(N_TESTING, predicted_testing_Y, key);
#endif

#if TIMMING == 1
    const double time = timer_get_s(timer);
    printf("\nTime:  %.4f s\n", time);
    timer = timer_destroy(timer);
#endif

    return 0;
}
