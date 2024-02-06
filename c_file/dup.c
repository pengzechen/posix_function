#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

#include <unistd.h>
#include <string.h>
#include <sys/types.h>   
#include <sys/stat.h>   
#include <fcntl.h>

int main() {

    const char *text = "Hello, World!\n";

    int fd;

    int dup_fd;

    fd = open("example.txt", O_WRONLY | O_CREAT | O_EXCL, 0644);

    if (fd == -1) {

        perror("Error opening file");

        return EXIT_FAILURE;

    }

    dup_fd = dup(STDOUT_FILENO);

    if (dup_fd == -1) {

        perror("Error duplicating file descriptor");

        close(fd);

        return EXIT_FAILURE;

    }

    close(STDOUT_FILENO);

    write(dup_fd, text, strlen(text));


    dup2(dup_fd, STDOUT_FILENO);

    close(dup_fd);

    close(fd);

    return EXIT_SUCCESS;

}

