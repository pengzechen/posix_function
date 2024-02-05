#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // 获取当前工作目录
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() failed");
        return EXIT_FAILURE;
    }

    // 打印当前工作目录
    printf("Current working directory is: %s\n", cwd);

    // 程序正常退出
    return EXIT_SUCCESS;
}
