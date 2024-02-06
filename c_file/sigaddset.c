#include <stdio.h>

#include <stdlib.h>

#include <signal.h>

#include <unistd.h>



void handle_sigint(int sig) {

    printf("Caught signal %d (SIGINT)\n", sig);

}



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

    

    printf("Press Ctrl+C to catch a signal.\n");


    if (signal(SIGINT, handle_sigint) == SIG_ERR) {

        perror("signal() failed");

        return EXIT_FAILURE;

    }

    while (1) {

        pause();

    }

    return EXIT_SUCCESS;

}

