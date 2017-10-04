#include "jlibvariance.h"


double range(double values[], int count)
{
    double min = min_double(values, count);
    double max = max_double(values, count);

    return max - min;
}


double sample_variance(double values[], int count)
{
    int i = 0;
    double M = mean(values, count);
    double sum = 0.0;
    
    while (i < count) {
        sum = sum + pow((values[i] - M), 2);
        i++;
    }

    return sum/(count-1);
}

