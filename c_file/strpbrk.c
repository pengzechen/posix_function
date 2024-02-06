#include <stdio.h>

#include <string.h>

int main() {

    char string[] = "Hello, World!";

    char chars[] = "abc";

    char *found = strpbrk(string, chars);

    if (found != NULL) {

        printf("*found: '%c'\n", *found);

    } else {

        printf("no\n");

    }

    return 0;

}

