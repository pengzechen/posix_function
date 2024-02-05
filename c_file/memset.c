#include <stdio.h>
#include <string.h> // 包含string.h以使用memset()函数

int main() {
    // 定义一个字符数组
    char buffer[20];

    // 使用memset()将整个内存块设置为0（即'\0'）
    memset(buffer, 0, sizeof(buffer));

    // 打印设置后的内存块内容
    printf("设置后的内存块内容是：%s\n", buffer);

    return 0;
}
