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

#pragma oss task device(fpga) in([4608000] data, [4500] label)inout([1024] theta)
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
    }
}

int main(int argc, char *argv[])
{
    float *data_points = (float *)malloc(DATA_SET_SIZE * sizeof(float));
    unsigned char *labels = (unsigned char *)malloc(NUM_SAMPLES * sizeof(unsigned char));
    float *param_vector = (float *)malloc(NUM_FEATURES * sizeof(float));

    const char *str_points_filepath = "shuffledfeats.dat";
    const char *str_labels_filepath = "shuffledlabels.dat";

    FILE *data_file;
    FILE *label_file;

    data_file = fopen(str_points_filepath, "r");
    if (!data_file)
    {
        printf("Failed to open data file %s, replacing with synthetic data\n", str_points_filepath);
        for (int i = 0; i < DATA_SET_SIZE; i++)
        {
            data_points[i] = (float)(rand() % 100);
        }
    }
    else
    {
        for (int i = 0; i < DATA_SET_SIZE; i++)
        {
            float tmp;
            fscanf(data_file, "%f", &tmp);
            data_points[i] = tmp;
        }
        fclose(data_file);
    }

    label_file = fopen(str_labels_filepath, "r");
    if (!label_file)
    {
        printf("Failed to open label file %s, replacing with synthetic data\n", str_labels_filepath);
        for (int i = 0; i < NUM_SAMPLES; i++)
        {
            labels[i] = (unsigned char)(rand() % 2);
        }
    }
    else
    {
        for (int i = 0; i < NUM_SAMPLES; i++)
        {
            int tmp;
            fscanf(label_file, "%d", &tmp);
            labels[i] = tmp;
        }
        fclose(label_file);
    }

    for (size_t i = 0; i < NUM_FEATURES; i++)
    {
        param_vector[i] = 0;
    }

    SgdLR_sw(data_points, labels, param_vector);
#pragma oss taskwait

    for (int i = 0; i < NUM_FEATURES; i += 64)
    {
        printf("param_vector[%i] = %f\n", i, param_vector[i]);
    }

    return EXIT_SUCCESS;
}
