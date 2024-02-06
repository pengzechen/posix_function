#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>



int main() {

    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) == NULL) {

        perror("getcwd() failed");

        return EXIT_FAILURE;

    }


    printf("Current working directory is: %s\n", cwd);


    return EXIT_SUCCESS;
}

