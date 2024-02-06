#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h>

#include <errno.h>



int main() {

    const char *filename = "example.txt";

    int fd;

    int flags;

    ssize_t bytesRead;

    char buffer[1024];


    fd = open(filename, O_RDONLY);

    if (fd == -1) {

        perror("Error opening file");

        return EXIT_FAILURE;

    }


    flags = fcntl(fd, F_GETFL, 0);

    if (flags == -1) {

        perror("Error getting file flags");

        close(fd);

        return EXIT_FAILURE;

    }

    flags |= O_NONBLOCK;

    if (fcntl(fd, F_SETFL, flags) == -1) {

        perror("Error setting file flags");

        close(fd);

        return EXIT_FAILURE;

    }


    // while (1) {

        bytesRead = read(fd, buffer, sizeof(buffer) - 1);

        if (bytesRead == -1) {

            if (errno != EAGAIN) {

                perror("Error reading file");

            }

        } else {

            buffer[bytesRead] = '\0';

            printf("Read: %s\n", buffer);

        }

        // usleep(10000); // �ȴ�10000΢�루10���룩

    // }


    close(fd);

    return EXIT_SUCCESS;

}

