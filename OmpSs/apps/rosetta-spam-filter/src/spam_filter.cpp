#include <cstdio>
#include <cstdlib>

const int NUM_FEATURES = 1024;
const int NUM_SAMPLES = 5000;
const int NUM_TRAINING = 4500;
const int NUM_TESTING = 500;
const int STEP_SIZE = 60000;
const int NUM_EPOCHS = 5;
const int DATA_SET_SIZE = NUM_FEATURES * NUM_SAMPLES;

#define PAR_FACTOR 32

#pragma oss task device(smp) in([1] epoch)
void print_task(int *epoch)
{
    printf("Epoch %d done\n", *epoch);
}

// #pragma oss task device(smp) in([1] f, [1] lower_bound, [1] upper_bound)
// void assert_task(float *f, float *lower_bound, float *upper_bound)
// {
//     if (*f > *lower_bound && *f < *upper_bound)
//     {
//         printf("assertion passed\n");
//     }
//     else
//     {
//         printf("assertion failed\n");
//     }
// }

#pragma oss task device(fpga) in([4608000] data, [NUM_TRAINING] label)inout([NUM_FEATURES] theta)
void SgdLR_sw(float data[NUM_FEATURES * NUM_TRAINING],
              unsigned char label[NUM_TRAINING],
              float theta[NUM_FEATURES])
{
    float gradient[NUM_FEATURES];

    for (int epoch = 0; epoch < NUM_EPOCHS; epoch++)
    {
        for (int training_id = 0; training_id < NUM_TRAINING; training_id++)
        {
            float dot = 0;
            for (int i = 0; i < NUM_FEATURES; i++)
            {
                dot += theta[i] * data[NUM_FEATURES * training_id + i];
            }

            float expf = 1.0f;
            float term = 1.0f;
            int n = 1;
            const int max_terms = 10;

            while (n < max_terms)
            {
                term *= (-dot) / n;
                expf += term;
                n++;
            }

            float prob = 1.0f / (1.0f + expf);

            float scale = prob - label[training_id];
            for (int i = 0; i < NUM_FEATURES; i++)
            {
                gradient[i] = scale * data[NUM_FEATURES * training_id + i];
            }

            for (int i = 0; i < NUM_FEATURES; i++)
            {
                theta[i] += -STEP_SIZE * gradient[i];
            }
        }
        print_task(&epoch);
#pragma oss taskwait
    }
    float lb1 = 2802.336181;
    float ub1 = 2802.336183;
    float lb2 = -8321.051759;
    float ub2 = -8321.051757;

    //    assert_task(&theta[1], &lb1, &ub1);
    // #pragma oss taskwait
    //    assert_task(&theta[1023], &lb2, &ub2);
    // #pragma oss taskwait
}

int main(int argc, char *argv[])
{
    float *data_points = (float *)malloc(DATA_SET_SIZE * sizeof(float));
    unsigned char *labels = (unsigned char *)malloc(NUM_SAMPLES * sizeof(unsigned char));
    float *param_vector = (float *)malloc(NUM_FEATURES * sizeof(float));

    SgdLR_sw(data_points, labels, param_vector);
#pragma oss taskwait

    return EXIT_SUCCESS;
}
