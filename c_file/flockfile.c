#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h>

#include <sys/stat.h>

#include <errno.h>

#include <string.h>

int main() {

    const char *filename = "example.txt";

    int fd;

    struct flock lock;

    fd = open(filename, O_WRONLY | O_CREAT, 0644);

    if (fd == -1) {

        perror("Error opening file");

        return EXIT_FAILURE;

    }


    memset(&lock, 0, sizeof(lock));

    lock.l_type = F_WRLCK; // д��

    lock.l_whence = SEEK_SET;

    lock.l_start = 0;

    lock.l_len = 0; 


    if (fcntl(fd, F_GETLK, &lock) == -1) {

        perror("Error getting lock status");

        close(fd);

        return EXIT_FAILURE;

    }

    if (lock.l_type != F_UNLCK) {

        printf("File is already locked. Waiting for the lock to be released...\n");

        while (fcntl(fd, F_GETLK, &lock) == -1) {

            if (errno != EINTR) {

                perror("Error waiting for lock");

                close(fd);

                return EXIT_FAILURE;

            }

        }

    }


    flockfile(fdopen(fd, "w+"));

    printf("File is locked. Writing to file...\n");

    funlockfile(fdopen(fd, "w+"));


    if (close(fd) == -1) {

        perror("Error closing file");

        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;

}

