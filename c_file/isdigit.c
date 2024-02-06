#include <stdio.h>

#include <ctype.h> 

int main() {

    char ch = '5';

    if (isdigit(ch)) {

        printf(" %c \n", ch);

    } else {

        printf("else %c \n", ch);

    }

    return 0;
}

