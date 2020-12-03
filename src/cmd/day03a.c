#include "day03.h"
#include "file_utils.h"

int main() {
    GET_INPUT(3);

    size_t const height = count_lines(in);
    size_t width = 0;

    for (char const *ptr = in->data; *ptr != '\n'; ptr++) {
        width++;
    }

    unsigned int const count = count_trees(in->data, width, height, 3, 1);

    printf("%u\n", count);

    free_input(in);
}
