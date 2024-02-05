#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // 指定要打开的目录名称
    const char *directory_name = "demo_directory";

    // 打开目录
    DIR *dir;
    if ((dir = opendir(directory_name)) == NULL) {
        perror("opendir() failed");
        return EXIT_FAILURE;
    }

    // 读取目录内容
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // 打印目录项的名称
        printf("%s\n", entry->d_name);
    }

    // 关闭目录
    if (closedir(dir) == -1) {
        perror("closedir() failed");
        return EXIT_FAILURE;
    }

    // 程序正常退出
    return EXIT_SUCCESS;
}
