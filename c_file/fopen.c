#include <stdio.h>

#include <stdlib.h>



int main() {

    FILE *file;

    const char *filename = "example.txt";

    const char *mode = "r"; 

    file = fopen(filename, mode);

    if (file == NULL) {

        perror("fopen failed");

        return 1; 

    }

    if (fclose(file) != 0) {

        perror("fclose failed");

        return 1; 

    }

    printf("File operations completed successfully.\n");

    return 0; 

}

