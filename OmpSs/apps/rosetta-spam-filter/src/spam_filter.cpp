#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <iostream>
#include <getopt.h>
#include <string>
#include <cmath>
#include <time.h>
#include <sys/time.h>

#define SW

const int NUM_FEATURES = 1024;
const int NUM_SAMPLES = 5000;
const int NUM_TRAINING = 4500;
const int NUM_TESTING = 500;
const int STEP_SIZE = 60000;
const int NUM_EPOCHS = 5;
const int DATA_SET_SIZE = NUM_FEATURES * NUM_SAMPLES;

typedef float FeatureType;
typedef float DataType;
typedef unsigned char LabelType;

#define PAR_FACTOR 32

void print_usage(char *filename)
{
    printf("usage: %s <options>\n", filename);
    printf("  -f [kernel file]\n");
    printf("  -p [path to data]\n");
}

void parse_sdaccel_command_line_args(
    int argc,
    char **argv,
    std::string &kernelFile,
    std::string &path_to_data)
{

    int c = 0;

    while ((c = getopt(argc, argv, "f:p:")) != -1)
    {
        switch (c)
        {
        case 'f':
            kernelFile = optarg;
            break;
        case 'p':
            path_to_data = optarg;
            break;
        default:
        {
            print_usage(argv[0]);
            exit(-1);
        }
        } // matching on arguments
    } // while args present
}

void parse_sdsoc_command_line_args(
    int argc,
    char **argv,
    std::string &path_to_data)
{

    int c = 0;

    while ((c = getopt(argc, argv, "f:p:")) != -1)
    {
        switch (c)
        {
        case 'p':
            path_to_data = optarg;
            break;
        default:
        {
            print_usage(argv[0]);
            exit(-1);
        }
        } // matching on arguments
    } // while args present
}

// data structure only used in this file
typedef struct DataSet_s
{
    DataType *data_points;
    LabelType *labels;
    FeatureType *parameter_vector;
    size_t num_data_points;
    size_t num_features;
} DataSet;

// sub-functions for result checking
// dot product
float dotProduct(FeatureType *param_vector, DataType *data_point_i, const size_t num_features)
{
    FeatureType result = 0.0f;

    for (int i = 0; i < num_features; i++)
        result += param_vector[i] * data_point_i[i];

#ifndef SW
    return result.to_float();
#else
    return result;
#endif
}

// predict
LabelType getPrediction(FeatureType *parameter_vector, DataType *data_point_i, size_t num_features, const double treshold = 0)
{
    float parameter_vector_dot_x_i = dotProduct(parameter_vector, data_point_i, num_features);
    return (parameter_vector_dot_x_i > treshold) ? 1 : 0;
}

// compute error rate
double computeErrorRate(
    DataSet data_set,
    double &cumulative_true_positive_rate,
    double &cumulative_false_positive_rate,
    double &cumulative_error)
{

    size_t true_positives = 0, true_negatives = 0, false_positives = 0, false_negatives = 0;

    for (size_t i = 0; i < data_set.num_data_points; i++)
    {
        LabelType prediction = getPrediction(data_set.parameter_vector, &data_set.data_points[i * data_set.num_features], data_set.num_features);
        if (prediction != data_set.labels[i])
        {
            if (prediction == 1)
                false_positives++;
            else
                false_negatives++;
        }
        else
        {
            if (prediction == 1)
                true_positives++;
            else
                true_negatives++;
        }
    }

    double error_rate = (double)(false_positives + false_negatives) / data_set.num_data_points;

    cumulative_true_positive_rate += (double)true_positives / (true_positives + false_negatives);
    cumulative_false_positive_rate += (double)false_positives / (false_positives + true_negatives);
    cumulative_error += error_rate;

    return error_rate;
}

// check results
void check_results(FeatureType *param_vector, DataType *data_points, LabelType *labels)
{
    std::ofstream ofile;
    ofile.open("output.txt");
    if (ofile.is_open())
    {
        ofile << "\nmain parameter vector: \n";
        for (int i = 0; i < 30; i++)
#ifndef SW
            ofile << "m[" << i << "]: " << param_vector[i].to_float() << " | ";
#else
            ofile << "m[" << i << "]: " << param_vector[i] << " | ";
#endif
        ofile << std::endl;

        // Initialize benchmark variables
        double training_tpr = 0.0;
        double training_fpr = 0.0;
        double training_error = 0.0;
        double testing_tpr = 0.0;
        double testing_fpr = 0.0;
        double testing_error = 0.0;

        // Get Training error
        DataSet training_set;
        training_set.data_points = data_points;
        training_set.labels = labels;
        training_set.num_data_points = NUM_TRAINING;
        training_set.num_features = NUM_FEATURES;
        training_set.parameter_vector = param_vector;
        computeErrorRate(training_set, training_tpr, training_fpr, training_error);

        // Get Testing error
        DataSet testing_set;
        testing_set.data_points = &data_points[NUM_FEATURES * NUM_TRAINING];
        testing_set.labels = &labels[NUM_TRAINING];
        testing_set.num_data_points = NUM_TESTING;
        testing_set.num_features = NUM_FEATURES;
        testing_set.parameter_vector = param_vector;
        computeErrorRate(testing_set, testing_tpr, testing_fpr, testing_error);

        training_tpr *= 100.0;
        training_fpr *= 100.0;
        training_error *= 100.0;
        testing_tpr *= 100.0;
        testing_fpr *= 100.0;
        testing_error *= 100.0;

        ofile << "Training TPR: " << training_tpr << std::endl;
        ofile << "Training FPR: " << training_fpr << std::endl;
        ofile << "Training Error: " << training_error << std::endl;
        ofile << "Testing TPR: " << testing_tpr << std::endl;
        ofile << "Testing FPR: " << testing_fpr << std::endl;
        ofile << "Testing Error: " << testing_error << std::endl;
    }
    else
    {
        std::cout << "Failed to create output file!" << std::endl;
    }
}

