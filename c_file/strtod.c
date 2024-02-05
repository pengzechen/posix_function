#include <stdio.h>
#include <stdlib.h>

int main() {
    // 定义一个包含数值的字符串
    char str[] = "123.456";

    // 使用strtod()函数将字符串转换为双精度浮点数
    double value = strtod(str, NULL);

    // 打印转换后的值
    printf("转换后的双精度浮点数是：%f\n", value);

    return 0;
}
