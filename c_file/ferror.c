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

    clearerr(file);

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {

        printf("%s", buffer);

    }

    if (ferror(file)) {

        perror("ferror detected");

        fclose(file); 

        return 1;

    }

    if (fclose(file) != 0) {

        perror("fclose failed");

        return 1;

    }

    printf("File read successfully.\n");

    return 0;

}

