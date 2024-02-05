#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    long fileSize;
    char *data = "Hello, World!";
    size_t bytesWritten, bytesRead;

    // 打开文件
    file = fopen(filename, "w+");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // 获取文件大小
    fileSize = lseek(fileno(file), 0, SEEK_END);
    printf("Initial file size: %ld\n", fileSize);

    // 将文件指针移动到文件末尾
    if (ftruncate(fileno(file), fileSize + strlen(data) + 1) == -1) {
        perror("Error truncating file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // 写入数据
    bytesWritten = fwrite(data, 1, strlen(data) + 1, file);
    if (bytesWritten != strlen(data) + 1) {
        perror("Error writing to file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // 将文件指针移动回文件开头
    if (fseek(file, 0, SEEK_SET) == -1) {
        perror("Error seeking to file beginning");
        fclose(file);
        return EXIT_FAILURE;
    }

    // 读取数据
    bytesRead = fread(data, 1, strlen(data) + 1, file);
    if (bytesRead != strlen(data) + 1) {
        perror("Error reading from file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // 打印读取的数据
    printf("Read data: %s\n", data);

    // 关闭文件
    fclose(file);

    // 程序正常退出
    return EXIT_SUCCESS;
}
