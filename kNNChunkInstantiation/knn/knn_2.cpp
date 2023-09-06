#include <cfloat>
#include <cmath>
#include "scenarios.h"
#include "design_params.h"

static double kNN_UpdateBestCaching(double queryDistance, int queryIdx,
                                    double bestDistances[K], int bestPointsIdx[K])
{
#pragma HLS INLINE
#pragma HLS ARRAY_PARTITION variable = bestDistances type = complete
#pragma HLS ARRAY_PARTITION variable = bestPointsIdx type = complete
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

void kNN_Predict_2(DATA_TYPE training_X[N_TRAINING][N_FEATURES],
                   CLASS_TYPE training_Y[N_TRAINING],
                   DATA_TYPE min[N_FEATURES], DATA_TYPE max[N_FEATURES],
                   DATA_TYPE queryDatapoint_0[N_FEATURES],
                   DATA_TYPE queryDatapoint_1[N_FEATURES],
                   CLASS_TYPE *res0, CLASS_TYPE *res1)
{
#pragma HLS ARRAY_PARTITION variable = training_X type = cyclic factor = 2 dim = 1
#pragma HLS ARRAY_PARTITION variable = queryDatapoint_0 type = complete
#pragma HLS ARRAY_PARTITION variable = queryDatapoint_1 type = complete

#if NORMALIZE_IN_LOOP == 0
    for (int i = 0; i < N_FEATURES; i++)
    {
#pragma HLS unroll
        DATA_TYPE nfeature_0 = (DATA_TYPE)((queryDatapoint_0[i] - min[i]) / (max[i] - min[i]));
        DATA_TYPE nfeature_1 = (DATA_TYPE)((queryDatapoint_1[i] - min[i]) / (max[i] - min[i]));

        queryDatapoint_0[i] = std::isnan(nfeature_0) ? 0.0 : (std::isinf(nfeature_0) ? 1.0 : nfeature_0);
        queryDatapoint_1[i] = std::isnan(nfeature_1) ? 0.0 : (std::isinf(nfeature_1) ? 1.0 : nfeature_1);
    }
#endif

    double bestDistanceMax_0 = DBL_MAX;
    double bestDistances_0[K];
    int bestPointsIdx_0[K];
    double bestDistanceMax_1 = DBL_MAX;
    double bestDistances_1[K];
    int bestPointsIdx_1[K];

    for (int i = 0; i < K; i++)
    {
#pragma HLS UNROLL
        bestDistances_0[i] = DBL_MAX;
        bestPointsIdx_0[i] = -1;
        bestDistances_1[i] = DBL_MAX;
        bestPointsIdx_1[i] = -1;
    }

    for (int i = 0; i < N_TRAINING; i += 2)
    {
        double distance_q0_t0 = 0.0F;
        double distance_q0_t1 = 0.0F;

        double distance_q1_t0 = 0.0F;
        double distance_q1_t1 = 0.0F;

        for (int j = 0; j < N_FEATURES; j++)
        {
#pragma HLS PIPELINE
            DATA_TYPE q0_feat = queryDatapoint_0[j];
            DATA_TYPE q1_feat = queryDatapoint_1[j];

#if NORMALIZE_IN_LOOP == 1
            q0_feat = (DATA_TYPE)((q0_feat - min[i]) / (max[i] - min[i]));
            q1_feat = (DATA_TYPE)((q1_feat - min[i]) / (max[i] - min[i]));

            q0_feat = std::isnan(q0_feat) ? 0.0 : (std::isinf(q0_feat) ? 1.0 : q0_feat);
            q1_feat = std::isnan(q1_feat) ? 0.0 : (std::isinf(q1_feat) ? 1.0 : q1_feat);
#endif

            DATA_TYPE t0_feat = training_X[i + 0][j];
            DATA_TYPE t1_feat = training_X[i + 1][j];

            double diff_q0_t0 = q0_feat - t0_feat;
            double diff_q1_t1 = q1_feat - t1_feat;

            distance_q0_t0 += diff_q0_t0 * diff_q0_t0;
            distance_q1_t1 += diff_q1_t1 * diff_q1_t1;

            double diff_q0_t1 = q0_feat - t1_feat;
            double diff_q1_t0 = q1_feat - t0_feat;

            distance_q0_t1 += diff_q0_t1 * diff_q0_t1;
            distance_q1_t0 += diff_q1_t0 * diff_q1_t0;
        }

        if (distance_q0_t0 < bestDistanceMax_0)
            bestDistanceMax_0 = kNN_UpdateBestCaching(distance_q0_t0, 0, bestDistances_0, bestPointsIdx_0);
        if (distance_q0_t1 < bestDistanceMax_0)
            bestDistanceMax_0 = kNN_UpdateBestCaching(distance_q0_t1, 1, bestDistances_0, bestPointsIdx_0);

        if (distance_q1_t0 < bestDistanceMax_1)
            bestDistanceMax_1 = kNN_UpdateBestCaching(distance_q1_t0, 0, bestDistances_1, bestPointsIdx_1);
        if (distance_q1_t1 < bestDistanceMax_1)
            bestDistanceMax_1 = kNN_UpdateBestCaching(distance_q1_t1, 1, bestDistances_1, bestPointsIdx_1);
    }

    CLASS_TYPE histogram_q0[N_CLASSES] = {0};
    CLASS_TYPE histogram_q1[N_CLASSES] = {0};

    for (int i = 0; i < K; i++)
    {
#pragma HLS UNROLL
        int bestIdx_q0 = bestPointsIdx_0[i];
        int bestIdx_q1 = bestPointsIdx_1[i];

        CLASS_TYPE cl_q0 = training_Y[bestIdx_q0];
        CLASS_TYPE cl_q1 = training_Y[bestIdx_q1];

        histogram_q0[(int)cl_q0]++;
        histogram_q1[(int)cl_q1]++;
    }

    CLASS_TYPE mostPopular_q0 = -1;
    CLASS_TYPE mostPopular_q1 = -1;
    int mostPopularCount_q0 = -1;
    int mostPopularCount_q1 = -1;

    for (int i = 0; i < N_CLASSES; i++)
    {
#pragma HLS PIPELINE
        if (histogram_q0[i] > mostPopularCount_q0)
        {
            mostPopularCount_q0 = histogram_q0[i];
            mostPopular_q0 = (CLASS_TYPE)i;
        }
        if (histogram_q1[i] > mostPopularCount_q1)
        {
            mostPopularCount_q1 = histogram_q1[i];
            mostPopular_q1 = (CLASS_TYPE)i;
        }
    }
    *res0 = mostPopular_q0;
    *res1 = mostPopular_q1;
}
