#include <stdio.h>

#include <ctype.h> 

int main() {
    char ch = ' ';

    if (isblank(ch)) {

        printf(" %c \n", ch);

    } else {

        printf("else %c \n", ch);

    }

    return 0;
}

