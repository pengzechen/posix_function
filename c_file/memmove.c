#include <stdio.h>
#include <string.h> // 包含string.h以使用memmove()函数

int main() {
    // 定义一个字符数组作为源
    char src[] = "Hello, World!";

    // 定义一个字符数组作为目的地，长度足够以容纳src中的字符串
    char dest[20] = "Hello, C!";

    // 使用memmove()复制字符串，即使src和dest有重叠也不会出错
    memmove(dest, src, sizeof(src));

    // 打印复制后的目的地字符串
    printf("复制后的字符串是：%s\n", dest);

    return 0;
}
