#include <stdio.h>

#include <stdlib.h> 

int main() {

    char str[] = "123.456";

    double value;

    value = atof(str);

    printf("转换后的浮点数： %f\n", value);

    return 0;
}

