#include "jlibcentral.c"

void test_mean();


int main()
{
    test_mean();
    return 0;
}


void test_mean()
{
    double a[]           = {12.3, 10.6, 14.0, 27.2, 9.0};
    int a_count          = 5;
    double expected_mean = 14.62;
    double actual_mean   = mean(a, a_count);

    printf("Testing mean\n" );
    printf("Expecting %f and got %f: ", expected_mean, actual_mean);

    if (expected_mean == actual_mean) {
        printf("pass.\n");
    }
    else {
        printf("fail.\n");
    }
}

