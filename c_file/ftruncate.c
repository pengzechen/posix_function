#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sys/stat.h>

#include <fcntl.h>

#include <string.h>

int main() {

    const char *filename = "example.txt";

    int fd;

    ssize_t bytes_written;

    char *data = "Hello, World!";

    off_t new_size;


    fd = open(filename, O_WRONLY | O_CREAT, 0644);

    if (fd == -1) {

        perror("Error opening file");

        return EXIT_FAILURE;

    }

    bytes_written = write(fd, data, strlen(data));

    if (bytes_written == -1) {

        perror("Error writing to file");

        close(fd);

        return EXIT_FAILURE;

    }

    new_size = lseek(fd, 0, SEEK_END);

    if (new_size == -1) {

        perror("Error seeking file");

        close(fd);

        return EXIT_FAILURE;

    }


    printf("Original file size: %ld bytes\n", new_size);


    new_size = 10; // �ض��ļ���10�ֽ�

    if (ftruncate(fd, new_size) == -1) {

        perror("Error truncating file");

        close(fd);

        return EXIT_FAILURE;

    }


    new_size = lseek(fd, 0, SEEK_END);

    if (new_size == -1) {

        perror("Error seeking file");

        close(fd);

        return EXIT_FAILURE;

    }

    printf("New file size: %ld bytes\n", new_size);


    close(fd);



    return EXIT_SUCCESS;

}

