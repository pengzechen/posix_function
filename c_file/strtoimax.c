#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    // 定义一个包含数值的字符串
    char str[] = "2147483647"; // 这是一个 INT_MAX 的值

    // 使用strtoimax()函数将字符串转换为intmax_t类型的最大整数
    intmax_t value = strtoimax(str, NULL, 10);

    // 打印转换后的值
    printf("转换后的intmax_t类型整数是：%jd\n", value);

    return 0;
}
