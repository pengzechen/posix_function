#include <stdio.h>

#include <stdlib.h> 



int main() {

    char str[] = "123.456"; 

    double value;

    value = atof(str);

    printf("value: %f\n", value);

    return 0;
}

