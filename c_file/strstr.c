#include <stdio.h>

#include <string.h>



int main() {

    char str1[] = "Hello, World!";

    char str2[] = "World";

    char *found = strstr(str1, str2);

    if (found != NULL) {

        printf("str2: '%s'str1: '%s' found - str1%ld\n", str2, str1, found - str1);

    } else {

        printf("str2: '%s'\n", str2);

    }

    return 0;

}

