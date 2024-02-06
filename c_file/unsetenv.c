#include <stdio.h>

#include <stdlib.h>



int main() {


    if (unsetenv("MY_VAR") != 0) {

        perror("unsetenv() failed");

        return EXIT_FAILURE;

    }

    printf("Environment variable MY_VAR has been removed.\n");

    return 0;

}

