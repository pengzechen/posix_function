#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    // 定义一个包含数值的字符串
    char str[] = "12345";

    // 使用strtoull()函数将字符串转换为无符号长整型数
    unsigned long long value = strtoull(str, NULL, 10);

    // 打印转换后的值
    printf("转换后的无符号长整型数是：%llu\n", value);

    return 0;
}
