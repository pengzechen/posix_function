#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    // �����źż�
    sigset_t sigset;

    // ����źż�
    if (sigemptyset(&sigset) == -1) {
        perror("sigemptyset() failed");
        return EXIT_FAILURE;
    }

    // �� SIGINT �ź���ӵ��źż���
    if (sigaddset(&sigset, SIGINT) == -1) {
        perror("sigaddset() failed");
        return EXIT_FAILURE;
    }

    // ʹ�� sigismember() ��� SIGINT �Ƿ����źż���
    if (sigismember(&sigset, SIGINT)) {
        printf("SIGINT is in the signal set.\n");
    } else {
        printf("SIGINT is not in the signal set.\n");
    }

    return EXIT_SUCCESS;
}
