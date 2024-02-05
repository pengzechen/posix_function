#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// �źŴ�����
void handle_signal(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    // �����źż�
    sigset_t sigset;

    // �������ź���ӵ��źż���
    if (sigfillset(&sigset) == -1) {
        perror("sigfillset() failed");
        return EXIT_FAILURE;
    }

    // �����źŴ�����
    if (sigprocmask(SIG_SETMASK, &sigset, NULL) == -1) {
        perror("sigprocmask() failed");
        return EXIT_FAILURE;
    }

    printf("Press any signal to catch it.\n");

    // ע���źŴ�����
    if (signal(SIGINT, handle_signal) == SIG_ERR) {
        perror("signal() failed");
        return EXIT_FAILURE;
    }

    // ע���źŴ�����
    if (signal(SIGTERM, handle_signal) == SIG_ERR) {
        perror("signal() failed");
        return EXIT_FAILURE;
    }

    // ע���źŴ�����
    if (signal(SIGQUIT, handle_signal) == SIG_ERR) {
        perror("signal() failed");
        return EXIT_FAILURE;
    }

    // ���������ڵ����У�ֱ�����յ��ź�
    while (1) {
        pause(); // ��ִͣ�У��ȴ��ź�
    }

    return EXIT_SUCCESS;
}
