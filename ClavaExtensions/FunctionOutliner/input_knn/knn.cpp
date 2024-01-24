#include <cfloat>
#include <cmath>
#include "scenarios.h"

double kNN_UpdateBest(double queryDistance, int queryIdx,
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
    return DBL_MAX;
}

double kNN_UpdateBestCaching(double queryDistance, int queryIdx,
                             double bestDistances[K], int bestPointsIdx[K])
{
    double worstOfBest = 0;
    int worstOfBestIdx = -1;
    double secondWorstOfBest = 0;
    int secondWorstOfBestIdx = -1;

    for (int i = 0; i < K; i++)
    {
        if (worstOfBest < bestDistances[i])
        {
            secondWorstOfBest = worstOfBest;
            secondWorstOfBestIdx = worstOfBestIdx;

            worstOfBest = bestDistances[i];
            worstOfBestIdx = i;
        }
        else if (secondWorstOfBest < bestDistances[i])
        {
            secondWorstOfBest = bestDistances[i];
            secondWorstOfBestIdx = i;
        }
    }

    if (queryDistance < worstOfBest)
    {
        bestDistances[worstOfBestIdx] = queryDistance;
        bestPointsIdx[worstOfBestIdx] = queryIdx;
    }
    return (queryDistance > secondWorstOfBest) ? queryDistance
                                               : secondWorstOfBest;
}

void kNN_InitBest(double bestDistances[K], int bestPointsIdx[K])
{
    for (int i = 0; i < K; i++)
    {
        bestDistances[i] = DBL_MAX;
        bestPointsIdx[i] = -1;
    }
}

CLASS_TYPE kNN_VoteBetweenBest(int bestPointsIdx[K], CLASS_TYPE training_Y[N_TRAINING])
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
    return mostPopular;
}

void kNN_MinMaxNormalize(DATA_TYPE min[N_FEATURES], DATA_TYPE max[N_FEATURES],
                         DATA_TYPE queryDatapoint[N_FEATURES])
{
    for (int i = 0; i < N_FEATURES; i++)
    {
        DATA_TYPE nfeature =
            (DATA_TYPE)((queryDatapoint[i] - min[i]) / (max[i] - min[i]));

        // in case the normalization returns a NaN or INF
        if (std::isnan(nfeature))
        {
            nfeature = (DATA_TYPE)0.0;
        }
        else if (std::isinf(nfeature))
        {
            nfeature = (DATA_TYPE)1.0;
        }

        queryDatapoint[i] = nfeature;
    }
}

CLASS_TYPE kNN_Predict(DATA_TYPE training_X[N_TRAINING][N_FEATURES],
                       CLASS_TYPE training_Y[N_TRAINING],
                       DATA_TYPE queryDatapoint[N_FEATURES],
                       DATA_TYPE min[N_FEATURES], DATA_TYPE max[N_FEATURES])
{
    double bestDistanceMax = DBL_MAX;
    double bestDistances[K];
    int bestPointsIdx[K];

    kNN_MinMaxNormalize(min, max, queryDatapoint);

    kNN_InitBest(bestDistances, bestPointsIdx);

    for (int i = 0; i < N_TRAINING; i++)
    {
#pragma clava begin_outline
        double distance = 0.0F;

        for (int j = 0; j < N_FEATURES; j++)
        {
            DATA_TYPE feature = queryDatapoint[j];
            double diff = feature - training_X[i][j];
            distance += diff * diff;
        }
#pragma clava end_outline

        bestDistanceMax = kNN_UpdateBestCaching(distance, i, bestDistances, bestPointsIdx);

        // Slighly improved version, it doesn't need to update the K-best distances if
        // the current point is worse than the worst K-best distance.
        // if (distance < bestDistanceMax)
        //{
        //    bestDistanceMax = kNN_UpdateBestCaching(distance, i, bestDistances, bestPointsIdx);
        //}
    }

    CLASS_TYPE voteResult = kNN_VoteBetweenBest(bestPointsIdx, training_Y);
    return voteResult;
}

void kNN_PredictAll(DATA_TYPE training_X[N_TRAINING][N_FEATURES],
                    CLASS_TYPE training_Y[N_TRAINING],
                    DATA_TYPE testing_X[N_TESTING][N_FEATURES],
                    CLASS_TYPE testing_Y[N_TESTING], DATA_TYPE min[N_FEATURES],
                    DATA_TYPE max[N_FEATURES])
{
    for (int i = 0; i < N_TESTING; i++)
    {
        testing_Y[i] = kNN_Predict(training_X, training_Y, testing_X[i], min, max);
    }
}
