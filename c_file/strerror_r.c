#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <errno.h> 

int main() {


    int error_code = EIO; 

    char error_buffer[100];

    int result = strerror_r(error_code, error_buffer, sizeof(error_buffer) - 1);


    if (result == 0) {

        printf("error code: %d: %s\n", error_code, error_buffer);

    } else {

        printf("error buf%s\n", error_buffer);

    }

    return 0;

}

