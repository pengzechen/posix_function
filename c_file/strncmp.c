#include <stdio.h>

#include <string.h>

int main() {

    char string1[] = "Hello";

    char string2[] = "Hello";

    char string3[] = "World";

    int result = strncmp(string1, string2, 5);

    if (result == 0) {

        printf("error \n");

    } else if (result < 0) {

        printf("string1 < string2\n");

    } else {

        printf("string1 > string2\n");

    }

    result = strncmp(string1, string3, 5);

    if (result == 0) {

        printf("error\n");

    } else if (result < 0) {

        printf("string1 < string3\n");

    } else {

        printf("string1 > string3\n");

    }

    return 0;

}

