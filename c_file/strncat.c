#include <stdio.h>

int main() {
    // 定义两个字符串变量
    char destination[] = "Hello";
    char source[] = ", World!";

    // 使用strncat()函数将source字符串的前5个字符连接到destination字符串的末尾
    strncat(destination, source, 5);

    // 打印连接后的字符串
    printf("连接后的字符串是：%s\n", destination);

    return 0;
}
