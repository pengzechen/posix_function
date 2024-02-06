#include <stdio.h>

#include <signal.h>

#include <unistd.h>

#include <stdlib.h>


void handle_sigint(int sig) {

    printf("Caught signal %d (SIGINT)\n", sig);

}



int main() {

    if (signal(SIGINT, handle_sigint) == SIG_ERR) {

        perror("signal() registration failed");

        return EXIT_FAILURE;

    }



    printf("Press Ctrl+C to catch the SIGINT signal.\n");

    while (1) {

        pause();

    }

    return EXIT_SUCCESS;

}

