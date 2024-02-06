#include <stdio.h>

#include <signal.h>

#include <unistd.h>

#include <stdlib.h>


int main() {

    sigset_t sigset;


    if (sigemptyset(&sigset) == -1) {

        perror("sigemptyset() failed");

        return EXIT_FAILURE;

    }


    if (sigaddset(&sigset, SIGINT) == -1) {

        perror("sigaddset() failed");

        return EXIT_FAILURE;

    }

    if (sigprocmask(SIG_SETMASK, &sigset, NULL) == -1) {

        perror("sigprocmask() failed");

        return EXIT_FAILURE;

    }


    printf("Program is suspended until SIGINT arrives.\n");


    if (sigsuspend(&sigset) == -1) {

        perror("sigsuspend() failed");

        return EXIT_FAILURE;

    }


    printf("SIGINT received, resuming execution.\n");



    return EXIT_SUCCESS;

}

