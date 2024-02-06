#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sys/stat.h>

#include <fcntl.h>



int main() {

    const char *filename = "example.txt";

    FILE *file;

    char buffer[11]; 

    size_t bytes_read;

    file = fopen(filename, "r");

    if (file == NULL) {

        perror("Error opening file");

        return EXIT_FAILURE;

    }

    bytes_read = fread(buffer, 1, sizeof(buffer), file);

    if (bytes_read == 0) {

        perror("Error reading from file");

        fclose(file);

        return EXIT_FAILURE;

    }

    printf("Read: %s\n", buffer);

    rewind(file);

    bytes_read = fread(buffer, 1, sizeof(buffer), file);

    if (bytes_read == 0) {

        perror("Error reading from file");

        fclose(file);

        return EXIT_FAILURE;

    }


    printf("Rewound and read: %s\n", buffer);

    fclose(file);

    return EXIT_SUCCESS;

}

