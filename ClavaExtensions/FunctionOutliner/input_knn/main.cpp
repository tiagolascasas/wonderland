/**
 * FEUP.DEI, v0.6 November 2021
 * Array version: May 2022
 */

#include <cstdio>
#include <chrono>

#include "scenarios.h"
#include "dataconverter.h"
#include "utils.h"
#include "knn.h"

using namespace std;
using namespace std::chrono;

//{{{1,2,3,4,5},'a'}};
Point training_points[N_TRAINING] = {
#include TRAINING_DATA_FILE
};

//{{{1,2,3,4,5},'a'}};
Point test_points[N_TESTING] = {
#include TEST_DATA_FILE
};

#if VERIFY == 1 // verify if classifications are still the original
const char key[N_TESTING] = {
#include VERIFICATION_DATA_FILE
};
#endif

int main(int argc, char **argv)
{
    printf("Data points initialized with dataset...\n");

#if NORMALIZE == 1 // minmax normalization
    datatype min[N_FEATURES];
    datatype max[N_FEATURES];

    // determine min and max from known points
    minmax(min, max, N_TRAINING, training_points, N_FEATURES);

    // normalize known points
    minmax_normalize(min, max, N_TRAINING, training_points, N_FEATURES);
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

    auto start = high_resolution_clock::now();
    kNN_PredictAll(training_X, training_Y, testing_X, predicted_testing_Y, min, max);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

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

    printf("kNN: number of classes = %d\n", N_CLASSES);
    printf("kNN: number of training instances = %d\n", N_TRAINING);
    printf("kNN: number of features = %d\n", N_FEATURES);
    printf("kNN: k = %d\n", K);

    printf("kNN: number of classified instances = %d\n", N_TESTING);

#if ACCURACY == 1
    printf("kNN: number of classifications wrong = %d\n", fail);
    printf("kNN: number of classifications right = %d\n", N_TESTING - fail);
    printf("kNN: accuracy = %.2f %c\n\n", 100 * (float)(N_TESTING - fail) / (float)N_TESTING, '%');
#endif

#if VERIFY == 1
    verify_results(N_TESTING, predicted_testing_Y, key);
#endif

#if TIMMING == 1
    printf("\nTime: %ld us\n", duration.count());
#endif

    return 0;
}
