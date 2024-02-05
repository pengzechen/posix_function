#include <stdio.h>
#include <string.h> // 包含string.h以使用memcpy()函数

int main() {
    // 定义一个字符数组作为源
    char src[] = "Hello, World!";

    // 定义一个字符数组作为目的地
    char dest[20]; // 确保这个数组足够大以容纳复制的内容

    // 使用memcpy()复制字符串
    memcpy(dest, src, sizeof(src));

    // 打印复制后的目的地字符串
    printf("复制后的字符串是：%s\n", dest);

    return 0;
}
