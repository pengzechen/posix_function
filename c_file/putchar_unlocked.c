#include <stdio.h>

int main() {
    // 打印字符到标准输出
    for (char character = 'A'; character <= 'Z'; ++character) {
        putchar_unlocked(character);
    }

    // 打印换行符
    putchar_unlocked('\n');

    // 程序正常退出
    return 0;
}
