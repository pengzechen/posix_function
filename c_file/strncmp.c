#include <stdio.h>

int main() {
    // 定义两个字符串变量
    char string1[] = "Hello";
    char string2[] = "Hello";
    char string3[] = "World";

    // 使用strncmp()函数比较string1和string2的前5个字符
    int result = strncmp(string1, string2, 5);

    // 打印比较结果
    if (result == 0) {
        printf("字符串相同。\n");
    } else if (result < 0) {
        printf("string1 < string2。\n");
    } else {
        printf("string1 > string2。\n");
    }

    // 使用strncmp()函数比较string1和string3的前5个字符
    result = strncmp(string1, string3, 5);

    // 打印比较结果
    if (result == 0) {
        printf("字符串相同。\n");
    } else if (result < 0) {
        printf("string1 < string3。\n");
    } else {
        printf("string1 > string3。\n");
    }

    return 0;
}
