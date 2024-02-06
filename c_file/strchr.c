#include <stdio.h>

#include <string.h>

int main() {

    char str[] = "Hello, World!";

    char to_find = 'o';

    char *found = strchr(str, to_find);


    if (found != NULL) {

        printf("to find'%c'found - str: %ld\n", to_find, found - str);

    } else {

        printf("char: '%c'\n", to_find);

    }

    return 0;

}

