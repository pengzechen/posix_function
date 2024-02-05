#include <stdio.h>

#include <signal.h>

#include <unistd.h>

#include <stdlib.h>


int main() {

    sigset_t sigset;



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



    // �����źż�

    if (sigprocmask(SIG_SETMASK, &sigset, NULL) == -1) {

        perror("sigprocmask() failed");

        return EXIT_FAILURE;

    }



    printf("Program is suspended until SIGINT arrives.\n");



    // �ȴ� SIGINT �ź�

    if (sigsuspend(&sigset) == -1) {

        perror("sigsuspend() failed");

        return EXIT_FAILURE;

    }



    // �źŴ����󷵻�

    printf("SIGINT received, resuming execution.\n");



    return EXIT_SUCCESS;

}

