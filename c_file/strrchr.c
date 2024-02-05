#include <stdio.h>

int main() {
    // 定义一个字符串
    char string[] = "Hello, World!";

    // 使用strrchr()函数查找字符串中最后一个出现的字符'a'
    char *found = strrchr(string, 'a');

    // 检查是否找到字符
    if (found != NULL) {
        printf("找到了字符'%c'，它在字符串中的位置是：%d\n", *found, found - string);
    } else {
        printf("没有找到字符'a'。\n");
    }

    return 0;
}
