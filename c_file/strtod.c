#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int main() {

    char str[] = "123.456";

    double value = strtod(str, NULL);

    printf("ת�����˫���ȸ������ǣ�%f\n", value);

    return 0;

}

