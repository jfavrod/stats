#ifndef JLIBCENTRAL_H
#define JLIBCENTRAL_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "helpers.h"
#include <math.h>

void usage(void);
double mean(double numbers[], int count);
double median(double numbers[], int count);
double mode(double numbers[], int count);

#define MAX_NUMBERS 102400

#endif


/**
 * mean
 *
 * Finds the mean of a given numerical dataset.
 *
 * @param double numbers[] Our numerical dataset.
 * @param int count The number of items in the dataset.
 *
 * @return double The mean of the dataset.
 */

double mean(double numbers[], int count)
{
    int    i   = 0;
    double sum = 0.0;

    for (; i < count; i++) {
        sum = sum + numbers[i];
    }

    return sum/count;
}


/**
 * median
 *
 * Finds the median of a given numerical dataset.
 *
 * @param double numbers[] Our numerical dataset.
 * @param int count The number of items in the dataset.
 *
 * @return double The median of the dataset.
 */

double median(double numbers[], int count)
{
    double tmp[2];

    qsort(numbers, count, MAX_NUMBERS, ascending);

    if ((count % 2) != 0) {
        tmp[0] = numbers[(int)ceil(count/2)];
    }
    else {
        tmp[0] = numbers[count/2];
        tmp[1] = numbers[(count/2)-1];
        tmp[0] = mean(tmp, 2);
    }

    return tmp[0];
}


/**
 * mode
 *
 * Finds the mode of a given numerical dataset.
 *
 * @param double numbers[] Our numerical dataset.
 * @param int count The number of items in the dataset.
 *
 * @return double The mode of the dataset.
 */

double mode(double numbers[], int count)
{
    int n = -1;
    int i = 0;
    double a[MAX_NUMBERS];
    double b[MAX_NUMBERS];

    for (; i < count; i++) {
        if (in_darray(numbers[i], a, count)) {
            printf("in array\n");
        }
    }

    return 0.0;
}

