#include <stdio.h>
#include <stdlib.h>

int main() {
    // 定义一个包含数值的字符串
    char str[] = "3.14159";

    // 使用strtof()函数将字符串转换为单精度浮点数
    float value = strtof(str, NULL);

    // 打印转换后的值
    printf("转换后的单精度浮点数是：%f\n", value);

    return 0;
}
