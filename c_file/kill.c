#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    // ��ȡ��ǰ���� ID
    pid_t pid = getpid();

    // ��ӡ��ǰ���� ID
    printf("The current process ID is: %d\n", (int)pid);

    // ���� SIGINT �źŸ���ǰ����
    if (kill(pid, SIGINT) == -1) {
        perror("kill() failed");
        return EXIT_FAILURE;
    }

    printf("SIGINT signal sent to process ID: %d\n", (int)pid);

    return EXIT_SUCCESS;
}
