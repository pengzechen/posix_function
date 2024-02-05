#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <utime.h>

int main() {
    // 文件名，这里假设你有一个名为 "example.txt" 的文件
    const char *filename = "example.txt";

    // 获取当前时间，并将其转换为 struct timeval 格式
    time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);
    struct timeval tv;
    tv.tv_sec = mktime(local_time); // 将 struct tm 转换为秒
    tv.tv_usec = 0; // 微秒部分设置为0

    // 设置文件的访问和修改时间为当前时间
    if (utime(filename, &tv) != 0) {
        perror("utime() failed");
        return EXIT_FAILURE;
    }

    printf("The access and modification times of %s have been updated successfully.\n", filename);

    return EXIT_SUCCESS;
}
