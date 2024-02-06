#include <stdio.h>

#include <stdlib.h>



int main() {

    const char *filename = "example.txt";

    FILE *file;

    char buffer[1024];

    size_t bytes_read;


    file = fopen(filename, "r");

    if (file == NULL) {

        perror("fopen failed");

        return 1;

    }

    while (!feof(file)) {

        bytes_read = fread(buffer, 1, sizeof(buffer), file);

        if (bytes_read == 0) {

            break; 

        }

        printf("%s", buffer);

    }

    if (fclose(file) != 0) {

        perror("fclose failed");

        return 1;

    }

    printf("File read successfully.\n");

    return 0;

}

