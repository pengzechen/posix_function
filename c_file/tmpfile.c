#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // 使用 tmpfile() 创建一个临时文件
    FILE *file = tmpfile();
    if (file == NULL) {
        perror("tmpfile() failed");
        return EXIT_FAILURE;
    }

    // 写入一些文本到临时文件
    const char *text = "Hello, World!\n";
    if (fputs(text, file) == EOF) {
        perror("fputs() failed to write to the file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // 重定位临时文件指针到文件开头
    if (fseek(file, 0, SEEK_SET) != 0) {
        perror("fseek() failed to rewind the file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // 读取并打印文件内容
    char buffer[256];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    // 关闭临时文件
    if (fclose(file) != 0) {
        perror("fclose() failed to close the file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
