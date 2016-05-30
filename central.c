#ifndef CENTRAL_H
#define CENTRAL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "helpers.h"
#include <math.h>

void usage(void);
int validateCSV(char numbers[]);
double mean(char numbers[]);
double median(char numbers[]);

#define FALSE 0
#define TRUE 1
#define MAX_CHARS 80

#endif


int main(int argc, char *argv[])
{
    if (argc == 1 || argc < 1 || argc > 3 || !validateCSV(argv[2])) {
        usage();
    }
    else {
        if (strcmp(argv[1], "mean") == 0) {
            mean(argv[2]);
        }
        if (strcmp(argv[1], "median") == 0) {
            median(argv[2]);
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
 * validateCSV
 *
 * Checks the numbers string is a CSV list of numbers --
 * either ints or doubles.
 *
 * @param char numbers[] A string representation of a CSV list of
 * numbers (ints or doubles).
 *
 * @return int TRUE if numbers string is a valid CSV list of numbers,
 * FALSE otherwise.
 */

int validateCSV(char numbers[])
{ 
    int  boolean = TRUE;
    int  i       = 0;
    int  dec     = 0;
    char tmpc    = '\0';

    while ((tmpc = numbers[i]) != '\0') {
        if (!isdigit(tmpc)) {
            if (tmpc == '.' && dec == 0) {
                ++dec;
                ++i;
            }
            else if (tmpc == ',') {
                dec = 0;
                ++i;
            }
            else {
                boolean = FALSE;
                break;
            }
        }
        else {
            ++i;
        }
    }

    /* Make sure the last entry in the list is a digit. */
    if (!isdigit(tmpc = numbers[--i])) {
        boolean = FALSE;
    }

    boolean ? : printf("The CSV is malformed!\n\n");
    return boolean;
}


/**
 * mean
 *
 * @param char numbers[] a string representation of a csv list of
 * numbers (ints or doubles).
 *
 * @return void
 */

double mean(char numbers[])
{
    int    i              = 0;
    int    j              = 0;
    double count          = 0.0;
    double sum            = 0.0;
    char   tmp[MAX_CHARS] = "";

    do {
        tmp[i] = numbers[j];
        if (tmp[i] == ',' || tmp[i] == '\0') {
            tmp[i] = '\0';
            sum = sum + atof(tmp);
            ++count;
            str_clear(tmp);
            i = -1;
        }
        i++;
    }
    while (numbers[j++] != '\0');

    printf("The mean is %f\n", sum/count);
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

double median(char numbers[])
{

    int i     = 0;
    int count = 0;
    int midpt = 0;

    do {
        if (numbers[i] == ',' || numbers[i] == '\0') {
            ++count;
        }
    }
    while (numbers[i++] != '\0');

    mid = (int)ceil((double)count/2.0);

    if ((count % 2) != 0) {
        count = 0;
    }

    printf("the middle position is %i\n", mid);

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

    return;
}

