#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    fpos_t position;
    int result;

    // 打开文件
    file = fopen(filename, "r+");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // 获取当前文件位置
    result = fgetpos(file, &position);
    if (result == -1) {
        perror("Error getting file position");
        fclose(file);
        return EXIT_FAILURE;
    }
    printf("Current file position: %ld\n", position);

    // 移动文件指针到文件开头
    result = fseek(file, 0, SEEK_SET);
    if (result == -1) {
        perror("Error seeking to file beginning");
        fclose(file);
        return EXIT_FAILURE;
    }

    // 再次获取文件位置
    result = fgetpos(file, &position);
    if (result == -1) {
        perror("Error getting file position");
        fclose(file);
        return EXIT_FAILURE;
    }
    printf("New file position after seeking: %ld\n", position);

    // 关闭文件
    fclose(file);

    // 程序正常退出
    return EXIT_SUCCESS;
}
