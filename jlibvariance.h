#ifndef JLIBVARIANCE_H
#define JLIBVARIANCE_H

#include <math.h>
#include "helpers.h"

extern double mean(double values[], int count);

double range(double values[], int count);
double sample_variance(double values[], int count);

#endif

