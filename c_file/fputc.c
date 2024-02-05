#include <stdio.h>

int main() {
    // 使用 fputc 打印字符到标准输出
    char ch = 'A'; // 定义一个字符变量并初始化为 'A'
    fputc(ch, stdout); // 将字符 'A' 写入 stdout（标准输出）

    // 程序正常退出
    return 0;
}
