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


    if (signal(SIGINT, handle_sigint) == SIG_ERR) {

        perror("signal() failed");

        return EXIT_FAILURE;

    }

    printf("Press Ctrl+C to catch a signal.\n");

    while (1) {

        pause(); 

    }



    return EXIT_SUCCESS;

}

