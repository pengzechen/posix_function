#include <stdio.h>

#include <unistd.h>

#include <fcntl.h>


int main() {

    int fd = open("example.txt", O_RDONLY); 
    if (fd == -1) {
        perror("open failed");
        return 1; 
    }

    printf("File opened successfully with file descriptor: %d\n", fd);

    if (close(fd) != 0) {

        perror("close failed");

        return 1;
    }

    printf("File closed successfully.\n");

    return 0;
}

