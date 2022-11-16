#include <float.h>
#include <math.h>

#ifndef USE_FPGA
#define USE_FPGA 1
#endif

#if USE_FPGA == 1
#define TARGET_FPGA
#else
#define TARGET_CPU
#endif

#ifdef TARGET_FPGA
#include "fpga_settings.h"
#else
#include "scenarios.h"
#endif

double kNN_UpdateBest(double queryDistance, int queryIdx,
                      double bestDistances[K], int bestPointsIdx[K])
{
#pragma HLS INLINE
    double worstOfBest = 0;
    int worstOfBestIdx = -1;

    for (int i = 0; i < K; i++)
    {
        // #pragma HLS pipeline
        // #pragma HLS unroll
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
    return DBL_MAX; // No caching yet
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
        // #pragma HLS pipeline
        // #pragma HLS unroll
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
        // #pragma HLS unroll
        bestDistances[i] = DBL_MAX;
        bestPointsIdx[i] = -1;
    }
}

CLASS_TYPE kNN_VoteBetweenBest(int bestPointsIdx[K],
                               CLASS_TYPE training_Y[N_TRAINING])
{
#pragma HLS INLINE
    // specialize for small K values?
    // we use the histogram version for now
    CLASS_TYPE histogram[N_CLASSES] = {0};

    for (int i = 0; i < K; i++)
    {
        // #pragma HLS unroll
        int bestIdx = bestPointsIdx[i];
        CLASS_TYPE cl = training_Y[bestIdx];
        histogram[(int)cl]++;
    }

    CLASS_TYPE mostPopular = -1;
    int mostPopularCount = -1;

    for (int i = 0; i < N_CLASSES; i++)
    {
        // #pragma HLS pipeline
        // #pragma HLS unroll
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
#pragma HLS INLINE
    for (int i = 0; i < N_FEATURES; i++)
    {
        // #pragma HLS unroll
        DATA_TYPE nfeature =
            (DATA_TYPE)((queryDatapoint[i] - min[i]) / (max[i] - min[i]));

        // in case the normalization returns a NaN or INF
        nfeature = (isnan(nfeature) ? 0.0 : (isinf(nfeature) ? 1.0 : nfeature));

        queryDatapoint[i] = nfeature;
    }
}

#define USE_HEAP 0
#define NORMALIZE_IN_LOOP 0

CLASS_TYPE kNN_Predict(DATA_TYPE training_X[N_TRAINING][N_FEATURES],
                       CLASS_TYPE training_Y[N_TRAINING],
                       DATA_TYPE queryDatapoint[N_FEATURES],
                       DATA_TYPE min[N_FEATURES], DATA_TYPE max[N_FEATURES],
                       int id)
{
#pragma HLS FUNCTION_INSTANTIATE variable = id
    double bestDistanceMax = DBL_MAX;
    double bestDistances[K];
    int bestPointsIdx[K];

#if NORMALIZE_IN_LOOP == 0
    kNN_MinMaxNormalize(min, max, queryDatapoint);
#endif

    kNN_InitBest(bestDistances, bestPointsIdx);

    for (int i = 0; i < N_TRAINING; i++)
    {
        double distance = id;

        for (int j = 0; j < N_FEATURES; j++)
        {
            // #pragma HLS pipeline
            DATA_TYPE feature = queryDatapoint[j];

#if NORMALIZE_IN_LOOP == 1
            feature = (DATA_TYPE)((feature - min[j]) / (max[j] - min[j]));
            feature = isnan(feature) ? 0.0 : (isinf(feature) ? 1.0 : feature);
#endif
            double diff = feature - training_X[i][j];
            distance += diff * diff;
        }
        distance -= id;

#if USE_HEAP == 0
        if (distance < bestDistanceMax)
        {

            bestDistanceMax = kNN_UpdateBestCaching(distance, i, bestDistances,
                                                    bestPointsIdx);
        }
#else

#endif
    }

    CLASS_TYPE voteResult = kNN_VoteBetweenBest(bestPointsIdx, training_Y);
    return voteResult;
}

#define QUERIES_PER_CHUNK 25

void kNN_PredictAll(DATA_TYPE training_X[N_TRAINING][N_FEATURES],
                    CLASS_TYPE training_Y[N_TRAINING],
                    DATA_TYPE testing_X[N_TESTING][N_FEATURES],
                    CLASS_TYPE testing_Y[N_TESTING], DATA_TYPE min[N_FEATURES],
                    DATA_TYPE max[N_FEATURES])
{
    int remainder = N_TESTING % QUERIES_PER_CHUNK;
    int N = N_TESTING - remainder;

    for (int i = 0; i < N; i += QUERIES_PER_CHUNK)
    {
        testing_Y[i + 0] = kNN_Predict(training_X, training_Y, testing_X[i], min, max, 0);
    }
	
}
