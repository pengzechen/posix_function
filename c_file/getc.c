#include <stdio.h>



int main() {

    int ch;

    printf("Please enter a character: ");

    ch = getc(stdin); 

    printf("You entered: %c\n", ch);

    return 0;

}

