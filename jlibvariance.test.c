#include "jlibvariance.c"

int main()
{
    double d[] = { 600.0, 470.0, 170.0, 430.0, 300.0 };
    printf("The range is %f\n", range(d, 5));
    printf("The sample variance is %f\n", sample_variance(d, 5));
    return 0;
}


