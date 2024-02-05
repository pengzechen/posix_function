#include <stdio.h>

int main() {
    // 分配一个足够大的缓冲区
    char buffer[30];

    // 使用sprintf()向缓冲区中写入格式化的字符串
    sprintf(buffer, "Hello, %s!", "World");

    // 打印缓冲区中的内容
    printf("缓冲区中的内容是：%s\n", buffer);

    return 0;
}
