#include <stdio.h>

#include <signal.h>

#include <unistd.h>

#include <stdlib.h>

#include <signal.h>


void handle_sigint(int sig) {

    printf("Received signal %d (SIGINT)\n", sig);

}



int main() {

    sigset_t sigset;

    int sig;


    if (signal(SIGINT, handle_sigint) == SIG_ERR) {

        perror("signal() registration failed");

        return EXIT_FAILURE;

    }

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



    printf("Waiting for SIGINT...\n");

    if (sigwait(&sigset, &sig) == -1) {

        perror("sigwait() failed");

        return EXIT_FAILURE;

    }

    printf("Received SIGINT, exiting.\n");

    return EXIT_SUCCESS;

}

