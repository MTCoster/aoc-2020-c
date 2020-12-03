#include "day01.h"

#include "file_utils.h"

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

int cmpui(void const *a, void const *b) {
    unsigned int const aa = *(unsigned int const *) a;
    unsigned int const bb = *(unsigned int const *) b;

    return (aa > bb) - (aa < bb);
}

unsigned int const *lines_as_sorted_unsigned_ints(input_t const * const in, size_t const lines) {
    unsigned int *nums = (unsigned int *) malloc(sizeof(unsigned int) * lines);
    assert(nums != NULL);

    unsigned int *num = nums;
    char const *ptr = in->data;
    char *end = (char *) ptr;
    do {
        ptr = end;
        *(num++) = strtoul(ptr, &end, 10);
        assert(errno == 0);
    } while (ptr != end && num != &nums[lines]);

    qsort(nums, lines, sizeof(nums[0]), cmpui);

    return nums;
}

bool find_sum(unsigned int const **lo, unsigned int const **hi, unsigned int const target) {
    unsigned int sum;
    while (*lo < *hi) {
        sum = **lo + **hi;

        if (sum == target) {
            break;
        } else if (sum < target) {
            (*lo)++;
        } else {
            (*hi)--;
        }
    }

    return sum == target;
}
