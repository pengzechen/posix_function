#include <stdio.h>

#include <stdlib.h>



int main() {

    const char *filename = "example.txt";

    FILE *file;

    int character;

    file = fopen(filename, "r");

    if (file == NULL) {

        perror("Error opening file");

        return EXIT_FAILURE;

    }

    while ((character = getc_unlocked(file)) != EOF) {

        putchar(character);

    }


    if (fclose(file) != 0) {

        perror("Error closing file");

        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;

}

