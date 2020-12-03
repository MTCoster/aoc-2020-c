#include "file_utils.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILENAME_LEN (16)
#define MAX_DAY (25)

input_t const *get_input(unsigned int const day) {
    assert(day > 0);
    assert(day < MAX_DAY);

    char filename[INPUT_FILENAME_LEN];
    snprintf(filename, INPUT_FILENAME_LEN, "input/day%02u.txt", day);

    FILE *fp = fopen(filename, "r");
    assert(fp != NULL);

    assert(fseek(fp, 0l, SEEK_END) == 0);
    long len = ftell(fp);
    rewind(fp);

    char *data = (char *) malloc(len + 1);
    assert(data != NULL);

    assert(fread(data, 1, len, fp) == len);
    data[len] = '\0';

    fclose(fp);

    input_t *in = (input_t *) malloc(sizeof(input_t));
    assert(in != NULL);

    in->data = data;
    in->len = len;

    return in;
}

void free_input(input_t const * const in) {
    free((void *) in->data);
    free((void *) in);
}

size_t count_lines(input_t const * const in) {
    size_t lines = 0;

    for (char const *ptr = in->data; *ptr != '\0'; ptr++) {
        if (*ptr == '\n') {
            lines++;
        }
    }

    return lines;
}
