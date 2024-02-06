#include <stdio.h>

#include <stdlib.h> 

int main() {

    long long int numerator = 1234567890123456789LL;

    long long int denominator = 12345;

    lldiv_t result;

    result = lldiv(numerator, denominator);

    printf("���� %lld�������� %lld��\n", result.quot, result.rem);


    return 0;

}

