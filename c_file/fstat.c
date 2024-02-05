#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    // 打开一个文件
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open() failed");
        return EXIT_FAILURE;
    }

    // 获取文件描述符 fd 的状态信息
    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        perror("fstat() failed");
        close(fd); // 关闭文件
        return EXIT_FAILURE;
    }

    // 打印状态信息
    printf("File size: %ld bytes\n", file_stat.st_size);
    printf("File type: %d\n", file_stat.st_mode);
    printf("Number of hard links: %d\n", file_stat.st_nlink);
    printf("Owner ID: %d\n", file_stat.st_uid);
    printf("Group ID: %d\n", file_stat.st_gid);
    printf("Last access time: %ld seconds since the Epoch\n", file_stat.st_atime);
    printf("Last modification time: %ld seconds since the Epoch\n", file_stat.st_mtime);
    printf("Last status change time: %ld seconds since the Epoch\n", file_stat.st_ctime);

    // 关闭文件
    if (close(fd) == -1) {
        perror("close() failed");
        return EXIT_FAILURE;
    }

    // 程序正常退出
    return EXIT_SUCCESS;
}
