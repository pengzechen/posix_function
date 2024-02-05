#include <stdio.h>
#include <string.h>

int main() {
    // 定义两个字符串
    char str1[] = "Hello, World!";
    char str2[] = "Hello";

    // 使用strspn()函数计算str1中最初段的长度，该段由str2中的字符组成
    size_t len = strspn(str1, str2);

    // 打印结果
    printf("strspn() returned: %zu\n", len);

    return 0;
}
