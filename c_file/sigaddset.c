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
    
    // ��ʼ���źż�
    if (sigemptyset(&sigset) == -1) {
        perror("sigemptyset() failed");
        return EXIT_FAILURE;
    }
    
    // �� SIGINT �ź���ӵ��źż���
    if (sigaddset(&sigset, SIGINT) == -1) {
        perror("sigaddset() failed");
        return EXIT_FAILURE;
    }
    
    // �����źŴ�����
    if (sigprocmask(SIG_SETMASK, &sigset, NULL) == -1) {
        perror("sigprocmask() failed");
        return EXIT_FAILURE;
    }
    
    printf("Press Ctrl+C to catch a signal.\n");

    // ע���źŴ�����
    if (signal(SIGINT, handle_sigint) == SIG_ERR) {
        perror("signal() failed");
        return EXIT_FAILURE;
    }

    // ���������ڵ����У�ֱ�����յ� SIGINT �ź�
    while (1) {
        pause(); // ��ִͣ�У��ȴ��ź�
    }

    return EXIT_SUCCESS;
}
