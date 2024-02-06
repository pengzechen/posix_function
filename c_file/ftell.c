#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sys/stat.h>

#include <fcntl.h>



int main() {

    const char *filename = "example.txt";

    FILE *file;

    long pos;

    char *data = "Hello, World!";

    file = fopen(filename, "w+");

    if (file == NULL) {

        perror("Error opening file");

        return EXIT_FAILURE;

    }

    fputs(data, file);

    pos = ftell(file);

    if (pos == -1) {

        perror("Error getting file position");

        fclose(file);

        return EXIT_FAILURE;

    }

    printf("Current file position: %ld\n", pos);

    fclose(file);

    return EXIT_SUCCESS;

}

