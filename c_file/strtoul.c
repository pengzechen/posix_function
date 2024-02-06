#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>



int main() {

    char str[] = "12345";

    unsigned long value = strtoul(str, NULL, 10);


    printf("value: %lu\n", value);


    return 0;

}

