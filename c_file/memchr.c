#include <stdio.h>
#include <string.h> // 包含string.h以使用memchr()函数

int main() {
    // 定义一个字符数组
    char str[] = "Hello, World!";

    // 要查找的字符
    char to_find = 'W';

    // 使用memchr()查找字符'W'
    char *found = memchr(str, to_find, sizeof(str) - 1); // 注意排除数组的最后一个元素

    // 检查是否找到字符
    if (found != NULL) {
        // 打印找到字符的地址
        printf("字符'%c'在数组中的地址是：%p\n", to_find, found);
    } else {
        // 如果没有找到字符，打印消息
        printf("字符'%c'未在数组中找到。\n", to_find);
    }

    return 0;
}
