#include "variance.h"


int main(int argc, char *argv[])
{
    double numbers[MAX_NUMBERS] = {0.0};
    int    count                = 0;

    if (argc != 3 || !validateCSV(argv[2])) {
        usage();
    }
    else {
        translateCSV(argv[2], numbers, &count);
        if (strcmp(argv[1], "sampvar") == 0) {
            printf("The sample variance is %f\n", sample_variance(numbers, count));
        }
        else if (strcmp(argv[1], "sstddev") == 0) {
            printf("The sample standard deviatation is %f\n", sample_std_deviation(numbers, count));
        }
        else if (strcmp(argv[1], "popvar") == 0) {
            printf("The population variance is %f\n", population_variance(numbers, count));
        }
        else if (strcmp(argv[1], "pstddev") == 0) {
            printf("The population standard deviatation is %f\n", population_std_deviation(numbers, count));
        }
        else {
            usage();
        }
    }

    return 0;
}


void usage()
{
    printf("variance: determine the variability in a series of values.\n");
    printf("usage:\n");
    printf("calculate sample variance\n");
    printf("sampvar [list of numbers]\n");
    printf("\n");
    printf("calculate sample standard deviation\n");
    printf("sstddev [list of numbers]\n");
    printf("\n");
    printf("calculate population variance\n");
    printf("popvar [list of numbers]\n");
    printf("\n");
    printf("calculate population standard deviation\n");
    printf("pstddev [list of numbers]\n");
    printf("\n");
    printf("(list is CSV with no spaces)\n");
}
