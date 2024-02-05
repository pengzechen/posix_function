#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sys/stat.h>

#include <string.h>

int main() {

    const char *filename = "example.txt";

    FILE *file;

    long fileSize;

    char *data = "Hello, World!";

    size_t bytesWritten, bytesRead;


    file = fopen(filename, "w+");

    if (file == NULL) {

        perror("Error opening file");

        return EXIT_FAILURE;

    }


    fileSize = lseek(fileno(file), 0, SEEK_END);

    printf("Initial file size: %ld\n", fileSize);


    if (ftruncate(fileno(file), fileSize + strlen(data) + 1) == -1) {

        perror("Error truncating file");

        fclose(file);

        return EXIT_FAILURE;

    }

    bytesWritten = fwrite(data, 1, strlen(data) + 1, file);

    if (bytesWritten != strlen(data) + 1) {

        perror("Error writing to file");

        fclose(file);

        return EXIT_FAILURE;

    }

    if (fseek(file, 0, SEEK_SET) == -1) {

        perror("Error seeking to file beginning");

        fclose(file);

        return EXIT_FAILURE;

    }

    bytesRead = fread(data, 1, strlen(data) + 1, file);

    if (bytesRead != strlen(data) + 1) {

        perror("Error reading from file");

        fclose(file);

        return EXIT_FAILURE;

    }

    printf("Read data: %s\n", data);


    fclose(file);

    return EXIT_SUCCESS;

}

