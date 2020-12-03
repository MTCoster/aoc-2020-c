#include "day03.h"

unsigned int count_trees(char const * const data, size_t const width, size_t const height, size_t const x_step, size_t const y_step) {
    unsigned int count = 0;

    size_t x = 0;
    for (size_t y = 0; y < height; y += y_step) {
        count += data[(y * (width + 1)) + x] & 0x01;
        x = (x + x_step) % width;
    }

    return count;
}