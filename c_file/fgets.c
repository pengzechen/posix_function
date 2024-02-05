#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    char buffer[1024];

    // 打开文件
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen failed");
        return 1;
    }

    // 读取文件内容
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // 输出读取的行
        printf("%s", buffer);
    }

    // 检查是否到达文件末尾
    if (feof(file)) {
        printf("Reached end of file.\n");
    }

    // 关闭文件
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1;
    }

    printf("File read successfully.\n");
    return 0;
}
