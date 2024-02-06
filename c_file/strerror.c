#include <stdio.h>

#include <stdlib.h>

#include <string.h>



int main() {

    int error_code = 123;

    char *error_message = strerror(error_code);

    if (error_message == NULL) {

        printf("error \n");

    } else {

        printf("error code %d: %s\n", error_code, error_message);

    }

    free(error_message);

    return 0;

}

