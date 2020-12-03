#include "day01.h"
#include "file_utils.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    GET_INPUT(1);

    size_t const lines = count_lines(in);
    unsigned int const *nums = lines_as_sorted_unsigned_ints(in, lines);

    unsigned int const *lo = &nums[0];
    unsigned int const *hi = &nums[lines - 1];
    assert(find_sum(&lo, &hi, TARGET_SUM));

    printf("%u\n", (*lo) * (*hi));

    free((void *) nums);
    free_input(in);
}
