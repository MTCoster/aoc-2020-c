#include "day01.h"
#include "file_utils.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    GET_INPUT(1);

    size_t const lines = count_lines(in);
    unsigned int const *nums = lines_as_sorted_unsigned_ints(in, lines);

    unsigned int const *ptr;
    unsigned int const *lo;
    unsigned int const *hi;
    for (ptr = nums; ptr < &nums[lines]; ptr++) {
        lo = ptr;
        hi = &nums[lines - 1];

        if (find_sum(&lo, &hi, TARGET_SUM - *ptr)) {
            break;
        }
    }

    assert(*ptr + *lo + *hi == TARGET_SUM);

    printf("%u\n", (*ptr) * (*lo) * (*hi));

    free((void *) nums);
    free_input(in);
}
