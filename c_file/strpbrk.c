#include <stdio.h>

int main() {
    // 定义一个字符串
    char string[] = "Hello, World!";

    // 定义一个字符集合
    char chars[] = "abc";

    // 使用strpbrk()函数查找字符串中字符集合的第一个字符
    char *found = strpbrk(string, chars);

    // 检查是否找到字符
    if (found != NULL) {
        printf("找到了字符集合中的第一个字符：'%c'\n", *found);
    } else {
        printf("没有找到字符集合中的任何字符。\n");
    }

    return 0;
}
