#include <stdio.h>
#include <string.h>

int main() {
    // 定义两个字符串
    char str1[] = "Hello, World!";
    char str2[] = "World";

    // 使用strstr()函数查找str1中str2第一次出现的位置
    char *found = strstr(str1, str2);

    // 检查是否找到字符串
    if (found != NULL) {
        printf("找到了字符串'%s'，它在字符串'%s'中的位置是：%ld\n", str2, str1, found - str1);
    } else {
        printf("没有找到字符串'%s'。\n", str2);
    }

    return 0;
}
