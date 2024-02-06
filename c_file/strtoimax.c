#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>

#include <string.h>

#include <inttypes.h>

int main() {

    char str[] = "2147483647";

    intmax_t value = strtoimax(str, NULL, 10);

    printf("value: %jd\n", value);

    return 0;
}

