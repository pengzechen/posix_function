#include <stdio.h>

int main() {
    // 定义一个字符串
    char str[] = "Hello, World!";

    // 要查找的字符
    char to_find = 'o';

    // 使用strchr()函数查找to_find字符在str字符串中第一次出现的位置
    char *found = strchr(str, to_find);

    // 检查是否找到了字符
    if (found != NULL) {
        // 打印找到的字符及其位置
        printf("字符'%c'在字符串中的位置是：%d\n", to_find, found - str);
    } else {
        // 如果没有找到字符，打印消息
        printf("字符'%c'在字符串中没有找到。\n", to_find);
    }

    return 0;
}
