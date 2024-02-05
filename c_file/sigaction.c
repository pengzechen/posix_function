#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// 信号处理函数
void handle_sigint(int sig) {
    printf("Caught signal %d (SIGINT)\n", sig);
}

int main() {
    // 创建信号处理结构体
    struct sigaction sa;
    
    // 初始化信号处理结构体
    memset(&sa, 0, sizeof(sa));
    
    // 设置信号处理函数
    sa.sa_handler = handle_sigint;
    
    // 设置 SA_RESTART 标志，以便被信号中断的系统调用可以重启
    sa.sa_flags = SA_RESTART;
    
    // 注册信号处理函数
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction() failed");
        return EXIT_FAILURE;
    }

    printf("Press Ctrl+C to catch a signal.\n");

    // 程序将无限期地运行，直到接收到 SIGINT 信号
    while (1) {
        pause(); // 暂停执行，等待信号
    }

    return EXIT_SUCCESS;
}
