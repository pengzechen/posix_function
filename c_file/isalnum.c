#include <stdio.h>

#include <ctype.h>


int main() {

    char ch = 'a';
    if (isalnum(ch)) {
        printf("char: %c \n", ch);
    } else {
        printf("not char %c \n", ch);
    }
    return 0;
}

