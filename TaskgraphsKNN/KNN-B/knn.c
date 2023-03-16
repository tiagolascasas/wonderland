#include <float.h>
#include <math.h>
#include "scenarios.h"

void kNN_UpdateBest(double queryDistance, int queryIdx,
                    double bestDistances[K], int bestPointsIdx[K])
{
    double worstOfBest = 0;
    int worstOfBestIdx = -1;

    for (int i = 0; i < K; i++)
    {
        if (bestDistances[i] > worstOfBest)
        {
            worstOfBest = bestDistances[i];
            worstOfBestIdx = i;
        }
    }

    if (queryDistance < worstOfBest)
    {
        bestDistances[worstOfBestIdx] = queryDistance;
        bestPointsIdx[worstOfBestIdx] = queryIdx;
    }
}

void kNN_InitBest(double bestDistances[K], int bestPointsIdx[K])
{
    for (int i = 0; i < K; i++)
    {
        bestDistances[i] = DBL_MAX;
        bestPointsIdx[i] = -1;
    }
}

void kNN_VoteBetweenBest(int bestPointsIdx[K], CLASS_TYPE training_Y[N_TRAINING], CLASS_TYPE *voteResult)
{
    CLASS_TYPE histogram[N_CLASSES] = {0};

    for (int i = 0; i < K; i++)
    {
        int bestIdx = bestPointsIdx[i];
        CLASS_TYPE cl = training_Y[bestIdx];
        histogram[(int)cl]++;
    }

    CLASS_TYPE mostPopular = -1;
    int mostPopularCount = -1;

    for (int i = 0; i < N_CLASSES; i++)
    {
        if (histogram[i] > mostPopularCount)
        {
            mostPopularCount = histogram[i];
            mostPopular = (CLASS_TYPE)i;
        }
    }
    *voteResult = mostPopular;
}

void kNN_MinMaxNormalize(DATA_TYPE min[N_FEATURES], DATA_TYPE max[N_FEATURES],
                         DATA_TYPE queryDatapoint[N_FEATURES])
{
    for (int i = 0; i < N_FEATURES; i++)
    {
        DATA_TYPE nfeature =
            (DATA_TYPE)((queryDatapoint[i] - min[i]) / (max[i] - min[i]));

        // in case the normalization returns a NaN or INF
        if (isnan(nfeature))
        {
            nfeature = (DATA_TYPE)0.0;
        }
        else if (isinf(nfeature))
        {
            nfeature = (DATA_TYPE)1.0;
        }

        queryDatapoint[i] = nfeature;
    }
}

// Extracted function
void kNN_Distance(double *distance_input, DATA_TYPE queryDatapoint[N_FEATURES], DATA_TYPE training_X[N_TRAINING][N_FEATURES], int i)
{
    double distance = 0.0F;

    for (int j = 0; j < N_FEATURES; j++)
    {
        DATA_TYPE feature = queryDatapoint[j];
        double diff = feature - training_X[i][j];
        distance += diff * diff;
    }
    *distance_input = distance;
}

void kNN_PredictAll(DATA_TYPE training_X[N_TRAINING][N_FEATURES],
                    CLASS_TYPE training_Y[N_TRAINING],
                    DATA_TYPE testing_X[N_TESTING][N_FEATURES],
                    CLASS_TYPE testing_Y[N_TESTING], DATA_TYPE min[N_FEATURES],
                    DATA_TYPE max[N_FEATURES])
{
    for (int i = 0; i < N_TESTING; i++)
    {
        double bestDistances[K];
        int bestPointsIdx[K];

        kNN_MinMaxNormalize(min, max, testing_X[i]);

        kNN_InitBest(bestDistances, bestPointsIdx);

        for (int _i = 0; _i < N_TRAINING; _i++)
        {
            double distance;
            kNN_Distance(&distance, testing_X[i], training_X, _i);

            kNN_UpdateBest(distance, _i, bestDistances, bestPointsIdx);
        }

        CLASS_TYPE voteResult;
        kNN_VoteBetweenBest(bestPointsIdx, training_Y, &voteResult);
        testing_Y[i] = voteResult;
    }
}
