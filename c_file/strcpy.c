#include <stdio.h>

int main() {
    // 定义两个字符串变量
    char source[] = "Hello, World!";
    char destination[20]; // 确保destination足够大以存储source字符串

    // 使用strcpy()函数将source字符串复制到destination字符串中
    strcpy(destination, source);

    // 打印复制后的destination字符串
    printf("%s\n", destination);

    return 0;
}
