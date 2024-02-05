#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h> // 用于定义 uintmax_t

int main() {
    const char *filename = "example.txt";
    FILE *file;
    off_t pos;
    char *data = "Hello, World!";

    // 打开文件
    file = fopen(filename, "w+");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // 写入数据
    fputs(data, file);

    // 获取当前文件位置
    pos = ftello(file);
    if (pos == -1) {
        perror("Error getting file position");
        fclose(file);
        return EXIT_FAILURE;
    }

    // 打印当前文件位置
    printf("Current file position: %ju\n", (uintmax_t)pos);

    // 关闭文件
    fclose(file);

    // 程序正常退出
    return EXIT_SUCCESS;
}
