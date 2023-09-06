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

void kNN_Predict_8(DATA_TYPE training_X[N_TRAINING][N_FEATURES],
                   CLASS_TYPE training_Y[N_TRAINING],
                   DATA_TYPE min[N_FEATURES], DATA_TYPE max[N_FEATURES],
                   DATA_TYPE queryDatapoint_0[N_FEATURES],
                   DATA_TYPE queryDatapoint_1[N_FEATURES],
                   DATA_TYPE queryDatapoint_2[N_FEATURES],
                   DATA_TYPE queryDatapoint_3[N_FEATURES],
                   DATA_TYPE queryDatapoint_4[N_FEATURES],
                   DATA_TYPE queryDatapoint_5[N_FEATURES],
                   DATA_TYPE queryDatapoint_6[N_FEATURES],
                   DATA_TYPE queryDatapoint_7[N_FEATURES],
                   CLASS_TYPE *res0, CLASS_TYPE *res1, CLASS_TYPE *res2, CLASS_TYPE *res3,
                   CLASS_TYPE *res4, CLASS_TYPE *res5, CLASS_TYPE *res6, CLASS_TYPE *res7)
{
#pragma HLS ARRAY_PARTITION variable = training_X type = cyclic factor = 8 dim = 1
	/*
#pragma HLS ARRAY_PARTITION variable = queryDatapoint_0 type = complete
#pragma HLS ARRAY_PARTITION variable = queryDatapoint_1 type = complete
#pragma HLS ARRAY_PARTITION variable = queryDatapoint_2 type = complete
#pragma HLS ARRAY_PARTITION variable = queryDatapoint_3 type = complete
#pragma HLS ARRAY_PARTITION variable = queryDatapoint_4 type = complete
#pragma HLS ARRAY_PARTITION variable = queryDatapoint_5 type = complete
#pragma HLS ARRAY_PARTITION variable = queryDatapoint_6 type = complete
#pragma HLS ARRAY_PARTITION variable = queryDatapoint_7 type = complete
*/

#if NORMALIZE_IN_LOOP == 0
    for (int i = 0; i < N_FEATURES; i++)
    {
#pragma HLS unroll
        DATA_TYPE nfeature_0 = (DATA_TYPE)((queryDatapoint_0[i] - min[i]) / (max[i] - min[i]));
        DATA_TYPE nfeature_1 = (DATA_TYPE)((queryDatapoint_1[i] - min[i]) / (max[i] - min[i]));
        DATA_TYPE nfeature_2 = (DATA_TYPE)((queryDatapoint_2[i] - min[i]) / (max[i] - min[i]));
        DATA_TYPE nfeature_3 = (DATA_TYPE)((queryDatapoint_3[i] - min[i]) / (max[i] - min[i]));
        DATA_TYPE nfeature_4 = (DATA_TYPE)((queryDatapoint_4[i] - min[i]) / (max[i] - min[i]));
        DATA_TYPE nfeature_5 = (DATA_TYPE)((queryDatapoint_5[i] - min[i]) / (max[i] - min[i]));
        DATA_TYPE nfeature_6 = (DATA_TYPE)((queryDatapoint_6[i] - min[i]) / (max[i] - min[i]));
        DATA_TYPE nfeature_7 = (DATA_TYPE)((queryDatapoint_7[i] - min[i]) / (max[i] - min[i]));

        queryDatapoint_0[i] = std::isnan(nfeature_0) ? 0.0 : (std::isinf(nfeature_0) ? 1.0 : nfeature_0);
        queryDatapoint_1[i] = std::isnan(nfeature_1) ? 0.0 : (std::isinf(nfeature_1) ? 1.0 : nfeature_1);
        queryDatapoint_2[i] = std::isnan(nfeature_2) ? 0.0 : (std::isinf(nfeature_2) ? 1.0 : nfeature_2);
        queryDatapoint_3[i] = std::isnan(nfeature_3) ? 0.0 : (std::isinf(nfeature_3) ? 1.0 : nfeature_3);
        queryDatapoint_4[i] = std::isnan(nfeature_0) ? 0.0 : (std::isinf(nfeature_4) ? 1.0 : nfeature_4);
        queryDatapoint_5[i] = std::isnan(nfeature_1) ? 0.0 : (std::isinf(nfeature_5) ? 1.0 : nfeature_5);
        queryDatapoint_6[i] = std::isnan(nfeature_2) ? 0.0 : (std::isinf(nfeature_6) ? 1.0 : nfeature_6);
        queryDatapoint_7[i] = std::isnan(nfeature_3) ? 0.0 : (std::isinf(nfeature_7) ? 1.0 : nfeature_7);
    }
#endif

    double bestDistanceMax_0 = DBL_MAX;
    double bestDistances_0[K];
    int bestPointsIdx_0[K];

    double bestDistanceMax_1 = DBL_MAX;
    double bestDistances_1[K];
    int bestPointsIdx_1[K];

    double bestDistanceMax_2 = DBL_MAX;
    double bestDistances_2[K];
    int bestPointsIdx_2[K];

    double bestDistanceMax_3 = DBL_MAX;
    double bestDistances_3[K];
    int bestPointsIdx_3[K];

    double bestDistanceMax_4 = DBL_MAX;
    double bestDistances_4[K];
    int bestPointsIdx_4[K];

    double bestDistanceMax_5 = DBL_MAX;
    double bestDistances_5[K];
    int bestPointsIdx_5[K];

    double bestDistanceMax_6 = DBL_MAX;
    double bestDistances_6[K];
    int bestPointsIdx_6[K];

    double bestDistanceMax_7 = DBL_MAX;
    double bestDistances_7[K];
    int bestPointsIdx_7[K];

    for (int i = 0; i < K; i++)
    {
#pragma HLS UNROLL
        bestDistances_0[i] = DBL_MAX;
        bestPointsIdx_0[i] = -1;

        bestDistances_1[i] = DBL_MAX;
        bestPointsIdx_1[i] = -1;

        bestDistances_2[i] = DBL_MAX;
        bestPointsIdx_2[i] = -1;

        bestDistances_3[i] = DBL_MAX;
        bestPointsIdx_3[i] = -1;

        bestDistances_4[i] = DBL_MAX;
        bestPointsIdx_4[i] = -1;

        bestDistances_5[i] = DBL_MAX;
        bestPointsIdx_5[i] = -1;

        bestDistances_6[i] = DBL_MAX;
        bestPointsIdx_6[i] = -1;

        bestDistances_7[i] = DBL_MAX;
        bestPointsIdx_7[i] = -1;
    }

    for (int i = 0; i < N_TRAINING; i += 8)
    {
        double distance_q0_t0 = 0.0F;
        double distance_q0_t1 = 0.0F;
        double distance_q0_t2 = 0.0F;
        double distance_q0_t3 = 0.0F;
        double distance_q0_t4 = 0.0F;
        double distance_q0_t5 = 0.0F;
        double distance_q0_t6 = 0.0F;
        double distance_q0_t7 = 0.0F;

        double distance_q1_t0 = 0.0F;
        double distance_q1_t1 = 0.0F;
        double distance_q1_t2 = 0.0F;
        double distance_q1_t3 = 0.0F;
        double distance_q1_t4 = 0.0F;
        double distance_q1_t5 = 0.0F;
        double distance_q1_t6 = 0.0F;
        double distance_q1_t7 = 0.0F;

        double distance_q2_t0 = 0.0F;
        double distance_q2_t1 = 0.0F;
        double distance_q2_t2 = 0.0F;
        double distance_q2_t3 = 0.0F;
        double distance_q2_t4 = 0.0F;
        double distance_q2_t5 = 0.0F;
        double distance_q2_t6 = 0.0F;
        double distance_q2_t7 = 0.0F;

        double distance_q3_t0 = 0.0F;
        double distance_q3_t1 = 0.0F;
        double distance_q3_t2 = 0.0F;
        double distance_q3_t3 = 0.0F;
        double distance_q3_t4 = 0.0F;
        double distance_q3_t5 = 0.0F;
        double distance_q3_t6 = 0.0F;
        double distance_q3_t7 = 0.0F;

        double distance_q4_t0 = 0.0F;
        double distance_q4_t1 = 0.0F;
        double distance_q4_t2 = 0.0F;
        double distance_q4_t3 = 0.0F;
        double distance_q4_t4 = 0.0F;
        double distance_q4_t5 = 0.0F;
        double distance_q4_t6 = 0.0F;
        double distance_q4_t7 = 0.0F;

        double distance_q5_t0 = 0.0F;
        double distance_q5_t1 = 0.0F;
        double distance_q5_t2 = 0.0F;
        double distance_q5_t3 = 0.0F;
        double distance_q5_t4 = 0.0F;
        double distance_q5_t5 = 0.0F;
        double distance_q5_t6 = 0.0F;
        double distance_q5_t7 = 0.0F;

        double distance_q6_t0 = 0.0F;
        double distance_q6_t1 = 0.0F;
        double distance_q6_t2 = 0.0F;
        double distance_q6_t3 = 0.0F;
        double distance_q6_t4 = 0.0F;
        double distance_q6_t5 = 0.0F;
        double distance_q6_t6 = 0.0F;
        double distance_q6_t7 = 0.0F;

        double distance_q7_t0 = 0.0F;
        double distance_q7_t1 = 0.0F;
        double distance_q7_t2 = 0.0F;
        double distance_q7_t3 = 0.0F;
        double distance_q7_t4 = 0.0F;
        double distance_q7_t5 = 0.0F;
        double distance_q7_t6 = 0.0F;
        double distance_q7_t7 = 0.0F;

        for (int j = 0; j < N_FEATURES; j++)
        {
#pragma HLS PIPELINE
            DATA_TYPE q0_feat = queryDatapoint_0[j];
            DATA_TYPE q1_feat = queryDatapoint_1[j];
            DATA_TYPE q2_feat = queryDatapoint_2[j];
            DATA_TYPE q3_feat = queryDatapoint_3[j];
            DATA_TYPE q4_feat = queryDatapoint_4[j];
            DATA_TYPE q5_feat = queryDatapoint_5[j];
            DATA_TYPE q6_feat = queryDatapoint_6[j];
            DATA_TYPE q7_feat = queryDatapoint_7[j];

#if NORMALIZE_IN_LOOP == 1
            q0_feat = std::isnan(q0_feat) ? 0.0 : (std::isinf(q0_feat) ? 1.0 : q0_feat);
            q1_feat = std::isnan(q1_feat) ? 0.0 : (std::isinf(q1_feat) ? 1.0 : q1_feat);
            q2_feat = std::isnan(q2_feat) ? 0.0 : (std::isinf(q2_feat) ? 1.0 : q2_feat);
            q3_feat = std::isnan(q3_feat) ? 0.0 : (std::isinf(q3_feat) ? 1.0 : q3_feat);
            q4_feat = std::isnan(q4_feat) ? 0.0 : (std::isinf(q4_feat) ? 1.0 : q4_feat);
            q5_feat = std::isnan(q5_feat) ? 0.0 : (std::isinf(q5_feat) ? 1.0 : q5_feat);
            q6_feat = std::isnan(q6_feat) ? 0.0 : (std::isinf(q6_feat) ? 1.0 : q6_feat);
            q7_feat = std::isnan(q7_feat) ? 0.0 : (std::isinf(q7_feat) ? 1.0 : q7_feat);
#endif

            DATA_TYPE t0_feat = training_X[i + 0][j];
            DATA_TYPE t1_feat = training_X[i + 1][j];
            DATA_TYPE t2_feat = training_X[i + 2][j];
            DATA_TYPE t3_feat = training_X[i + 3][j];
            DATA_TYPE t4_feat = training_X[i + 4][j];
            DATA_TYPE t5_feat = training_X[i + 5][j];
            DATA_TYPE t6_feat = training_X[i + 6][j];
            DATA_TYPE t7_feat = training_X[i + 7][j];

            //---------------------------------------
            double diff_q0_t0 = q0_feat - t0_feat;
            double diff_q1_t1 = q1_feat - t1_feat;
            double diff_q2_t2 = q2_feat - t2_feat;
            double diff_q3_t3 = q3_feat - t3_feat;
            double diff_q4_t4 = q4_feat - t4_feat;
            double diff_q5_t5 = q5_feat - t5_feat;
            double diff_q6_t6 = q6_feat - t6_feat;
            double diff_q7_t7 = q7_feat - t7_feat;

            distance_q0_t0 += diff_q0_t0 * diff_q0_t0;
            distance_q1_t1 += diff_q1_t1 * diff_q1_t1;
            distance_q2_t2 += diff_q2_t2 * diff_q2_t2;
            distance_q3_t3 += diff_q3_t3 * diff_q3_t3;
            distance_q4_t4 += diff_q4_t4 * diff_q4_t4;
            distance_q5_t5 += diff_q5_t5 * diff_q5_t5;
            distance_q6_t6 += diff_q6_t6 * diff_q6_t6;
            distance_q7_t7 += diff_q7_t7 * diff_q7_t7;

            //---------------------------------------
            double diff_q0_t1 = q0_feat - t1_feat;
            double diff_q1_t2 = q1_feat - t2_feat;
            double diff_q2_t3 = q2_feat - t3_feat;
            double diff_q3_t4 = q3_feat - t4_feat;
            double diff_q4_t5 = q4_feat - t5_feat;
            double diff_q5_t6 = q5_feat - t6_feat;
            double diff_q6_t7 = q6_feat - t7_feat;
            double diff_q7_t0 = q7_feat - t0_feat;

            distance_q0_t1 += diff_q0_t1 * diff_q0_t1;
            distance_q1_t2 += diff_q1_t2 * diff_q1_t2;
            distance_q2_t3 += diff_q2_t3 * diff_q2_t3;
            distance_q3_t4 += diff_q3_t4 * diff_q3_t4;
            distance_q4_t5 += diff_q4_t5 * diff_q4_t5;
            distance_q5_t6 += diff_q5_t6 * diff_q5_t6;
            distance_q6_t7 += diff_q6_t7 * diff_q6_t7;
            distance_q7_t0 += diff_q7_t0 * diff_q7_t0;

            //---------------------------------------
            double diff_q0_t2 = q0_feat - t2_feat;
            double diff_q1_t3 = q1_feat - t3_feat;
            double diff_q2_t4 = q2_feat - t4_feat;
            double diff_q3_t5 = q3_feat - t5_feat;
            double diff_q4_t6 = q4_feat - t6_feat;
            double diff_q5_t7 = q5_feat - t7_feat;
            double diff_q6_t0 = q6_feat - t0_feat;
            double diff_q7_t1 = q7_feat - t1_feat;

            distance_q0_t2 += diff_q0_t2 * diff_q0_t2;
            distance_q1_t3 += diff_q1_t3 * diff_q1_t3;
            distance_q2_t4 += diff_q2_t4 * diff_q2_t4;
            distance_q3_t5 += diff_q3_t5 * diff_q3_t5;
            distance_q4_t6 += diff_q4_t6 * diff_q4_t6;
            distance_q5_t7 += diff_q5_t7 * diff_q5_t7;
            distance_q6_t0 += diff_q6_t0 * diff_q6_t0;
            distance_q7_t1 += diff_q7_t1 * diff_q7_t1;

            //---------------------------------------
            double diff_q0_t3 = q0_feat - t3_feat;
            double diff_q1_t4 = q1_feat - t4_feat;
            double diff_q2_t5 = q2_feat - t5_feat;
            double diff_q3_t6 = q3_feat - t6_feat;
            double diff_q4_t7 = q4_feat - t7_feat;
            double diff_q5_t0 = q5_feat - t0_feat;
            double diff_q6_t1 = q6_feat - t1_feat;
            double diff_q7_t2 = q7_feat - t2_feat;

            distance_q0_t3 += diff_q0_t3 * diff_q0_t3;
            distance_q1_t4 += diff_q1_t4 * diff_q1_t4;
            distance_q2_t5 += diff_q2_t5 * diff_q2_t5;
            distance_q3_t6 += diff_q3_t6 * diff_q3_t6;
            distance_q4_t7 += diff_q4_t7 * diff_q4_t7;
            distance_q5_t0 += diff_q5_t0 * diff_q5_t0;
            distance_q6_t1 += diff_q6_t1 * diff_q6_t1;
            distance_q7_t2 += diff_q7_t2 * diff_q7_t2;

            //---------------------------------------
            double diff_q0_t4 = q0_feat - t4_feat;
            double diff_q1_t5 = q1_feat - t5_feat;
            double diff_q2_t6 = q2_feat - t6_feat;
            double diff_q3_t7 = q3_feat - t7_feat;
            double diff_q4_t0 = q4_feat - t0_feat;
            double diff_q5_t1 = q5_feat - t1_feat;
            double diff_q6_t2 = q6_feat - t2_feat;
            double diff_q7_t3 = q7_feat - t3_feat;

            distance_q0_t4 += diff_q0_t4 * diff_q0_t4;
            distance_q1_t5 += diff_q1_t5 * diff_q1_t5;
            distance_q2_t6 += diff_q2_t6 * diff_q2_t6;
            distance_q3_t7 += diff_q3_t7 * diff_q3_t7;
            distance_q4_t0 += diff_q4_t0 * diff_q4_t0;
            distance_q5_t1 += diff_q5_t1 * diff_q5_t1;
            distance_q6_t2 += diff_q6_t2 * diff_q6_t2;
            distance_q7_t3 += diff_q7_t3 * diff_q7_t3;

            //---------------------------------------
            double diff_q0_t5 = q0_feat - t5_feat;
            double diff_q1_t6 = q1_feat - t6_feat;
            double diff_q2_t7 = q2_feat - t7_feat;
            double diff_q3_t0 = q3_feat - t0_feat;
            double diff_q4_t1 = q4_feat - t1_feat;
            double diff_q5_t2 = q5_feat - t2_feat;
            double diff_q6_t3 = q6_feat - t3_feat;
            double diff_q7_t4 = q7_feat - t4_feat;

            distance_q0_t5 += diff_q0_t5 * diff_q0_t5;
            distance_q1_t6 += diff_q1_t6 * diff_q1_t6;
            distance_q2_t7 += diff_q2_t7 * diff_q2_t7;
            distance_q3_t0 += diff_q3_t0 * diff_q3_t0;
            distance_q4_t1 += diff_q4_t1 * diff_q4_t1;
            distance_q5_t2 += diff_q5_t2 * diff_q5_t2;
            distance_q6_t3 += diff_q6_t3 * diff_q6_t3;
            distance_q7_t4 += diff_q7_t4 * diff_q7_t4;

            //---------------------------------------
            double diff_q0_t6 = q0_feat - t6_feat;
            double diff_q1_t7 = q1_feat - t7_feat;
            double diff_q2_t0 = q2_feat - t0_feat;
            double diff_q3_t1 = q3_feat - t1_feat;
            double diff_q4_t2 = q4_feat - t2_feat;
            double diff_q5_t3 = q5_feat - t3_feat;
            double diff_q6_t4 = q6_feat - t4_feat;
            double diff_q7_t5 = q7_feat - t5_feat;

            distance_q0_t6 += diff_q0_t6 * diff_q0_t6;
            distance_q1_t7 += diff_q1_t7 * diff_q1_t7;
            distance_q2_t0 += diff_q2_t0 * diff_q2_t0;
            distance_q3_t1 += diff_q3_t1 * diff_q3_t1;
            distance_q4_t2 += diff_q4_t2 * diff_q4_t2;
            distance_q5_t3 += diff_q5_t3 * diff_q5_t3;
            distance_q6_t4 += diff_q6_t4 * diff_q6_t4;
            distance_q7_t5 += diff_q7_t5 * diff_q7_t5;

            //---------------------------------------
            double diff_q0_t7 = q0_feat - t7_feat;
            double diff_q1_t0 = q1_feat - t0_feat;
            double diff_q2_t1 = q2_feat - t1_feat;
            double diff_q3_t2 = q3_feat - t2_feat;
            double diff_q4_t3 = q4_feat - t3_feat;
            double diff_q5_t4 = q5_feat - t4_feat;
            double diff_q6_t5 = q6_feat - t5_feat;
            double diff_q7_t6 = q7_feat - t6_feat;

            distance_q0_t7 += diff_q0_t7 * diff_q0_t7;
            distance_q1_t0 += diff_q1_t0 * diff_q1_t0;
            distance_q2_t1 += diff_q2_t1 * diff_q2_t1;
            distance_q3_t2 += diff_q3_t2 * diff_q3_t2;
            distance_q4_t3 += diff_q4_t3 * diff_q4_t3;
            distance_q5_t4 += diff_q5_t4 * diff_q5_t4;
            distance_q6_t5 += diff_q6_t5 * diff_q6_t5;
            distance_q7_t6 += diff_q7_t6 * diff_q7_t6;

            if (distance_q0_t0 < bestDistanceMax_0)
                bestDistanceMax_0 = kNN_UpdateBestCaching(distance_q0_t0, 0, bestDistances_0, bestPointsIdx_0);
            if (distance_q0_t1 < bestDistanceMax_0)
                bestDistanceMax_0 = kNN_UpdateBestCaching(distance_q0_t1, 1, bestDistances_0, bestPointsIdx_0);
            if (distance_q0_t2 < bestDistanceMax_0)
                bestDistanceMax_0 = kNN_UpdateBestCaching(distance_q0_t2, 2, bestDistances_0, bestPointsIdx_0);
            if (distance_q0_t3 < bestDistanceMax_0)
                bestDistanceMax_0 = kNN_UpdateBestCaching(distance_q0_t3, 3, bestDistances_0, bestPointsIdx_0);
            if (distance_q0_t4 < bestDistanceMax_0)
                bestDistanceMax_0 = kNN_UpdateBestCaching(distance_q0_t4, 4, bestDistances_0, bestPointsIdx_0);
            if (distance_q0_t5 < bestDistanceMax_0)
                bestDistanceMax_0 = kNN_UpdateBestCaching(distance_q0_t5, 5, bestDistances_0, bestPointsIdx_0);
            if (distance_q0_t6 < bestDistanceMax_0)
                bestDistanceMax_0 = kNN_UpdateBestCaching(distance_q0_t6, 6, bestDistances_0, bestPointsIdx_0);
            if (distance_q0_t7 < bestDistanceMax_0)
                bestDistanceMax_0 = kNN_UpdateBestCaching(distance_q0_t7, 7, bestDistances_0, bestPointsIdx_0);

            if (distance_q1_t0 < bestDistanceMax_1)
                bestDistanceMax_1 = kNN_UpdateBestCaching(distance_q1_t0, 0, bestDistances_1, bestPointsIdx_1);
            if (distance_q1_t1 < bestDistanceMax_1)
                bestDistanceMax_1 = kNN_UpdateBestCaching(distance_q1_t1, 1, bestDistances_1, bestPointsIdx_1);
            if (distance_q1_t2 < bestDistanceMax_1)
                bestDistanceMax_1 = kNN_UpdateBestCaching(distance_q1_t2, 2, bestDistances_1, bestPointsIdx_1);
            if (distance_q1_t3 < bestDistanceMax_1)
                bestDistanceMax_1 = kNN_UpdateBestCaching(distance_q1_t3, 3, bestDistances_1, bestPointsIdx_1);
            if (distance_q1_t4 < bestDistanceMax_1)
                bestDistanceMax_1 = kNN_UpdateBestCaching(distance_q1_t4, 4, bestDistances_1, bestPointsIdx_1);
            if (distance_q1_t5 < bestDistanceMax_1)
                bestDistanceMax_1 = kNN_UpdateBestCaching(distance_q1_t5, 5, bestDistances_1, bestPointsIdx_1);
            if (distance_q1_t6 < bestDistanceMax_1)
                bestDistanceMax_1 = kNN_UpdateBestCaching(distance_q1_t6, 6, bestDistances_1, bestPointsIdx_1);
            if (distance_q1_t7 < bestDistanceMax_1)
                bestDistanceMax_1 = kNN_UpdateBestCaching(distance_q1_t7, 7, bestDistances_1, bestPointsIdx_1);

            if (distance_q2_t0 < bestDistanceMax_2)
                bestDistanceMax_2 = kNN_UpdateBestCaching(distance_q2_t0, 0, bestDistances_2, bestPointsIdx_2);
            if (distance_q2_t1 < bestDistanceMax_2)
                bestDistanceMax_2 = kNN_UpdateBestCaching(distance_q2_t1, 1, bestDistances_2, bestPointsIdx_2);
            if (distance_q2_t2 < bestDistanceMax_2)
                bestDistanceMax_2 = kNN_UpdateBestCaching(distance_q2_t2, 2, bestDistances_2, bestPointsIdx_2);
            if (distance_q2_t3 < bestDistanceMax_2)
                bestDistanceMax_2 = kNN_UpdateBestCaching(distance_q2_t3, 3, bestDistances_2, bestPointsIdx_2);
            if (distance_q2_t4 < bestDistanceMax_2)
                bestDistanceMax_2 = kNN_UpdateBestCaching(distance_q2_t4, 4, bestDistances_2, bestPointsIdx_2);
            if (distance_q2_t5 < bestDistanceMax_2)
                bestDistanceMax_2 = kNN_UpdateBestCaching(distance_q2_t5, 5, bestDistances_2, bestPointsIdx_2);
            if (distance_q2_t6 < bestDistanceMax_2)
                bestDistanceMax_2 = kNN_UpdateBestCaching(distance_q2_t6, 6, bestDistances_2, bestPointsIdx_2);
            if (distance_q2_t7 < bestDistanceMax_2)
                bestDistanceMax_2 = kNN_UpdateBestCaching(distance_q2_t7, 7, bestDistances_2, bestPointsIdx_2);

            if (distance_q3_t0 < bestDistanceMax_3)
                bestDistanceMax_3 = kNN_UpdateBestCaching(distance_q3_t0, 0, bestDistances_3, bestPointsIdx_3);
            if (distance_q3_t1 < bestDistanceMax_3)
                bestDistanceMax_3 = kNN_UpdateBestCaching(distance_q3_t1, 1, bestDistances_3, bestPointsIdx_3);
            if (distance_q3_t2 < bestDistanceMax_3)
                bestDistanceMax_3 = kNN_UpdateBestCaching(distance_q3_t2, 2, bestDistances_3, bestPointsIdx_3);
            if (distance_q3_t3 < bestDistanceMax_3)
                bestDistanceMax_3 = kNN_UpdateBestCaching(distance_q3_t3, 3, bestDistances_3, bestPointsIdx_3);
            if (distance_q3_t4 < bestDistanceMax_3)
                bestDistanceMax_3 = kNN_UpdateBestCaching(distance_q3_t4, 4, bestDistances_3, bestPointsIdx_3);
            if (distance_q3_t5 < bestDistanceMax_3)
                bestDistanceMax_3 = kNN_UpdateBestCaching(distance_q3_t5, 5, bestDistances_3, bestPointsIdx_3);
            if (distance_q3_t6 < bestDistanceMax_3)
                bestDistanceMax_3 = kNN_UpdateBestCaching(distance_q3_t6, 6, bestDistances_3, bestPointsIdx_3);
            if (distance_q3_t7 < bestDistanceMax_3)
                bestDistanceMax_3 = kNN_UpdateBestCaching(distance_q3_t7, 7, bestDistances_3, bestPointsIdx_3);

            if (distance_q4_t0 < bestDistanceMax_4)
                bestDistanceMax_4 = kNN_UpdateBestCaching(distance_q4_t0, 0, bestDistances_4, bestPointsIdx_4);
            if (distance_q4_t1 < bestDistanceMax_4)
                bestDistanceMax_4 = kNN_UpdateBestCaching(distance_q4_t1, 1, bestDistances_4, bestPointsIdx_4);
            if (distance_q4_t2 < bestDistanceMax_4)
                bestDistanceMax_4 = kNN_UpdateBestCaching(distance_q4_t2, 2, bestDistances_4, bestPointsIdx_4);
            if (distance_q4_t3 < bestDistanceMax_4)
                bestDistanceMax_4 = kNN_UpdateBestCaching(distance_q4_t3, 3, bestDistances_4, bestPointsIdx_4);
            if (distance_q4_t4 < bestDistanceMax_4)
                bestDistanceMax_4 = kNN_UpdateBestCaching(distance_q4_t4, 4, bestDistances_4, bestPointsIdx_4);
            if (distance_q4_t5 < bestDistanceMax_4)
                bestDistanceMax_4 = kNN_UpdateBestCaching(distance_q4_t5, 5, bestDistances_4, bestPointsIdx_4);
            if (distance_q4_t6 < bestDistanceMax_4)
                bestDistanceMax_4 = kNN_UpdateBestCaching(distance_q4_t6, 6, bestDistances_4, bestPointsIdx_4);
            if (distance_q4_t7 < bestDistanceMax_4)
                bestDistanceMax_4 = kNN_UpdateBestCaching(distance_q4_t7, 7, bestDistances_4, bestPointsIdx_4);

            if (distance_q5_t0 < bestDistanceMax_5)
                bestDistanceMax_5 = kNN_UpdateBestCaching(distance_q5_t0, 0, bestDistances_5, bestPointsIdx_5);
            if (distance_q5_t1 < bestDistanceMax_5)
                bestDistanceMax_5 = kNN_UpdateBestCaching(distance_q5_t1, 1, bestDistances_5, bestPointsIdx_5);
            if (distance_q5_t2 < bestDistanceMax_5)
                bestDistanceMax_5 = kNN_UpdateBestCaching(distance_q5_t2, 2, bestDistances_5, bestPointsIdx_5);
            if (distance_q5_t3 < bestDistanceMax_5)
                bestDistanceMax_5 = kNN_UpdateBestCaching(distance_q5_t3, 3, bestDistances_5, bestPointsIdx_5);
            if (distance_q5_t4 < bestDistanceMax_5)
                bestDistanceMax_5 = kNN_UpdateBestCaching(distance_q5_t4, 4, bestDistances_5, bestPointsIdx_5);
            if (distance_q5_t5 < bestDistanceMax_5)
                bestDistanceMax_5 = kNN_UpdateBestCaching(distance_q5_t5, 5, bestDistances_5, bestPointsIdx_5);
            if (distance_q5_t6 < bestDistanceMax_5)
                bestDistanceMax_5 = kNN_UpdateBestCaching(distance_q5_t6, 6, bestDistances_5, bestPointsIdx_5);
            if (distance_q5_t7 < bestDistanceMax_5)
                bestDistanceMax_5 = kNN_UpdateBestCaching(distance_q5_t7, 7, bestDistances_5, bestPointsIdx_5);

            if (distance_q6_t0 < bestDistanceMax_6)
                bestDistanceMax_6 = kNN_UpdateBestCaching(distance_q6_t0, 0, bestDistances_6, bestPointsIdx_6);
            if (distance_q6_t1 < bestDistanceMax_6)
                bestDistanceMax_6 = kNN_UpdateBestCaching(distance_q6_t1, 1, bestDistances_6, bestPointsIdx_6);
            if (distance_q6_t2 < bestDistanceMax_6)
                bestDistanceMax_6 = kNN_UpdateBestCaching(distance_q6_t2, 2, bestDistances_6, bestPointsIdx_6);
            if (distance_q6_t3 < bestDistanceMax_6)
                bestDistanceMax_6 = kNN_UpdateBestCaching(distance_q6_t3, 3, bestDistances_6, bestPointsIdx_6);
            if (distance_q6_t4 < bestDistanceMax_6)
                bestDistanceMax_6 = kNN_UpdateBestCaching(distance_q6_t4, 4, bestDistances_6, bestPointsIdx_6);
            if (distance_q6_t5 < bestDistanceMax_6)
                bestDistanceMax_6 = kNN_UpdateBestCaching(distance_q6_t5, 5, bestDistances_6, bestPointsIdx_6);
            if (distance_q6_t6 < bestDistanceMax_6)
                bestDistanceMax_6 = kNN_UpdateBestCaching(distance_q6_t6, 6, bestDistances_6, bestPointsIdx_6);
            if (distance_q6_t7 < bestDistanceMax_6)
                bestDistanceMax_6 = kNN_UpdateBestCaching(distance_q6_t7, 7, bestDistances_6, bestPointsIdx_6);

            if (distance_q7_t0 < bestDistanceMax_7)
                bestDistanceMax_7 = kNN_UpdateBestCaching(distance_q7_t0, 0, bestDistances_7, bestPointsIdx_7);
            if (distance_q7_t1 < bestDistanceMax_7)
                bestDistanceMax_7 = kNN_UpdateBestCaching(distance_q7_t1, 1, bestDistances_7, bestPointsIdx_7);
            if (distance_q7_t2 < bestDistanceMax_7)
                bestDistanceMax_7 = kNN_UpdateBestCaching(distance_q7_t2, 2, bestDistances_7, bestPointsIdx_7);
            if (distance_q7_t3 < bestDistanceMax_7)
                bestDistanceMax_7 = kNN_UpdateBestCaching(distance_q7_t3, 3, bestDistances_7, bestPointsIdx_7);
            if (distance_q7_t4 < bestDistanceMax_7)
                bestDistanceMax_7 = kNN_UpdateBestCaching(distance_q7_t4, 4, bestDistances_7, bestPointsIdx_7);
            if (distance_q7_t5 < bestDistanceMax_7)
                bestDistanceMax_7 = kNN_UpdateBestCaching(distance_q7_t5, 5, bestDistances_7, bestPointsIdx_7);
            if (distance_q7_t6 < bestDistanceMax_7)
                bestDistanceMax_7 = kNN_UpdateBestCaching(distance_q7_t6, 6, bestDistances_7, bestPointsIdx_7);
            if (distance_q7_t7 < bestDistanceMax_7)
                bestDistanceMax_7 = kNN_UpdateBestCaching(distance_q7_t7, 7, bestDistances_7, bestPointsIdx_7);
        }
    }
    CLASS_TYPE histogram_q0[N_CLASSES] = {0};
    CLASS_TYPE histogram_q1[N_CLASSES] = {0};
    CLASS_TYPE histogram_q2[N_CLASSES] = {0};
    CLASS_TYPE histogram_q3[N_CLASSES] = {0};
    CLASS_TYPE histogram_q4[N_CLASSES] = {0};
    CLASS_TYPE histogram_q5[N_CLASSES] = {0};
    CLASS_TYPE histogram_q6[N_CLASSES] = {0};
    CLASS_TYPE histogram_q7[N_CLASSES] = {0};

    for (int i = 0; i < K; i++)
    {
#pragma HLS UNROLL
        int bestIdx_q0 = bestPointsIdx_0[i];
        int bestIdx_q1 = bestPointsIdx_1[i];
        int bestIdx_q2 = bestPointsIdx_2[i];
        int bestIdx_q3 = bestPointsIdx_3[i];
        int bestIdx_q4 = bestPointsIdx_4[i];
        int bestIdx_q5 = bestPointsIdx_5[i];
        int bestIdx_q6 = bestPointsIdx_6[i];
        int bestIdx_q7 = bestPointsIdx_7[i];

        CLASS_TYPE cl_q0 = training_Y[bestIdx_q0];
        CLASS_TYPE cl_q1 = training_Y[bestIdx_q1];
        CLASS_TYPE cl_q2 = training_Y[bestIdx_q2];
        CLASS_TYPE cl_q3 = training_Y[bestIdx_q3];
        CLASS_TYPE cl_q4 = training_Y[bestIdx_q4];
        CLASS_TYPE cl_q5 = training_Y[bestIdx_q5];
        CLASS_TYPE cl_q6 = training_Y[bestIdx_q6];
        CLASS_TYPE cl_q7 = training_Y[bestIdx_q7];

        histogram_q0[(int)cl_q0]++;
        histogram_q1[(int)cl_q1]++;
        histogram_q2[(int)cl_q2]++;
        histogram_q3[(int)cl_q3]++;
        histogram_q4[(int)cl_q4]++;
        histogram_q5[(int)cl_q5]++;
        histogram_q6[(int)cl_q6]++;
        histogram_q7[(int)cl_q7]++;
    }

    CLASS_TYPE mostPopular_q0 = -1;
    CLASS_TYPE mostPopular_q1 = -1;
    CLASS_TYPE mostPopular_q2 = -1;
    CLASS_TYPE mostPopular_q3 = -1;
    CLASS_TYPE mostPopular_q4 = -1;
    CLASS_TYPE mostPopular_q5 = -1;
    CLASS_TYPE mostPopular_q6 = -1;
    CLASS_TYPE mostPopular_q7 = -1;

    int mostPopularCount_q0 = -1;
    int mostPopularCount_q1 = -1;
    int mostPopularCount_q2 = -1;
    int mostPopularCount_q3 = -1;
    int mostPopularCount_q4 = -1;
    int mostPopularCount_q5 = -1;
    int mostPopularCount_q6 = -1;
    int mostPopularCount_q7 = -1;

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
        if (histogram_q2[i] > mostPopularCount_q2)
        {
            mostPopularCount_q2 = histogram_q2[i];
            mostPopular_q2 = (CLASS_TYPE)i;
        }
        if (histogram_q3[i] > mostPopularCount_q3)
        {
            mostPopularCount_q3 = histogram_q3[i];
            mostPopular_q3 = (CLASS_TYPE)i;
        }
        if (histogram_q4[i] > mostPopularCount_q4)
        {
            mostPopularCount_q4 = histogram_q4[i];
            mostPopular_q4 = (CLASS_TYPE)i;
        }
        if (histogram_q5[i] > mostPopularCount_q5)
        {
            mostPopularCount_q5 = histogram_q5[i];
            mostPopular_q5 = (CLASS_TYPE)i;
        }
        if (histogram_q6[i] > mostPopularCount_q6)
        {
            mostPopularCount_q6 = histogram_q6[i];
            mostPopular_q6 = (CLASS_TYPE)i;
        }
        if (histogram_q7[i] > mostPopularCount_q7)
        {
            mostPopularCount_q7 = histogram_q7[i];
            mostPopular_q7 = (CLASS_TYPE)i;
        }
    }
    *res0 = mostPopular_q0;
    *res1 = mostPopular_q1;
    *res2 = mostPopular_q2;
    *res3 = mostPopular_q3;
    *res4 = mostPopular_q4;
    *res5 = mostPopular_q5;
    *res6 = mostPopular_q6;
    *res7 = mostPopular_q7;
}
