#include <stdio.h>

#include <stdlib.h> 

int main() {

    char str[] = "1234"; 
    long value;

    value = atol(str);

    printf("value: %ld\n", value);

    return 0;
}

