#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sys/stat.h>

#include <fcntl.h>

#include <stdint.h> 


int main() {

    const char *filename = "example.txt";

    FILE *file;

    off_t pos;

    char *data = "Hello, World!";

    file = fopen(filename, "w+");

    if (file == NULL) {

        perror("Error opening file");

        return EXIT_FAILURE;

    }

    fputs(data, file);

    pos = ftello(file);

    if (pos == -1) {

        perror("Error getting file position");

        fclose(file);

        return EXIT_FAILURE;

    }

    printf("Current file position: %ju\n", (uintmax_t)pos);

    fclose(file);

    return EXIT_SUCCESS;

}

