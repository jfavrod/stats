#ifndef CENTRAL_H
#define CENTRAL_H

#include <stdio.h>
#include <string.h>

#define MAX_NUMBERS 102400

struct m {
    int count;
    double *modes;
};

extern double modes[];
extern int validateCSV(char numbersCSV[]);
extern void translateCSV(char numbersCSV[], double numbers[], int * count);
extern void print_darray(double a[], int count);
extern double mean(double numbers[], int count);
extern double median(double numbers[], int count);
extern struct m mode(double numbers[], int count);
extern struct m new_m(int count, double modes[]);
extern int cmp_m (struct m m1, struct m m2);

void usage();

#endif

