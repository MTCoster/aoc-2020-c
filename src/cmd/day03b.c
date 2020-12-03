#include "day03.h"
#include "file_utils.h"

int main() {
    GET_INPUT(3);

    size_t const height = count_lines(in);
    size_t width = 0;

    for (char const *ptr = in->data; *ptr != '\n'; ptr++) {
        width++;
    }

    unsigned int const steps[] = {
            1, 1,
            3, 1,
            5, 1,
            7, 1,
            1, 2,
            0
    };

    unsigned int product = 1;
    for (unsigned int const *ptr = steps; *ptr != 0; ptr += 2) {
        product *= count_trees(in->data, width, height, ptr[0], ptr[1]);
    }

    printf("%u\n", product);

    free_input(in);
}
