#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int main() {

    char str[] = "123.456";

    double value = strtod(str, NULL);

    printf("value: %f\n", value);

    return 0;

}

