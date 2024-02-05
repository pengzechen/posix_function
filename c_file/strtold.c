#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    // 定义一个包含数值的字符串
    char str[] = "12345.6789";

    // 使用strtold()函数将字符串转换为长双精度浮点数
    long double value = strtold(str, NULL);

    // 打印转换后的值
    printf("转换后的长双精度浮点数是：%Lf\n", value);

    return 0;
}
