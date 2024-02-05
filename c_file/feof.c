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

    // 读取文件内容直到文件末尾
    while (!feof(file)) {
        bytes_read = fread(buffer, 1, sizeof(buffer), file);
        if (bytes_read == 0) {
            break; // 如果读取零字节，可能是文件末尾
        }
        // 输出读取的数据
        printf("%s", buffer);
    }

    // 关闭文件
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1;
    }

    printf("File read successfully.\n");
    return 0;
}
