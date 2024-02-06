#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h>



int main() {

    int fd = open("example.txt", O_RDONLY);

    if (fd == -1) {

        perror("open() failed");

        return EXIT_FAILURE;

    }

    long config_value = fpathconf(fd, _PC_NAME_MAX);

    if (config_value == -1) {

        perror("fpathconf() failed");

        close(fd); 

        return EXIT_FAILURE;

    }

    printf("The maximum length of a file name is: %ld\n", config_value);

    if (close(fd) == -1) {

        perror("close() failed");

        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;

}

