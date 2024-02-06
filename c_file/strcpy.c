#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main() {

    char source[] = "Hello, World!";

    char destination[20]; 

    strcpy(destination, source);

    printf("%s\n", destination);

    return 0;

}

