#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    const char *filename = "example.txt";
    int fd;
    ssize_t bytes_written;
    char *data = "Hello, World!";
    off_t new_size;

    // 打开文件，如果不存在则创建
    fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // 写入数据
    bytes_written = write(fd, data, strlen(data));
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd);
        return EXIT_FAILURE;
    }

    // 获取文件大小
    new_size = lseek(fd, 0, SEEK_END);
    if (new_size == -1) {
        perror("Error seeking file");
        close(fd);
        return EXIT_FAILURE;
    }

    // 打印原始文件大小
    printf("Original file size: %ld bytes\n", new_size);

    // 截断文件到新大小
    new_size = 10; // 截断文件到10字节
    if (ftruncate(fd, new_size) == -1) {
        perror("Error truncating file");
        close(fd);
        return EXIT_FAILURE;
    }

    // 再次获取文件大小
    new_size = lseek(fd, 0, SEEK_END);
    if (new_size == -1) {
        perror("Error seeking file");
        close(fd);
        return EXIT_FAILURE;
    }

    // 打印新的文件大小
    printf("New file size: %ld bytes\n", new_size);

    // 关闭文件
    close(fd);

    // 程序正常退出
    return EXIT_SUCCESS;
}
