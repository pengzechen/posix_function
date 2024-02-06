#include <stdio.h>

#include <stdlib.h>



int main() {

    const char *filename = "example.txt";

    FILE *file;

    int character;

    file = fopen(filename, "w");

    if (file == NULL) {

        perror("Error opening file");

        return EXIT_FAILURE;

    }

    for (character = 'A'; character <= 'Z'; ++character) {

        putc_unlocked(character, file);

    }

    putc_unlocked('\n', file);

    if (fclose(file) != 0) {

        perror("Error closing file");

        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;

}

