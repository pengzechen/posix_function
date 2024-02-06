#include <stdio.h>

#include <stdlib.h>



int main() {

    char input[100];

    int ch;

    printf("Enter a string: ");

    fgets(input, sizeof(input), stdin);

    if (feof(stdin)) {

        printf("End of file reached.\n");

    } else if (ferror(stdin)) {

        perror("Read error");

    } else {

        printf("You entered: %s", input);

    }

    clearerr(stdin);

    ch = getchar();

    if (feof(stdin)) {

        printf("End of file reached after clearerr().\n");

    } else if (ferror(stdin)) {

        perror("Read error after clearerr().");

    } else {

        printf("Read character: %c\n", ch);

    }

    return 0;

}

