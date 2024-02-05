#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    const char *filename = "example.txt";
    int fd;

    // 打开文件
    fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // 尝试锁定文件描述符
    if (ftrylockfile(fd) == 0) {
        // 锁定成功，可以安全地进行写操作
        printf("File is locked. Writing to file...\n");
        // 写入数据到文件
        // ...
    } else {
        // 文件已经被锁定
        printf("File is already locked. Exiting program.\n");
    }

    // 关闭文件描述符
    if (close(fd) == -1) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    // 程序正常退出
    return EXIT_SUCCESS;
}
