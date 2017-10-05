#include "inc/central.h"


int main(int argc, char *argv[])
{
    double numbers[MAX_NUMBERS] = {0.0};
    int    count                = 0;

    if (argc != 3 || !validateCSV(argv[2])) {
        usage();
    }
    else {
        translateCSV(argv[2], numbers, &count);
        if (strcmp(argv[1], "mean") == 0) {
            printf("The mean is: %f\n", mean(numbers, count));
        }
        else if (strcmp(argv[1], "median") == 0) {
            printf("The median is: %f\n", median(numbers, count));
        }
        else if (strcmp(argv[1], "mode") == 0) {
            struct m my = mode(numbers, count);
            printf("The mode is: ");
            print_darray(my.modes, my.count);
        }
        else {
            usage();
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

