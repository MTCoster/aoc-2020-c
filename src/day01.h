#ifndef AOC_2020_C_DAY01_H
#define AOC_2020_C_DAY01_H

#include "file_utils.h"

#include <stdbool.h>

#define TARGET_SUM (2020)

int cmpui(void const *a, void const *b);
unsigned int const *lines_as_sorted_unsigned_ints(input_t const *in, size_t lines);
bool find_sum(unsigned int const **lo, unsigned int const **hi, unsigned int target);

#endif  // AOC_2020_C_DAY01_H
