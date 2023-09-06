#include <cfloat>
#include <cmath>
#include "scenarios.h"
#include "design_params.h"
#include "knn_2.h"
#include "knn_4.h"
#include "knn_8.h"

double kNN_UpdateBest(double queryDistance, int queryIdx,
                      double bestDistances[K], int bestPointsIdx[K])
{
    double worstOfBest = 0;
    int worstOfBestIdx = -1;

    for (int i = 0; i < K; i++)
    {
#pragma HLS pipeline
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
#pragma HLS INLINE
    double worstOfBest = 0;
    int worstOfBestIdx = -1;
    double secondWorstOfBest = 0;
    int secondWorstOfBestIdx = -1;

    for (int i = 0; i < K; i++)
    {
#pragma HLS PIPELINE
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
#pragma HLS INLINE
    for (int i = 0; i < K; i++)
    {
#pragma HLS unroll
        bestDistances[i] = DBL_MAX;
        bestPointsIdx[i] = -1;
    }
}

CLASS_TYPE kNN_VoteBetweenBest(int bestPointsIdx[K], CLASS_TYPE training_Y[N_TRAINING])
{
#pragma HLS INLINE
    CLASS_TYPE histogram[N_CLASSES] = {0};

    for (int i = 0; i < K; i++)
    {
#pragma HLS unroll
        int bestIdx = bestPointsIdx[i];
        CLASS_TYPE cl = training_Y[bestIdx];
        histogram[(int)cl]++;
    }

    CLASS_TYPE mostPopular = -1;
    int mostPopularCount = -1;

    for (int i = 0; i < N_CLASSES; i++)
    {
#pragma HLS pipeline
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
#pragma HLS unroll
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
#pragma HLS ARRAY_PARTITION variable=training_X type=cyclic factor=64 dim=1
#pragma HLS ARRAY_PARTITION variable=queryDatapoint type=complete
    double bestDistanceMax = DBL_MAX;
    double bestDistances[K];
    int bestPointsIdx[K];

#if NORMALIZE_IN_LOOP == 0
    kNN_MinMaxNormalize(min, max, queryDatapoint);
#endif

    kNN_InitBest(bestDistances, bestPointsIdx);

    for (int i = 0; i < N_TRAINING; i++)
    {
        double distance = 0.0F;

        for (int j = 0; j < N_FEATURES; j++)
        {
#pragma HLS PIPELINE
            DATA_TYPE feature = queryDatapoint[j];

#if NORMALIZE_IN_LOOP == 1
            feature = (DATA_TYPE)((feature - min[j]) / (max[j] - min[j]));
            feature = std::isnan(feature) ? 0.0 : (std::isinf(feature) ? 1.0 : feature);
#endif

            double diff = feature - training_X[i][j];
            distance += diff * diff;
        }

#if USE_CACHING == 1
        if (distance < bestDistanceMax)
        {
            bestDistanceMax = kNN_UpdateBestCaching(distance, i, bestDistances, bestPointsIdx);
        }
#else
        kNN_UpdateBest(distance, i, bestDistances, bestPointsIdx);
#endif
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
#if CHUNK_SIZE == 1
    for (int i = 0; i < N_TESTING; i++)
    {
        testing_Y[i] = kNN_Predict(training_X, training_Y, testing_X[i], min, max);
    }
#endif
#if CHUNK_SIZE == 2
    for (int i = 0; i < N_TESTING; i += CHUNK_SIZE)
    {
        kNN_Predict_2(training_X, training_Y, min, max, testing_X[i], testing_X[i+1],
        		&testing_Y[i], &testing_Y[i+1]);
    }
#endif
#if CHUNK_SIZE == 4
    for (int i = 0; i < N_TESTING; i += CHUNK_SIZE)
    {
        kNN_Predict_4(training_X, training_Y, min, max, testing_X[i], testing_X[i+1], testing_X[i+2], testing_X[i+3],
        		&testing_Y[i], &testing_Y[i+1], &testing_Y[i+2], &testing_Y[i+3]);
    }
#endif
#if CHUNK_SIZE == 8
    for (int i = 0; i < N_TESTING; i += CHUNK_SIZE)
    {
        kNN_Predict_8(training_X, training_Y, min, max,
		testing_X[i], testing_X[i+1], testing_X[i+2], testing_X[i+3], testing_X[i+4], testing_X[i+5], testing_X[i+6], testing_X[i+7],
		&testing_Y[i], &testing_Y[i+1], &testing_Y[i+2], &testing_Y[i+3], &testing_Y[i+4], &testing_Y[i+5], &testing_Y[i+6], &testing_Y[i+7]);
    }
#endif

}
