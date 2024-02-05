#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    long pos;
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
    pos = ftell(file);
    if (pos == -1) {
        perror("Error getting file position");
        fclose(file);
        return EXIT_FAILURE;
    }

    // 打印当前文件位置
    printf("Current file position: %ld\n", pos);

    // 关闭文件
    fclose(file);

    // 程序正常退出
    return EXIT_SUCCESS;
}
