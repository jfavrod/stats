#ifndef JLIBCENTRAL_H
#define JLIBCENTRAL_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "helpers.h"
#include <math.h>

#define MAX_NUMBERS 102400


struct m {
    int count;
    double *modes;
};

double modes[MAX_NUMBERS] = {0};

void usage(void);
double mean(double numbers[], int count);
double median(double numbers[], int count);
struct m mode(double numbers[], int count);

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

    /* Linux: */
    /* qsort(numbers, count, MAX_NUMBERS, ascending); */

    /* Darwin: */
    qsort(numbers, count, sizeof(tmp[0]), ascending);

    if ((count % 2) != 0) {
        int mid = ceil(count/2.0) - 1;
        tmp[0] = numbers[mid];
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

struct m mode(double numbers[], int count)
{

    double a[MAX_NUMBERS] = {0};
    int b[MAX_NUMBERS]    = {0};
    struct m mx           = {0, modes};

    /* abc - The count of elements in a and b (a b count). */
    int abc = 0;
    int i   = 0;
    int j   = 0;
    int max = 0;

    for (; i < count; i++) {
        int index = darray_indexof(numbers[i], a, abc);

        if (index == -1) {
            a[abc] = numbers[i];
            b[abc]++;
            abc++;
        }
        else {
            b[index]++;
        }
    }

    for (i = 0; i < abc; i++) {
        max = max_int(b, abc);

        if (b[i] == max) {
            mx.count++;
            mx.modes[j++] = a[i];
        }
    }

    return mx;
}

