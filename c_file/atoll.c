#include <stdio.h>

#include <stdlib.h> 


int main() {

    char str[] = "1234"; 
    long long value;

    value = atoll(str);

    printf("value: %lld\n", value);

    return 0;
}

