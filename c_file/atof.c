#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用atof()函数

int main() {
    char str[] = "123.456"; // 定义一个包含数字的字符串
    double value;

    // 使用atof()函数将字符串转换为浮点数
    value = atof(str);

    printf("转换后的浮点数： %f\n", value);

    return 0;
}
