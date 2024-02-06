#include <stdio.h>

#include <ctype.h> 
int main() {

    char ch = '\n'; 

    if (iscntrl(ch)) {

        printf(" %c \n", ch);

    } else {

        printf("else %c \n", ch);

    }

    return 0;

}

