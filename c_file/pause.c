#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

volatile sig_atomic_t stop; // 用于存储信号处理函数中的状态

// 信号处理函数
void handle_sigint(int sig) {
    stop = 1; // 设置停止标志
}

int main() {
    // 注册信号处理函数
    signal(SIGINT, handle_sigint);

    printf("Press Ctrl+C to stop the program.\n");

    // 进入一个循环，等待信号
    while (!stop) {
        pause(); // 暂停执行，等待信号
    }

    printf("Program stopped by user.\n");

    return EXIT_SUCCESS;
}
