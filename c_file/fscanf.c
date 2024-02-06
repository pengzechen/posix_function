#include <stdio.h>



int main() {

    int num;

    FILE *file;

    const char *filename = "input.txt";

    file = fopen(filename, "r"); 

    if (file == NULL) {

        perror("fopen failed");

        return 1; 

    }

    while (fscanf(file, "%d", &num) == 1) {

        printf("Read integer: %d\n", num);

    }

    if (fclose(file) != 0) {

        perror("fclose failed");

        return 1; 

    }



    printf("Reading from file completed successfully.\n");

    return 0; 

}

