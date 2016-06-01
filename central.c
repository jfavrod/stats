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
double mode(double numbers[], int count);

#define MAX_NUMBERS 1000000

#endif


int main(int argc, char *argv[])
{
    double numbers[MAX_NUMBERS] = {0.0};
    int    count                = 0;

    if (argc != 3 || !validateCSV(argv[2])) {
        usage();
    }
    else {
        translateCSV(argv[2], numbers, &count);
        if (strcmp(argv[1], "mean") == 0) {
            printf("The mean is: %f\n", mean(numbers, count));
        }
        else if (strcmp(argv[1], "median") == 0) {
            printf("The median is: %f\n", median(numbers, count));
        }
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
    printf("mode numbers is: ");

    return 0.0;
}

