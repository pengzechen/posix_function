#include <stdio.h>

#include <stdlib.h>

#include <signal.h>

#include <unistd.h>

#include <string.h>


void handle_sigint(int sig) {

    printf("Caught signal %d (SIGINT)\n", sig);

}


int main() {


    struct sigaction sa;


    memset(&sa, 0, sizeof(sa));


    sa.sa_handler = handle_sigint;

    sa.sa_flags = SA_RESTART;


    if (sigaction(SIGINT, &sa, NULL) == -1) {

        perror("sigaction() failed");

        return EXIT_FAILURE;

    }



    printf("Press Ctrl+C to catch a signal.\n");

    while (1) {

        pause(); 

    }

    return EXIT_SUCCESS;
}

