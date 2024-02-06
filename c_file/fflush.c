#include <stdio.h>

#include <stdlib.h>



int main() {

    const char *filename = "example.txt";

    FILE *file;

    char buffer[1024];

    size_t bytes_written;

    file = fopen(filename, "w");

    if (file == NULL) {

        perror("fopen failed");

        return 1;

    }

    snprintf(buffer, sizeof(buffer), "Hello, World!");

    bytes_written = fputs(buffer, file);

    if (bytes_written == -1) {

        perror("fputs failed");

        fclose(file); 

        return 1;

    }

    fflush(file);

    snprintf(buffer, sizeof(buffer), "This is another line.");

    bytes_written = fputs(buffer, file);

    if (bytes_written == -1) {

        perror("fputs failed");

        fclose(file); 

        return 1;

    }

    fflush(file);

    if (fclose(file) != 0) {

        perror("fclose failed");

        return 1;

    }


    printf("Data written to %s successfully.\n", filename);

    return 0;

}

