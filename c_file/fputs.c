#include <stdio.h>

int main() {
    // 使用 fputs 打印字符串到标准输出
    const char *message = "Hello, World! This is a demo of the fputs function.\n";
    fputs(message, stdout); // 将字符串写入 stdout（标准输出）

    // 程序正常退出
    return 0;
}
