#include "libvariance.h"


int main()
{
    int i = 0;
    double expected;
    double actual;

    /* Test sample_variance. */

    for (; i < TEST_COUNT; i++) {
        expected = expected_sample_results[i];
        actual = sample_variance(test_sample[i], SAMPLE_SIZE);

        printf("sample_variance test %i\n", i);
        printf("expected: %f, actual: %f\n", expected, actual);

        if (fabs(expected - actual) < 0.00001) {
            printf("**pass**\n");
        }
        else {
            printf("**fail**\n");
        }
    }

    i = 0;
    printf("\n");

    /* Test population_variance. */

    for (; i < TEST_COUNT; i++) {
        expected = expected_population_results[i];
        actual = population_variance(test_population[i], POPULATION_SIZE);

        printf("population_variance test %i\n", i);
        printf("expected: %f, actual: %f\n", expected, actual);

        if (fabs(expected - actual) < 0.00001) {
            printf("**pass**\n");
        }
        else {
            printf("**fail**\n");
        }
    }

    return 0;
}


