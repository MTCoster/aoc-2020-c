#include "day02.h"

#include <assert.h>
#include <errno.h>
#include <stdlib.h>

void parse_prefix(prefix_t *const out, char const **ptr) {
    char *end;

    out->min = strtoul(*ptr, &end, 10);
    assert(errno == 0);
    *ptr = end + 1;

    out->max = strtoul(*ptr, &end, 10);
    assert(errno == 0);
    *ptr = end + 1;

    out->c = **ptr;
    *ptr += 2;
}
