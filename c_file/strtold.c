#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>



int main() {

    char str[] = "12345.6789";

    long double value = strtold(str, NULL);

    printf("ת����ĳ�˫���ȸ������ǣ�%Lf\n", value);

    return 0;

}

