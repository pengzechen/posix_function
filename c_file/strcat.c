#include <stdio.h>

int main() {
    // 定义两个字符串变量
    char str1[] = "Hello, ";
    char str2[] = "World!";

    // 使用strcat()函数将str2连接到str1后面
    strcat(str1, str2);

    // 打印连接后的字符串
    printf("%s\n", str1);

    return 0;
}