#pragma oss task device(smp) in([1] epoch)
void print_task(int epoch)
{
    printf("Epoch %d done\n", epoch);
}

#pragma oss task device(smp) in([1] f)
void assert_task(FeatureType f, FeatureType lower_bound, FeatureType upper_bound)
{
    if (f > lower_bound && f < upper_bound)
    {
        printf("assertion passed\n");
    }
    else
    {
        printf("assertion failed\n");
    }
}

#pragma oss task device(fpga) in([NUM_FEATURES * NUM_TRAINING] data, [NUM_TRAINING] label) inout([NUM_FEATURES] theta)
void SgdLR_sw(DataType data[NUM_FEATURES * NUM_TRAINING],
              LabelType label[NUM_TRAINING],
              FeatureType theta[NUM_FEATURES])
{
    FeatureType gradient[NUM_FEATURES];

    for (int epoch = 0; epoch < NUM_EPOCHS; epoch++)
    {
        for (int training_id = 0; training_id < NUM_TRAINING; training_id++)
        {
            DataType *feature = &data[NUM_FEATURES * training_id];
            FeatureType dot = 0;
            for (int i = 0; i < NUM_FEATURES; i++)
            {
                dot += theta[i] * feature[i];
            }

            FeatureType prob = 1.0f / (1.0f + expf(-dot));

            FeatureType scale = prob - label[training_id];
            for (int i = 0; i < NUM_FEATURES; i++)
            {
                gradient[i] = scale * data[NUM_FEATURES * training_id + i];
            }

            for (int i = 0; i < NUM_FEATURES; i++)
            {
                theta[i] += -STEP_SIZE * gradient[i];
            }
        }
        printf("Epoch %d done\n", epoch);
#pragma oss taskwait
    }
    assert_task(theta[1], 2802.336181, 2802.336183);
#pragma oss taskwait
    assert_task(theta[1023], -8321.051759, -8321.051757);
#pragma oss taskwait
}

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);

    printf("Spam Filter Application\n");

    std::string path_to_data("");
    parse_sdsoc_command_line_args(argc, argv, path_to_data);

    // allocate space
    // for software verification
    DataType *data_points = new DataType[DATA_SET_SIZE];
    LabelType *labels = new LabelType[NUM_SAMPLES];
    FeatureType *param_vector = new FeatureType[NUM_FEATURES];

    // read in dataset
    std::string str_points_filepath = path_to_data + "./shuffledfeats.dat";
    std::string str_labels_filepath = path_to_data + "./shuffledlabels.dat";

    FILE *data_file;
    FILE *label_file;

    data_file = fopen(str_points_filepath.c_str(), "r");
    if (!data_file)
    {
        printf("Failed to open data file %s!\n", str_points_filepath.c_str());
        return EXIT_FAILURE;
    }
    for (int i = 0; i < DATA_SET_SIZE; i++)
    {
        float tmp;
        fscanf(data_file, "%f", &tmp);
        data_points[i] = tmp;
    }
    fclose(data_file);

    label_file = fopen(str_labels_filepath.c_str(), "r");
    if (!label_file)
    {
        printf("Failed to open label file %s!\n", str_labels_filepath.c_str());
        return EXIT_FAILURE;
    }
    for (int i = 0; i < NUM_SAMPLES; i++)
    {
        int tmp;
        fscanf(label_file, "%d", &tmp);
        labels[i] = tmp;
    }
    fclose(label_file);

    // reset parameter vector
    for (size_t i = 0; i < NUM_FEATURES; i++)
        param_vector[i] = 0;

    // timers
    struct timeval start, end;

    gettimeofday(&start, NULL);
    SgdLR_sw(data_points, labels, param_vector);
#pragma oss taskwait
    gettimeofday(&end, NULL);

    // check results
    printf("Checking results:\n");
    check_results(param_vector, data_points, labels);

    // print time
    long long elapsed = (end.tv_sec - start.tv_sec) * 1000000LL + end.tv_usec - start.tv_usec;
    printf("elapsed time: %lld us\n", elapsed);

    delete[] data_points;
    delete[] labels;
    delete[] param_vector;

    return EXIT_SUCCESS;
}
