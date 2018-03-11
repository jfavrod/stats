#ifndef VARIANCE_H
#define VARIANCE_H

#include <stdio.h>
#include "helpers.h"

#define MAX_NUMBERS 102400

void usage();
extern double sample_variance(double values[], int count);
extern double population_variance(double values[], int count);
extern double sample_std_deviation(double values[], int count);
extern double population_std_deviation(double values[], int count);

#endif

