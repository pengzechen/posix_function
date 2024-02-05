#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h>

#include <sys/stat.h>



int main() {

    const char *filename = "example.txt";

    int fd;



    // ���ļ�

    fd = open(filename, O_WRONLY | O_CREAT, 0644);

    if (fd == -1) {

        perror("Error opening file");

        return EXIT_FAILURE;

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

