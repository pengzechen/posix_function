#include <stdio.h>

int main() {
    // 使用 getc 读取标准输入的一个字符
    int ch;

    printf("Please enter a character: ");
    ch = getc(stdin); // 从 stdin 读取一个字符

    // 打印读取的字符
    printf("You entered: %c\n", ch);

    // 程序正常退出
    return 0;
}
