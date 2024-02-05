#include <stdio.h>
#include <string.h> // 包含string.h以使用memcmp()函数

int main() {
    // 定义两个字符串
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World";

    // 使用memcmp()比较两个字符串
    int result = memcmp(str1, str2, sizeof(str1));

    // 检查比较结果
    if (result == 0) {
        // 如果两个字符串相等，打印消息
        printf("字符串'%s'和'%s'相等。\n", str1, str2);
    } else if (result > 0) {
        // 如果str1大于str2，打印消息
        printf("字符串'%s'大于'%s'。\n", str1, str2);
    } else {
        // 如果str1小于str2，打印消息
        printf("字符串'%s'小于'%s'。\n", str1, str2);
    }

    return 0;
}
