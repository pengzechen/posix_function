#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // 打开一个文件
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open() failed");
        return EXIT_FAILURE;
    }

    // 获取文件描述符 fd 的配置信息
    long config_value = fpathconf(fd, _PC_NAME_MAX);
    if (config_value == -1) {
        perror("fpathconf() failed");
        close(fd); // 关闭文件
        return EXIT_FAILURE;
    }

    // 打印配置信息
    printf("The maximum length of a file name is: %ld\n", config_value);

    // 关闭文件
    if (close(fd) == -1) {
        perror("close() failed");
        return EXIT_FAILURE;
    }

    // 程序正常退出
    return EXIT_SUCCESS;
}
