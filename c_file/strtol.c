#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>



int main() {


    char str[] = "12345";

    long value = strtol(str, NULL, 10);

    printf("ת����ĳ��������ǣ�%ld\n", value);

    return 0;

}

