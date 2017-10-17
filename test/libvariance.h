#include <stdio.h>
#include "../src/libvariance.c"

#define TEST_COUNT 5
#define SAMPLE_SIZE 5
#define POPULATION_SIZE 7

double test_sample[TEST_COUNT][SAMPLE_SIZE] = {
    {5,9,7,7,10},
    {4,5,9,3,8},
    {7,10,7,6,2},
    {5,2,7,3,2},
    {9,10,2,9,6}
};


double test_population[TEST_COUNT][POPULATION_SIZE] = {
    {8,2,2,4,6,10,1},
    {9,7,3,2,3,2,8},
    {4,7,6,9,1,9,9},
    {2,2,10,3,8,3,9},
    {5,7,3,10,6,9,3}
};


double expected_sample_results[TEST_COUNT] = {
    3.800000, 6.700000, 8.300000, 4.700000, 10.700000
};


double expected_population_results[TEST_COUNT] = {
    9.918367, 7.836735, 7.959184, 10.775510, 6.408163
};

