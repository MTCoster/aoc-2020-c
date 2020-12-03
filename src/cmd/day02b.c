#include "day02.h"
#include "file_utils.h"

#include <stdbool.h>

int main() {
    GET_INPUT(2);

    unsigned int count = 0;
    char const *ptr = in->data;
    prefix_t prefix;

    while (*ptr != '\0') {
        parse_prefix(&prefix, &ptr);

        bool a = *(ptr + prefix.min) == prefix.c;
        bool b = *(ptr + prefix.max) == prefix.c;
        if ((a && !b) || (!a && b)) {
            count++;
        }

        while (*(++ptr) != '\n');
        ptr++;
    }

    printf("%u\n", count);

    free_input(in);
}
