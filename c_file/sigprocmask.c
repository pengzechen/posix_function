#include <stdio.h>

#include <signal.h>

#include <unistd.h>

#include <time.h>

#include <stdlib.h>


int main() {

    sigset_t sigset, old_sigset;

    struct timespec timeout;



    // ����źż�

    if (sigemptyset(&sigset) == -1) {

        perror("sigemptyset() failed");

        return EXIT_FAILURE;

    }



    // �� SIGINT �źż����źż�

    if (sigaddset(&sigset, SIGINT) == -1) {

        perror("sigaddset() failed");

        return EXIT_FAILURE;

    }



    // ���� SIGINT �ź�

    if (sigprocmask(SIG_BLOCK, &sigset, &old_sigset) == -1) {

        perror("sigprocmask(SIG_BLOCK) failed");

        return EXIT_FAILURE;

    }



    // �ȴ��źţ�����������һ��1��ĳ�ʱ

    timeout.tv_sec = 1;

    timeout.tv_nsec = 0;

    if (sigtimedwait(&sigset, NULL, &timeout) == -1) {

        perror("sigtimedwait() failed");

        return EXIT_FAILURE;

    }



    // ������� SIGINT �ź�

    if (sigprocmask(SIG_UNBLOCK, &sigset, NULL) == -1) {

        perror("sigprocmask(SIG_UNBLOCK) failed");

        return EXIT_FAILURE;

    }



    // ��ӡ������κ���ź�״̬

    if (sigpending(&sigset) == -1) {

        perror("sigpending() failed");

        return EXIT_FAILURE;

    }



    printf("Signals pending after unblocking SIGINT: ");

    if (sigismember(&sigset, SIGINT)) {

        printf("SIGINT is pending.\n");

    } else {

        printf("SIGINT is not pending.\n");

    }



    return EXIT_SUCCESS;

}

