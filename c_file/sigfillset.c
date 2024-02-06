#include <stdio.h>

#include <stdlib.h>

#include <signal.h>

#include <unistd.h>



void handle_signal(int sig) {

    printf("Caught signal %d\n", sig);

}



int main() {


    sigset_t sigset;


    if (sigfillset(&sigset) == -1) {

        perror("sigfillset() failed");

        return EXIT_FAILURE;

    }


    if (sigprocmask(SIG_SETMASK, &sigset, NULL) == -1) {

        perror("sigprocmask() failed");

        return EXIT_FAILURE;

    }



    printf("Press any signal to catch it.\n");

    if (signal(SIGINT, handle_signal) == SIG_ERR) {

        perror("signal() failed");

        return EXIT_FAILURE;

    }

    if (signal(SIGTERM, handle_signal) == SIG_ERR) {

        perror("signal() failed");

        return EXIT_FAILURE;

    }

    if (signal(SIGQUIT, handle_signal) == SIG_ERR) {

        perror("signal() failed");

        return EXIT_FAILURE;

    }

    while (1) {

        pause(); 

    }



    return EXIT_SUCCESS;

}

