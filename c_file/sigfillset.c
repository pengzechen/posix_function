#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// 信号处理函数
void handle_signal(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    // 创建信号集
    sigset_t sigset;

    // 将所有信号添加到信号集中
    if (sigfillset(&sigset) == -1) {
        perror("sigfillset() failed");
        return EXIT_FAILURE;
    }

    // 设置信号处理函数
    if (sigprocmask(SIG_SETMASK, &sigset, NULL) == -1) {
        perror("sigprocmask() failed");
        return EXIT_FAILURE;
    }

    printf("Press any signal to catch it.\n");

    // 注册信号处理函数
    if (signal(SIGINT, handle_signal) == SIG_ERR) {
        perror("signal() failed");
        return EXIT_FAILURE;
    }

    // 注册信号处理函数
    if (signal(SIGTERM, handle_signal) == SIG_ERR) {
        perror("signal() failed");
        return EXIT_FAILURE;
    }

    // 注册信号处理函数
    if (signal(SIGQUIT, handle_signal) == SIG_ERR) {
        perror("signal() failed");
        return EXIT_FAILURE;
    }

    // 程序将无限期地运行，直到接收到信号
    while (1) {
        pause(); // 暂停执行，等待信号
    }

    return EXIT_SUCCESS;
}
