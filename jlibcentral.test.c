#include "jlibcentral.c"
#define TEST_COUNT 2

void test_mean(double input[], int count, double expected);
void test_median(double input[], int count, double expected);


double test_set[TEST_COUNT][MAX_NUMBERS] = {
    {12.3, 10.6, 14.0, 27.2, 9.0},
    {1, 2, 4, 7, 7, 10, 2, 4, 5, 22}
};

int count[TEST_COUNT] = {5, 10};

double mean_expected[TEST_COUNT]   = { 14.62, 6.4 };
double median_expected[TEST_COUNT] = { 12.3, 4.5 };


int main()
{
    int i;

    for (i = 0; i < TEST_COUNT; i++) {
        printf("\n");
        test_mean(test_set[i], count[i], mean_expected[i]);
        test_median(test_set[i], count[i], median_expected[i]);
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

