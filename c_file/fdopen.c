#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *filename = "example.txt";
    int fd;
    FILE *file;
    char *data = "Hello, World!";
    ssize_t bytes_written;

    // 创建一个新文件或打开现有文件
    fd = open(filename, O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    // 将文件描述符转换为文件流
    file = fdopen(fd, "w");
    if (file == NULL) {
        perror("fdopen failed");
        close(fd); // 关闭文件描述符
        return 1;
    }

    // 使用文件流写入数据
    bytes_written = fputs(data, file);
    if (bytes_written == -1) {
        perror("fputs failed");
        fclose(file); // 关闭文件流
        return 1;
    }

    // 关闭文件流
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1;
    }

    // 关闭文件描述符
    if (close(fd) == -1) {
        perror("close failed");
        return 1;
    }

    printf("Data written to %s successfully.\n", filename);
    return 0;
}
