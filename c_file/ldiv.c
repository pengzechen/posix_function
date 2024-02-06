#include <stdio.h>

#include <stdlib.h> 


int main() {


    long int numerator = 1234567890;

    long int denominator = 12345;


    ldiv_t result;

    result = ldiv(numerator, denominator);

    printf("���� %ld�������� %ld��\n", result.quot, result.rem);


    return 0;

}

