#ifndef AOC_2020_C_FILE_UTILS_H
#define AOC_2020_C_FILE_UTILS_H

#include <stdio.h>

#define GET_INPUT(day) input_t const *in = get_input(day)

typedef struct input {
    char const *data;
    size_t len;
} input_t;

input_t const *get_input(unsigned int day);
void free_input(input_t const *in);

size_t count_lines(input_t const *in);

#endif  // AOC_2020_C_FILE_UTILS_H
