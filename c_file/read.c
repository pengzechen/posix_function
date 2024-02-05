#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // 定义一个字符数组来存储用户输入的字符串
    char buffer[100];

    // 使用 read 读取标准输入的字符串
    ssize_t bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1); // 留一个位置给 '\0'

    if (bytesRead == -1) {
        perror("read failed");
        exit(EXIT_FAILURE); // 读取失败
    }

    // 确保字符串以 null 字符结尾
    buffer[bytesRead] = '\0';

    // 打印用户输入的字符串
    printf("You entered: %s\n", buffer);

    // 程序正常退出
    return 0;
}
