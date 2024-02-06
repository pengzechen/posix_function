#include <stdio.h>

#include <signal.h>

#include <unistd.h>

#include <time.h>

#include <stdlib.h>


int main() {

    sigset_t sigset, old_sigset;

    struct timespec timeout;

    if (sigemptyset(&sigset) == -1) {

        perror("sigemptyset() failed");

        return EXIT_FAILURE;

    }


    if (sigaddset(&sigset, SIGINT) == -1) {

        perror("sigaddset() failed");

        return EXIT_FAILURE;

    }



    if (sigprocmask(SIG_BLOCK, &sigset, &old_sigset) == -1) {

        perror("sigprocmask(SIG_BLOCK) failed");

        return EXIT_FAILURE;

    }


    timeout.tv_sec = 1;

    timeout.tv_nsec = 0;

    if (sigtimedwait(&sigset, NULL, &timeout) == -1) {

        perror("sigtimedwait() failed");

        return EXIT_FAILURE;

    }


    if (sigprocmask(SIG_UNBLOCK, &sigset, NULL) == -1) {

        perror("sigprocmask(SIG_UNBLOCK) failed");

        return EXIT_FAILURE;

    }


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

