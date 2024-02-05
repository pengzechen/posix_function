#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    // 定义一个包含数值的字符串
    char str[] = "12345";

    // 使用strtoll()函数将字符串转换为长整型数
    long long value = strtoll(str, NULL, 10);

    // 打印转换后的值
    printf("转换后的长整型数是：%lld\n", value);

    return 0;
}
