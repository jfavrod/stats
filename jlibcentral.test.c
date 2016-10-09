#include "jlibcentral.c"

/* Increment whenever adding a test_array. */
#define TEST_COUNT 3

void test_mean(double input[], int count, double expected);
void test_median(double input[], int count, double expected);
void test_mode(double input[], int in_count, double expected[], int ex_count);
struct m new_m(int count, double numbers[]);


/* Add an array of numbers to the test_array. */
double test_array[TEST_COUNT][MAX_NUMBERS] = {
    {12.3, 10.6, 14.0, 27.2, 9.0},
    {1, 2, 4, 7, 7, 10, 2, 4, 5, 22},
    {26, 33, 65, 28, 34, 55, 25, 44, 50, 36, 26, 37, 43, 62, 35, 38, 45, 32, 28, 34}
};

/* Corresponds to the count of numbers in each test_array entry. */
int count[TEST_COUNT] = {5, 10, 20};

/* The expected outcomes of the tests */
double mean_expected[TEST_COUNT]   = { 14.62, 6.4, 38.8};
double median_expected[TEST_COUNT] = { 12.3, 4.5, 35.5 };
double mode_expected[TEST_COUNT][MAX_NUMBERS] = {
    {12.3, 10.6, 14.0, 27.2, 9.0},
    {2, 4, 7},
    {26, 28, 34}
};

/* Corresponds with the count of numbers in mode_expected array entry. */
int mode_expected_count[] = {5, 3, 3};


int main()
{
    int i;

    for (i = 0; i < TEST_COUNT; i++) {
        printf("\n");
        test_mean(test_array[i], count[i], mean_expected[i]);
        test_median(test_array[i], count[i], median_expected[i]);
        test_mode(test_array[i], count[i], mode_expected[i], mode_expected_count[i]);
    }
    printf("\n");

    return 0;
}


void test_mean(double input[], int count, double expected)
{
    double actual = mean(input, count);

    printf("Testing mean\n" );
    printf("Expecting %f and got %f: ", expected, actual);

    if (expected == actual) {
        printf("pass.\n");
    }
    else {
        printf("fail.\n");
    }
}


void test_median(double input[], int count, double expected)
{
    double actual = median(input, count);

    printf("Testing median\n");
    printf("Expecting %f and got %f: ", expected, actual);

    if (expected == actual) {
        printf("pass.\n");
    }
    else {
        printf("fail.\n");
    }
}


void test_mode(double input[], int in_count, double expected[], int ex_count)
{
    struct m expect = new_m(ex_count, expected);
    struct m actual = mode(input, in_count);

    printf("Testing mode\n");
    printf("Expecting ");
    print_darray(expect.modes, expect.count);

    printf("Actual: ");
    print_darray(actual.modes, actual.count);

    if (!cmp_m(expect, actual)) {
        printf(":fail.\n");
    }
    else {
        printf(":pass.\n");
    }

    return;
}



