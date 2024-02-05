#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // 指定要创建的目录名称
    const char *directory_name = "demo_directory";

    // 使用 mkdir() 函数创建目录
    if (mkdir(directory_name, 0755) == 0) {
        // 目录创建成功
        printf("Directory '%s' created successfully.\n", directory_name);
    } else {
        // 目录创建失败
        perror("mkdir() failed");
    }

    // 程序正常退出
    return EXIT_SUCCESS;
}
