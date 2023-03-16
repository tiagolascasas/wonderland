#ifndef __KNN_UTILS_H__
#define __KNN_UTILS_H__

#include "scenarios.h"
#include <math.h>

char get_class_name(class_t class_id);

void verify_results(int num_new_points, const class_t *classifications,
                    const class_t *key);

int get_reference_score(double time_s, int num_points);

void initialize_known_points(int num_points, Point *known_points,
                             int num_classes, int num_features);

void initialize_new_points(int num_new_points, Point *new_points,
                           int num_features);

void show_point(Point point, int num_features);

void minmax(datatype *min, datatype *max, int num_points, Point *known_points,
            int num_features);

void minmax_normalize(datatype *min, datatype *max, int num_points,
                      Point *points, int num_features);

#endif
