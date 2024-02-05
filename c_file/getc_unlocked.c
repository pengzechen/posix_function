#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    int character;

    // 打开文件
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // 读取文件直到遇到文件结束符
    while ((character = getc_unlocked(file)) != EOF) {
        // 打印读取的字符
        putchar(character);
    }

    // 如果文件正常关闭失败，打印错误信息
    if (fclose(file) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    // 程序正常退出
    return EXIT_SUCCESS;
}
