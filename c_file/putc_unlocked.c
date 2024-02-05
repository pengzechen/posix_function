#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    int character;

    // 打开文件
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // 写入字符到文件
    for (character = 'A'; character <= 'Z'; ++character) {
        putc_unlocked(character, file);
    }

    // 写入文件结束符
    putc_unlocked('\n', file);

    // 如果文件正常关闭失败，打印错误信息
    if (fclose(file) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    // 程序正常退出
    return EXIT_SUCCESS;
}
