#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    const char *filename = "example.txt";
    int fd;
    int flags;
    ssize_t bytesRead;
    char buffer[1024];

    // 打开文件
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // 设置文件描述符为非阻塞模式
    flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) {
        perror("Error getting file flags");
        close(fd);
        return EXIT_FAILURE;
    }
    flags |= O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flags) == -1) {
        perror("Error setting file flags");
        close(fd);
        return EXIT_FAILURE;
    }

    // 循环读取数据直到文件结束
    while (1) {
        // 尝试读取数据
        bytesRead = read(fd, buffer, sizeof(buffer) - 1);
        if (bytesRead == -1) {
            // 检查是否是因为非阻塞模式而导致的EAGAIN错误
            if (errno != EAGAIN) {
                perror("Error reading file");
                break;
            }
        } else {
            // 移除字符串末尾的换行符（如果有的话）
            buffer[bytesRead] = '\0';
            printf("Read: %s\n", buffer);
        }

        // 这里可以添加睡眠或其他等待机制来避免繁忙等待
        // usleep(10000); // 等待10000微秒（10毫秒）
    }

    // 关闭文件描述符
    close(fd);

    // 程序正常退出
    return EXIT_SUCCESS;
}
