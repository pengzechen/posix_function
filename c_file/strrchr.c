#include <stdio.h>

#include <string.h>

int main() {

    char string[] = "Hello, World!";


    char *found = strrchr(string, 'a');


    if (found != NULL) {

        printf("fond: %c found - string: %ld\n", *found, found - string);

    } else {

        printf("a not in hello world\n");

    }


    return 0;

}

