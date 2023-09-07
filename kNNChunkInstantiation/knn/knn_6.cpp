#include <cfloat>
#include <cmath>
#include "scenarios.h"
#include "design_params.h"

static double kNN_UpdateBestCaching(double queryDistance, int queryIdx,
                                    double bestDistances[K], int bestPointsIdx[K])
{
//#pragma HLS INLINE
    double worstOfBest = 0;
    int worstOfBestIdx = -1;
    double secondWorstOfBest = 0;
    int secondWorstOfBestIdx = -1;

    for (int i = 0; i < K; i++)
    {
//#pragma HLS PIPELINE
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

void kNN_Predict_6(DATA_TYPE training_X[N_TRAINING][N_FEATURES],
                   CLASS_TYPE training_Y[N_TRAINING],
                   DATA_TYPE min[N_FEATURES], DATA_TYPE max[N_FEATURES],
                   DATA_TYPE queryDatapoint_0[N_FEATURES],
                   DATA_TYPE queryDatapoint_1[N_FEATURES],
                   DATA_TYPE queryDatapoint_2[N_FEATURES],
                   DATA_TYPE queryDatapoint_3[N_FEATURES],
                   DATA_TYPE queryDatapoint_4[N_FEATURES],
                   DATA_TYPE queryDatapoint_5[N_FEATURES],
                   CLASS_TYPE *res0, CLASS_TYPE *res1, CLASS_TYPE *res2, CLASS_TYPE *res3, CLASS_TYPE *res4, CLASS_TYPE *res5)
{
#pragma HLS ARRAY_PARTITION variable = training_X type = cyclic factor = 6 dim = 1
//#pragma HLS ARRAY_PARTITION variable = queryDatapoint_0 type = complete
//#pragma HLS ARRAY_PARTITION variable = queryDatapoint_1 type = complete
//#pragma HLS ARRAY_PARTITION variable = queryDatapoint_2 type = complete
//#pragma HLS ARRAY_PARTITION variable = queryDatapoint_3 type = complete
//#pragma HLS ARRAY_PARTITION variable = queryDatapoint_4 type = complete
//#pragma HLS ARRAY_PARTITION variable = queryDatapoint_5 type = complete

#if NORMALIZE_IN_LOOP == 0
    for (int i = 0; i < N_FEATURES; i++)
    {
//#pragma HLS unroll
        DATA_TYPE nfeature_0 = (DATA_TYPE)((queryDatapoint_0[i] - min[i]) / (max[i] - min[i]));
        DATA_TYPE nfeature_1 = (DATA_TYPE)((queryDatapoint_1[i] - min[i]) / (max[i] - min[i]));
        DATA_TYPE nfeature_2 = (DATA_TYPE)((queryDatapoint_2[i] - min[i]) / (max[i] - min[i]));
        DATA_TYPE nfeature_3 = (DATA_TYPE)((queryDatapoint_3[i] - min[i]) / (max[i] - min[i]));
        DATA_TYPE nfeature_4 = (DATA_TYPE)((queryDatapoint_4[i] - min[i]) / (max[i] - min[i]));
        DATA_TYPE nfeature_5 = (DATA_TYPE)((queryDatapoint_5[i] - min[i]) / (max[i] - min[i]));

        queryDatapoint_0[i] = std::isnan(nfeature_0) ? 0.0 : (std::isinf(nfeature_0) ? 1.0 : nfeature_0);
        queryDatapoint_1[i] = std::isnan(nfeature_1) ? 0.0 : (std::isinf(nfeature_1) ? 1.0 : nfeature_1);
        queryDatapoint_2[i] = std::isnan(nfeature_2) ? 0.0 : (std::isinf(nfeature_2) ? 1.0 : nfeature_2);
        queryDatapoint_3[i] = std::isnan(nfeature_3) ? 0.0 : (std::isinf(nfeature_3) ? 1.0 : nfeature_3);
        queryDatapoint_4[i] = std::isnan(nfeature_4) ? 0.0 : (std::isinf(nfeature_4) ? 1.0 : nfeature_4);
        queryDatapoint_5[i] = std::isnan(nfeature_5) ? 0.0 : (std::isinf(nfeature_5) ? 1.0 : nfeature_5);
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

    for (int i = 0; i < K; i++)
    {
//#pragma HLS UNROLL
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
    }

    for (int i = 0; i < N_TRAINING; i += 4)
    {
        double distance_q0_t0 = 0.0F;
        double distance_q0_t1 = 0.0F;
        double distance_q0_t2 = 0.0F;
        double distance_q0_t3 = 0.0F;
        double distance_q0_t4 = 0.0F;
        double distance_q0_t5 = 0.0F;

        double distance_q1_t0 = 0.0F;
        double distance_q1_t1 = 0.0F;
        double distance_q1_t2 = 0.0F;
        double distance_q1_t3 = 0.0F;
        double distance_q1_t4 = 0.0F;
        double distance_q1_t5 = 0.0F;

        double distance_q2_t0 = 0.0F;
        double distance_q2_t1 = 0.0F;
        double distance_q2_t2 = 0.0F;
        double distance_q2_t3 = 0.0F;
        double distance_q2_t4 = 0.0F;
        double distance_q2_t5 = 0.0F;

        double distance_q3_t0 = 0.0F;
        double distance_q3_t1 = 0.0F;
        double distance_q3_t2 = 0.0F;
        double distance_q3_t3 = 0.0F;
        double distance_q3_t4 = 0.0F;
        double distance_q3_t5 = 0.0F;

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

        for (int j = 0; j < N_FEATURES; j++)
        {
//#pragma HLS PIPELINE
            DATA_TYPE q0_feat = queryDatapoint_0[j];
            DATA_TYPE q1_feat = queryDatapoint_1[j];
            DATA_TYPE q2_feat = queryDatapoint_2[j];
            DATA_TYPE q3_feat = queryDatapoint_3[j];
            DATA_TYPE q4_feat = queryDatapoint_4[j];
            DATA_TYPE q5_feat = queryDatapoint_5[j];

#if NORMALIZE_IN_LOOP == 1
            q0_feat = (DATA_TYPE)((q0_feat - min[i]) / (max[i] - min[i]));
            q1_feat = (DATA_TYPE)((q1_feat - min[i]) / (max[i] - min[i]));
            q2_feat = (DATA_TYPE)((q2_feat - min[i]) / (max[i] - min[i]));
            q3_feat = (DATA_TYPE)((q3_feat - min[i]) / (max[i] - min[i]));
            q4_feat = (DATA_TYPE)((q4_feat - min[i]) / (max[i] - min[i]));
            q5_feat = (DATA_TYPE)((q5_feat - min[i]) / (max[i] - min[i]));

            q0_feat = std::isnan(q0_feat) ? 0.0 : (std::isinf(q0_feat) ? 1.0 : q0_feat);
            q1_feat = std::isnan(q1_feat) ? 0.0 : (std::isinf(q1_feat) ? 1.0 : q1_feat);
            q2_feat = std::isnan(q2_feat) ? 0.0 : (std::isinf(q2_feat) ? 1.0 : q2_feat);
            q3_feat = std::isnan(q3_feat) ? 0.0 : (std::isinf(q3_feat) ? 1.0 : q3_feat);
            q4_feat = std::isnan(q4_feat) ? 0.0 : (std::isinf(q4_feat) ? 1.0 : q4_feat);
            q5_feat = std::isnan(q5_feat) ? 0.0 : (std::isinf(q5_feat) ? 1.0 : q5_feat);
#endif

            DATA_TYPE t0_feat = training_X[i + 0][j];
            DATA_TYPE t1_feat = training_X[i + 1][j];
            DATA_TYPE t2_feat = training_X[i + 2][j];
            DATA_TYPE t3_feat = training_X[i + 3][j];
            DATA_TYPE t4_feat = training_X[i + 4][j];
            DATA_TYPE t5_feat = training_X[i + 5][j];

            // -----------------------------------------
            double diff_q0_t0 = q0_feat - t0_feat;
            double diff_q1_t1 = q1_feat - t1_feat;
            double diff_q2_t2 = q2_feat - t2_feat;
            double diff_q3_t3 = q3_feat - t3_feat;
            double diff_q4_t4 = q4_feat - t4_feat;
            double diff_q5_t5 = q5_feat - t5_feat;

            distance_q0_t0 += diff_q0_t0 * diff_q0_t0;
            distance_q1_t1 += diff_q1_t1 * diff_q1_t1;
            distance_q2_t2 += diff_q2_t2 * diff_q2_t2;
            distance_q3_t3 += diff_q3_t3 * diff_q3_t3;
            distance_q4_t4 += diff_q4_t4 * diff_q4_t4;
            distance_q5_t5 += diff_q5_t5 * diff_q5_t5;

            // -----------------------------------------
            double diff_q0_t1 = q0_feat - t1_feat;
            double diff_q1_t2 = q1_feat - t2_feat;
            double diff_q2_t3 = q2_feat - t3_feat;
            double diff_q3_t4 = q3_feat - t4_feat;
            double diff_q4_t5 = q4_feat - t5_feat;
            double diff_q5_t0 = q5_feat - t0_feat;

            distance_q0_t1 += diff_q0_t1 * diff_q0_t1;
            distance_q1_t2 += diff_q1_t2 * diff_q1_t2;
            distance_q2_t3 += diff_q2_t3 * diff_q2_t3;
            distance_q3_t4 += diff_q3_t4 * diff_q3_t4;
            distance_q4_t5 += diff_q4_t5 * diff_q4_t5;
            distance_q5_t0 += diff_q5_t0 * diff_q5_t0;

            // -----------------------------------------
            double diff_q0_t2 = q0_feat - t2_feat;
            double diff_q1_t3 = q1_feat - t3_feat;
            double diff_q2_t4 = q2_feat - t4_feat;
            double diff_q3_t5 = q3_feat - t5_feat;
            double diff_q4_t0 = q4_feat - t0_feat;
            double diff_q5_t1 = q5_feat - t1_feat;

            distance_q0_t2 += diff_q0_t2 * diff_q0_t2;
            distance_q1_t3 += diff_q1_t3 * diff_q1_t3;
            distance_q2_t4 += diff_q2_t4 * diff_q2_t4;
            distance_q3_t5 += diff_q3_t5 * diff_q3_t5;
            distance_q4_t0 += diff_q4_t0 * diff_q4_t0;
            distance_q5_t1 += diff_q5_t1 * diff_q5_t1;

            // -----------------------------------------
            double diff_q0_t3 = q0_feat - t3_feat;
            double diff_q1_t4 = q1_feat - t4_feat;
            double diff_q2_t5 = q2_feat - t5_feat;
            double diff_q3_t0 = q3_feat - t0_feat;
            double diff_q4_t1 = q4_feat - t1_feat;
            double diff_q5_t2 = q5_feat - t2_feat;

            distance_q0_t3 += diff_q0_t3 * diff_q0_t3;
            distance_q1_t4 += diff_q1_t4 * diff_q1_t4;
            distance_q2_t5 += diff_q2_t5 * diff_q2_t5;
            distance_q3_t0 += diff_q3_t0 * diff_q3_t0;
            distance_q4_t1 += diff_q4_t1 * diff_q4_t1;
            distance_q5_t2 += diff_q5_t2 * diff_q5_t2;

            // -----------------------------------------
            double diff_q0_t4 = q0_feat - t4_feat;
            double diff_q1_t5 = q1_feat - t5_feat;
            double diff_q2_t0 = q2_feat - t0_feat;
            double diff_q3_t1 = q3_feat - t1_feat;
            double diff_q4_t2 = q4_feat - t2_feat;
            double diff_q5_t3 = q5_feat - t3_feat;

            distance_q0_t4 += diff_q0_t4 * diff_q0_t4;
            distance_q1_t5 += diff_q1_t5 * diff_q1_t5;
            distance_q2_t0 += diff_q2_t0 * diff_q2_t0;
            distance_q3_t1 += diff_q3_t1 * diff_q3_t1;
            distance_q4_t2 += diff_q4_t2 * diff_q4_t2;
            distance_q5_t3 += diff_q5_t3 * diff_q5_t3;

            // -----------------------------------------
            double diff_q0_t5 = q0_feat - t5_feat;
            double diff_q1_t0 = q1_feat - t0_feat;
            double diff_q2_t1 = q2_feat - t1_feat;
            double diff_q3_t2 = q3_feat - t2_feat;
            double diff_q4_t3 = q4_feat - t3_feat;
            double diff_q5_t4 = q5_feat - t4_feat;

            distance_q0_t5 += diff_q0_t5 * diff_q0_t5;
            distance_q1_t0 += diff_q1_t0 * diff_q1_t0;
            distance_q2_t1 += diff_q2_t1 * diff_q2_t1;
            distance_q3_t2 += diff_q3_t2 * diff_q3_t2;
            distance_q4_t3 += diff_q4_t3 * diff_q4_t3;
            distance_q5_t4 += diff_q5_t4 * diff_q5_t4;
        }

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
    }

    CLASS_TYPE histogram_q0[N_CLASSES] = {0};
    CLASS_TYPE histogram_q1[N_CLASSES] = {0};
    CLASS_TYPE histogram_q2[N_CLASSES] = {0};
    CLASS_TYPE histogram_q3[N_CLASSES] = {0};
    CLASS_TYPE histogram_q4[N_CLASSES] = {0};
    CLASS_TYPE histogram_q5[N_CLASSES] = {0};

    for (int i = 0; i < K; i++)
    {
//#pragma HLS UNROLL
        int bestIdx_q0 = bestPointsIdx_0[i];
        int bestIdx_q1 = bestPointsIdx_1[i];
        int bestIdx_q2 = bestPointsIdx_2[i];
        int bestIdx_q3 = bestPointsIdx_3[i];
        int bestIdx_q4 = bestPointsIdx_4[i];
        int bestIdx_q5 = bestPointsIdx_5[i];

        CLASS_TYPE cl_q0 = training_Y[bestIdx_q0];
        CLASS_TYPE cl_q1 = training_Y[bestIdx_q1];
        CLASS_TYPE cl_q2 = training_Y[bestIdx_q2];
        CLASS_TYPE cl_q3 = training_Y[bestIdx_q3];
        CLASS_TYPE cl_q4 = training_Y[bestIdx_q4];
        CLASS_TYPE cl_q5 = training_Y[bestIdx_q5];

        histogram_q0[(int)cl_q0]++;
        histogram_q1[(int)cl_q1]++;
        histogram_q2[(int)cl_q2]++;
        histogram_q3[(int)cl_q3]++;
        histogram_q4[(int)cl_q4]++;
        histogram_q5[(int)cl_q5]++;
    }

    CLASS_TYPE mostPopular_q0 = -1;
    CLASS_TYPE mostPopular_q1 = -1;
    CLASS_TYPE mostPopular_q2 = -1;
    CLASS_TYPE mostPopular_q3 = -1;
    CLASS_TYPE mostPopular_q4 = -1;
    CLASS_TYPE mostPopular_q5 = -1;
    int mostPopularCount_q0 = -1;
    int mostPopularCount_q1 = -1;
    int mostPopularCount_q2 = -1;
    int mostPopularCount_q3 = -1;
    int mostPopularCount_q4 = -1;
    int mostPopularCount_q5 = -1;

    for (int i = 0; i < N_CLASSES; i++)
    {
//#pragma HLS PIPELINE
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
    }
    *res0 = mostPopular_q0;
    *res1 = mostPopular_q1;
    *res2 = mostPopular_q2;
    *res3 = mostPopular_q3;
    *res4 = mostPopular_q4;
    *res5 = mostPopular_q5;
}
