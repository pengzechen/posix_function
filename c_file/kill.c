#include <stdio.h>

#include <stdlib.h>

#include <signal.h>

#include <unistd.h>



int main() {


    pid_t pid = getpid();


    printf("The current process ID is: %d\n", (int)pid);

    if (kill(pid, SIGINT) == -1) {

        perror("kill() failed");

        return EXIT_FAILURE;

    }

    printf("SIGINT signal sent to process ID: %d\n", (int)pid);

    return EXIT_SUCCESS;

}

