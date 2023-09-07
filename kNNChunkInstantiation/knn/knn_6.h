#pragma once

void kNN_Predict_6(DATA_TYPE training_X[N_TRAINING][N_FEATURES],
                   CLASS_TYPE training_Y[N_TRAINING],
                   DATA_TYPE min[N_FEATURES], DATA_TYPE max[N_FEATURES],
                   DATA_TYPE queryDatapoint_0[N_FEATURES],
                   DATA_TYPE queryDatapoint_1[N_FEATURES],
                   DATA_TYPE queryDatapoint_2[N_FEATURES],
                   DATA_TYPE queryDatapoint_3[N_FEATURES],
                   DATA_TYPE queryDatapoint_4[N_FEATURES],
                   DATA_TYPE queryDatapoint_5[N_FEATURES],
                   CLASS_TYPE *res0, CLASS_TYPE *res1, CLASS_TYPE *res2, CLASS_TYPE *res3, CLASS_TYPE *res4, CLASS_TYPE *res5);
