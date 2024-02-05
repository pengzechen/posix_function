#include <stdio.h>

#include <stdlib.h>



int main() {

    const char *filename = "example.txt";

    FILE *file;

    int character;


    file = fopen(filename, "r");

    if (file == NULL) {

        perror("fopen failed");

        return 1;

    }


    while ((character = fgetc(file)) != EOF) {

        putchar(character);

    }

    if (feof(file)) {

        printf("Reached end of file.\n");

    }

    if (fclose(file) != 0) {

        perror("fclose failed");

        return 1;
    }


    printf("File read successfully.\n");

    return 0;

}

