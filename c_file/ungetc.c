#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

#include <string.h>

int main() {

    char buffer[100];

    int c;


    printf("Enter a string: ");

    fgets(buffer, sizeof(buffer), stdin);


    c = buffer[strlen(buffer) - 1]; 

    printf("The last character you entered is: %c\n", c);


    if (ungetc(c, stdin) == EOF) {

        perror("ungetc failed");

        exit(EXIT_FAILURE);
    }


    printf("Enter another string: ");

    fgets(buffer, sizeof(buffer), stdin);


    c = buffer[strlen(buffer) - 1]; 

    printf("The last character you entered is now: %c\n", c);

    return 0;

}

