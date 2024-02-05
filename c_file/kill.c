#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    // 获取当前进程 ID
    pid_t pid = getpid();

    // 打印当前进程 ID
    printf("The current process ID is: %d\n", (int)pid);

    // 发送 SIGINT 信号给当前进程
    if (kill(pid, SIGINT) == -1) {
        perror("kill() failed");
        return EXIT_FAILURE;
    }

    printf("SIGINT signal sent to process ID: %d\n", (int)pid);

    return EXIT_SUCCESS;
}
