#include <stdio.h>

#include <stdlib.h>

#include <signal.h>

#include <unistd.h>



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

    if (sigismember(&sigset, SIGINT)) {

        printf("SIGINT is in the signal set.\n");

    } else {

        printf("SIGINT is not in the signal set.\n");

    }

    return EXIT_SUCCESS;

}

