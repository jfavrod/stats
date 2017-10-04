#include "jlibcentral.h"


/**
 * mean
 *
 * Finds the mean of a given numerical dataset.
 *
 * @param double numbers[] Our numerical dataset.
 * @param int count The number of items in the dataset.
 *
 * @return double The mean of the dataset.
 */

double mean(double numbers[], int count)
{
    int    i   = 0;
    double sum = 0.0;

    for (; i < count; i++) {
        sum = sum + numbers[i];
    }

    return sum/count;
}


/**
 * median
 *
 * Finds the median of a given numerical dataset.
 *
 * @param double numbers[] Our numerical dataset.
 * @param int count The number of items in the dataset.
 *
 * @return double The median of the dataset.
 */

double median(double numbers[], int count)
{
    double tmp[2];

    /* Linux: */
    /* qsort(numbers, count, MAX_NUMBERS, ascending); */

    /* Darwin: */
    qsort(numbers, count, sizeof(tmp[0]), ascending);

    if ((count % 2) != 0) {
        int mid = ceil(count/2.0) - 1;
        tmp[0] = numbers[mid];
    }
    else {
        tmp[0] = numbers[count/2];
        tmp[1] = numbers[(count/2)-1];
        tmp[0] = mean(tmp, 2);
    }

    return tmp[0];
}


/**
 * mode
 *
 * Finds the mode of a given numerical dataset.
 *
 * @param double numbers[] Our numerical dataset.
 * @param int count The number of items in the dataset.
 *
 * @return double The mode of the dataset.
 */

struct m mode(double numbers[], int count)
{

    double a[MAX_NUMBERS] = {0};
    int b[MAX_NUMBERS]    = {0};
    struct m mx           = {0, modes};

    /* abc - The count of elements in a and b (a b count). */
    int abc = 0;
    int i   = 0;
    int j   = 0;
    int max = 0;

    for (; i < count; i++) {
        int index = darray_indexof(numbers[i], a, abc);

        if (index == -1) {
            a[abc] = numbers[i];
            b[abc]++;
            abc++;
        }
        else {
            b[index]++;
        }
    }

    for (i = 0; i < abc; i++) {
        max = max_int(b, abc);

        if (b[i] == max) {
            mx.count++;
            mx.modes[j++] = a[i];
        }
    }

    return mx;
}


struct m new_m(int count, double modes[])
{
    struct m tmp;

    tmp.count = count;
    tmp.modes = modes;

    return tmp;
}


int cmp_m (struct m m1, struct m m2) {
    int i;

    if (m1.count != m2.count) {
        return 0;
    }

    qsort(m1.modes, m1.count, sizeof(m1.modes[0]), ascending);
    qsort(m2.modes, m2.count, sizeof(m2.modes[0]), ascending);

    for (i = 0; i < m1.count; i++) {
        if (m1.modes[i] != m2.modes[i]) {
            return 0;
        }
    }

    return 1;
}
