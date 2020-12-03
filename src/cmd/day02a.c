#include "day02.h"
#include "file_utils.h"

int main() {
    GET_INPUT(2);

    unsigned int count = 0;
    char const *ptr = in->data;
    prefix_t prefix;

    while (*ptr != '\0') {
        parse_prefix(&prefix, &ptr);
        ptr++;

        unsigned int i = 0;
        for (; *ptr != '\n'; ptr++) {
            if (*ptr == prefix.c) {
                i++;
            }
        }

        ptr++;

        if (i >= prefix.min && i <= prefix.max) {
            count++;
        }
    }

    printf("%u\n", count);

    free_input(in);
}
