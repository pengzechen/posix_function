#include <stdio.h>

#include <stdlib.h>



int main() {

    char *user = getenv("USER");

    if (user != NULL) {

        printf("The value of the USER environment variable is: %s\n", user);

    } else {
        printf("The USER environment variable is not set.\n");

    }

    return 0;
}

