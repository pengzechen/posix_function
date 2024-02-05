#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    char buffer[1024];
    size_t bytes_written;

    // 打开文件
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("fopen failed");
        return 1;
    }

    // 写入文件内容
    snprintf(buffer, sizeof(buffer), "Hello, World!");
    bytes_written = fputs(buffer, file);
    if (bytes_written == -1) {
        perror("fputs failed");
        fclose(file); // 关闭文件流
        return 1;
    }

    // 刷新输出流，确保数据被写入文件
    fflush(file);

    // 写入更多文件内容
    snprintf(buffer, sizeof(buffer), "This is another line.");
    bytes_written = fputs(buffer, file);
    if (bytes_written == -1) {
        perror("fputs failed");
        fclose(file); // 关闭文件流
        return 1;
    }

    // 再次刷新输出流，确保所有数据被写入文件
    fflush(file);

    // 关闭文件
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1;
    }

    printf("Data written to %s successfully.\n", filename);
    return 0;
}
