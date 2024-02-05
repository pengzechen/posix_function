#include <stdio.h>

int main() {
    // 定义两个字符串变量
    char str1[] = "Hello";
    char str2[] = "World";
    char str3[] = "Hello";

    // 使用strcmp()函数比较str1和str2
    int result = strcmp(str1, str2);

    // 检查比较结果
    if (result < 0) {
        // str1小于str2
        printf("str1 < str2\n");
    } else if (result > 0) {
        // str1大于str2
        printf("str1 > str2\n");
    } else {
        // str1等于str2
        printf("str1 == str2\n");
    }

    // 使用strcmp()函数比较str1和str3
    result = strcmp(str1, str3);

    // 检查比较结果
    if (result < 0) {
        // str1小于str3
        printf("str1 < str3\n");
    } else if (result > 0) {
        // str1大于str3
        printf("str1 > str3\n");
    } else {
        // str1等于str3
        printf("str1 == str3\n");
    }

    return 0;
}
