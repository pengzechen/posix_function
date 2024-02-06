#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>

#include <inttypes.h>


int main() {

    char str[] = "12345";


    unsigned long value = strtoumax(str, NULL, 10);


    printf("ת������޷��ų��������ǣ�%lu\n", value);


    return 0;

}

