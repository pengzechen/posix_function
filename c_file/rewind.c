#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    char buffer[11]; // 足够存放 "Hello, World!"
    size_t bytes_read;

    // 打开文件
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // 读取数据
    bytes_read = fread(buffer, 1, sizeof(buffer), file);
    if (bytes_read == 0) {
        perror("Error reading from file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // 打印读取的数据
    printf("Read: %s\n", buffer);

    // 将文件位置指针倒回到文件开头
    rewind(file);

    // 再次读取相同的数据
    bytes_read = fread(buffer, 1, sizeof(buffer), file);
    if (bytes_read == 0) {
        perror("Error reading from file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // 打印再次读取的数据
    printf("Rewound and read: %s\n", buffer);

    // 关闭文件
    fclose(file);

    // 程序正常退出
    return EXIT_SUCCESS;
}
