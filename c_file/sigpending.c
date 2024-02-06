#include <stdio.h>

#include <stdlib.h>

#include <signal.h>

#include <unistd.h>

#include <time.h>



int main() {

    sigset_t sigset;

    struct timespec timeout;

    int sigcount = 0;

    if (sigemptyset(&sigset) == -1) {

        perror("sigemptyset() failed");

        return EXIT_FAILURE;

    }

    timeout.tv_sec = 1;

    timeout.tv_nsec = 0;

    if (sigpending(&sigset) == -1) {

        perror("sigpending() failed");

        return EXIT_FAILURE;

    }

    if (sigismember(&sigset, SIGINT)) {

        sigcount++;

        printf("SIGINT is pending.\n");

    }



    if (sigismember(&sigset, SIGTERM)) {

        sigcount++;

        printf("SIGTERM is pending.\n");

    }

    printf("Total signals pending: %d\n", sigcount);



    return EXIT_SUCCESS;

}

