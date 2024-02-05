#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// �źŴ�����
void handle_sigint(int sig) {
    printf("Caught signal %d (SIGINT)\n", sig);
}

int main() {
    // �����źż�
    sigset_t sigset;

    // ����źż�
    if (sigemptyset(&sigset) == -1) {
        perror("sigemptyset() failed");
        return EXIT_FAILURE;
    }

    // ע���źŴ�����
    if (signal(SIGINT, handle_sigint) == SIG_ERR) {
        perror("signal() failed");
        return EXIT_FAILURE;
    }

    printf("Press Ctrl+C to catch a signal.\n");

    // ���������ڵ����У�ֱ�����յ� SIGINT �ź�
    while (1) {
        pause(); // ��ִͣ�У��ȴ��ź�
    }

    return EXIT_SUCCESS;
}
