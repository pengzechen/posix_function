#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int main() {


    char str[] = "3.14159";

    float value = strtof(str, NULL);

    printf("value: %f\n", value);

    return 0;

}

