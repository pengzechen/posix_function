#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>



int main() {

    char str[] = "12345";

    unsigned long long value = strtoull(str, NULL, 10);


    printf("value: %llu\n", value);

    return 0;

}

