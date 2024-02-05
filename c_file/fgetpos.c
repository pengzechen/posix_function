#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h>

#include <errno.h>

#include <sys/types.h>

#include <sys/stat.h>



int main() {

    const char *filename = "example.txt";

    FILE *file;

    fpos_t position;

    int result;

    file = fopen(filename, "r+");

    if (file == NULL) {

        perror("Error opening file");

        return EXIT_FAILURE;

    }

    result = fgetpos(file, &position);

    if (result == -1) {

        perror("Error getting file position");

        fclose(file);

        return EXIT_FAILURE;

    }

    printf("Current file position: %ld\n", position.__pos);

    result = fseek(file, 0, SEEK_SET);

    if (result == -1) {

        perror("Error seeking to file beginning");

        fclose(file);

        return EXIT_FAILURE;

    }

    result = fgetpos(file, &position);

    if (result == -1) {

        perror("Error getting file position");

        fclose(file);

        return EXIT_FAILURE;

    }

    printf("New file position after seeking: %ld\n", position.__pos);


    fclose(file);


    return EXIT_SUCCESS;

}

