#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>



int main() {

    char buffer[100];

    ssize_t bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1); 

    if (bytesRead == -1) {

        perror("read failed");

        exit(EXIT_FAILURE);

    }

    buffer[bytesRead] = '\0';

    printf("You entered: %s\n", buffer);

    return 0;
}

