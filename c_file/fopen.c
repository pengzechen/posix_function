#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    const char *filename = "example.txt";
    const char *mode = "r"; // "r" 表示只读模式

    // 打开文件
    file = fopen(filename, mode);
    if (file == NULL) {
        perror("fopen failed");
        return 1; // 打开文件失败
    }

    // 文件成功打开，可以进行读取、写入或操作
    // ...

    // 关闭文件
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1; // 关闭文件失败
    }

    printf("File operations completed successfully.\n");
    return 0; // 程序正常退出
}
