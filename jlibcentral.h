#ifndef JLIBCENTRAL_H
#define JLIBCENTRAL_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "helpers.h"
#include <math.h>

#define MAX_NUMBERS 102400

double modes[MAX_NUMBERS] = {0};

struct m {
    int count;
    double *modes;
};

void usage(void);
double mean(double numbers[], int count);
double median(double numbers[], int count);
struct m mode(double numbers[], int count);
struct m new_m(int count, double modes[]);
int cmp_m (struct m m1, struct m m2);

#endif

