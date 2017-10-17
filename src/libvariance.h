#ifndef LIBVARIANCE_H
#define LIBVARIANCE_H

#include <math.h>
#include "helpers.h"

extern double mean(double values[], int count);

double range(double values[], int count);
double sample_variance(double values[], int count);
double population_variance(double values[], int count);
double sample_std_deviation(double values[], int count);
double population_std_deviation(double values[], int count);

#endif

