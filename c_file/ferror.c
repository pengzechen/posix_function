#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    char buffer[1024];
    size_t bytes_read;

    // 打开文件
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen failed");
        return 1;
    }

    // 初始化错误标志
    clearerr(file);

    // 读取文件内容
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        // 输出读取的数据
        printf("%s", buffer);
    }

    // 检查读取过程中是否出现错误
    if (ferror(file)) {
        perror("ferror detected");
        fclose(file); // 即使有错误，也应关闭文件流
        return 1;
    }

    // 关闭文件
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1;
    }

    printf("File read successfully.\n");
    return 0;
}
