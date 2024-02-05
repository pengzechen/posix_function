#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    // 创建信号集
    sigset_t sigset;

    // 清空信号集
    if (sigemptyset(&sigset) == -1) {
        perror("sigemptyset() failed");
        return EXIT_FAILURE;
    }

    // 将 SIGINT 信号添加到信号集中
    if (sigaddset(&sigset, SIGINT) == -1) {
        perror("sigaddset() failed");
        return EXIT_FAILURE;
    }

    // 使用 sigismember() 检查 SIGINT 是否在信号集中
    if (sigismember(&sigset, SIGINT)) {
        printf("SIGINT is in the signal set.\n");
    } else {
        printf("SIGINT is not in the signal set.\n");
    }

    return EXIT_SUCCESS;
}
