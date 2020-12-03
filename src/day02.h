#ifndef AOC_2020_C_DAY02_H
#define AOC_2020_C_DAY02_H

#include <stddef.h>

typedef struct prefix {
    size_t min;
    size_t max;
    char c;
} prefix_t;

void parse_prefix(prefix_t *out, char const **ptr);

#endif  // AOC_2020_C_DAY02_H
