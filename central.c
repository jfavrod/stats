#ifndef CENTRAL_H
#define CENTRAL_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "helpers.h"
#include <math.h>

void usage(void);
double mean(double numbers[], int count);
double median(double numbers[], int count);

#define MAX_NUMBERS 1000000

#endif


int main(int argc, char *argv[])
{
    double numbers[MAX_NUMBERS] = {0.0};
    int    count                = 0;

    if (argc == 1 || argc < 1 || argc > 3 || !validateCSV(argv[2])) {
        usage();
    }
    else {
        translateCSV(argv[2], numbers, &count);
        if (strcmp(argv[1], "mean") == 0) {
            mean(numbers, count);
        }
        /*
        else if (strcmp(argv[1], "median") == 0) {
            median(argv[2]);
        }
        */
        else {
            usage();
        }
    }

    return 0;
}


void usage()
{
    int i = 0;
    char *item[6] = {
        "usage:",
        "Find the central tendency of a list of numbers.",
        "(list is CSV with no spaces)\n",
        "mean [list of numbers]",
        "median [list of numbers]",
        "mode [list of numbers]"
    };

    for (; i < (sizeof(item)/sizeof(char *)); i++) {
        printf("%s\n", item[i]);
    }
}


/**
 * mean
 *
 * @param char numbers[] a string representation of a csv list of
 * numbers (ints or doubles).
 *
 * @return void
 */

double mean(double numbers[], int count)
{
    int    i   = 0;
    double sum = 0.0;

    for (; i < count; i++) {
        sum = sum + numbers[i];
    }

    printf("The mean is: %f\n", sum/count);
    return sum/count;
}


/**
 * median
 *
 * @param char numbers[] a string representation of a csv list of
 * numbers (ints or doubles).
 *
 * @return double The median of the given numbers.
 */

double median(double numbers[], int count)
{
    return 0.0;
}


/**
 * mode
 *
 * @param char numbers[] a string representation of a csv list of
 * numbers (ints or doubles).
 *
 * @return void
 */

double mode(char numbers[])
{
    printf("mode numbers are %s\n", numbers);

    return 0.0;
}

