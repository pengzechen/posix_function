#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h>



int main() {

    const char *filename = "example.txt";

    int fd;

    FILE *file;

    char *data = "Hello, World!";

    ssize_t bytes_written;

    fd = open(filename, O_WRONLY | O_CREAT | O_EXCL, 0644);

    if (fd == -1) {

        perror("open failed");

        return 1;

    }


    file = fdopen(fd, "w");

    if (file == NULL) {

        perror("fdopen failed");

        close(fd); 

        return 1;

    }


    bytes_written = fputs(data, file);

    if (bytes_written == -1) {

        perror("fputs failed");

        fclose(file); 
        return 1;

    }


    if (fclose(file) != 0) {

        perror("fclose failed");

        return 1;

    }


    if (close(fd) == -1) {

        perror("close failed");

        return 1;

    }

    printf("Data written to %s successfully.\n", filename);

    return 0;

}

