#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // 使用 open 打开一个文件
    int fd = open("example.txt", O_RDONLY); // "O_RDONLY" 表示只读模式

    if (fd == -1) {
        perror("open failed");
        return 1; // 打开文件失败
    }

    // 文件描述符成功打开，可以进行读取操作
    printf("File opened successfully with file descriptor: %d\n", fd);

    // 关闭文件
    if (close(fd) != 0) {
        perror("close failed");
        return 1; // 关闭文件失败
    }

    printf("File closed successfully.\n");

    // 程序正常退出
    return 0;
}
