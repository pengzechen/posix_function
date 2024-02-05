#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    int file_descriptor;

    // 打开文件
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen failed");
        return 1;
    }

    // 获取文件的文件描述符
    file_descriptor = fileno(file);
    if (file_descriptor == -1) {
        perror("fileno failed");
        fclose(file); // 关闭文件流
        return 1;
    }

    // 打印文件描述符
    printf("File descriptor: %d\n", file_descriptor);

    // 关闭文件
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1;
    }

    printf("File operations completed successfully.\n");
    return 0;
}
