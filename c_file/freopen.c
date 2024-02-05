#include <stdio.h>

int main() {
    // 使用 freopen 重定向标准输出到 output.txt 文件
    freopen("output.txt", "w", stdout); // 将 stdout 重定向到 output.txt 文件

    // 现在 stdout 将输出到 output.txt 文件而不是屏幕
    printf("Hello, World! This is a demo of the freopen function.\n");

    // 关闭 output.txt 文件流
    fclose(stdout);

    // 程序正常退出
    return 0;
}
