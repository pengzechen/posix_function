#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>



int main() {

    char str[] = "12345";

    long long value = strtoll(str, NULL, 10);

    printf("ת����ĳ��������ǣ�%lld\n", value);

    return 0;

}

