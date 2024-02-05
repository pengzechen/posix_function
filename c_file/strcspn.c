#include <stdio.h>

int main() {
    // 定义两个字符串变量
    char str[] = "Hello, World!";
    char chars_to_ignore[] = "abc";

    // 使用strcspn()函数计算str中不属于chars_to_ignore的字符串前缀的长度
    int length = strcspn(str, chars_to_ignore);

    // 打印计算出的长度
    printf("长度为：%d\n", length);

    return 0;
}
