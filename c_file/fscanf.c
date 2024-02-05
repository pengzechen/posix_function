#include <stdio.h>

int main() {
    int num;
    FILE *file;
    const char *filename = "input.txt";

    // 打开文件
    file = fopen(filename, "r"); // "r" 表示只读模式
    if (file == NULL) {
        perror("fopen failed");
        return 1; // 打开文件失败
    }

    // 从文件中读取整数
    while (fscanf(file, "%d", &num) == 1) {
        printf("Read integer: %d\n", num);
    }

    // 关闭文件
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1; // 关闭文件失败
    }

    printf("Reading from file completed successfully.\n");
    return 0; // 程序正常退出
}
