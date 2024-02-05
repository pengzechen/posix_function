#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    const char *filename = "example.txt";
    char *data = "Hello, World!";

    // 打开文件
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("fopen failed");
        return 1;
    }

    // 写入数据到文件
    if (fputs(data, file) == EOF) {
        perror("fputs failed");
        fclose(file); // 即使写入失败，也应关闭文件流
        return 1;
    }

    // 关闭文件流
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1;
    }

    printf("Data written to %s successfully.\n", filename);
    return 0;
}
