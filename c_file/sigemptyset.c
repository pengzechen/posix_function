#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// 信号处理函数
void handle_sigint(int sig) {
    printf("Caught signal %d (SIGINT)\n", sig);
}

int main() {
    // 创建信号集
    sigset_t sigset;

    // 清空信号集
    if (sigemptyset(&sigset) == -1) {
        perror("sigemptyset() failed");
        return EXIT_FAILURE;
    }

    // 注册信号处理函数
    if (signal(SIGINT, handle_sigint) == SIG_ERR) {
        perror("signal() failed");
        return EXIT_FAILURE;
    }

    printf("Press Ctrl+C to catch a signal.\n");

    // 程序将无限期地运行，直到接收到 SIGINT 信号
    while (1) {
        pause(); // 暂停执行，等待信号
    }

    return EXIT_SUCCESS;
}
