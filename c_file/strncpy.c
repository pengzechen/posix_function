#include <stdio.h>

int main() {
    // 定义两个字符串变量
    char destination[] = "Hello";
    char source[] = "Hello, World!";

    // 使用strncpy()函数将source字符串复制到destination字符串中，不超过5个字符
    strncpy(destination, source, 5);

    // 打印复制后的字符串
    printf("复制后的字符串是：%s\n", destination);

    return 0;
}
