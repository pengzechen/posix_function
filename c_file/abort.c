#include <stdio.h>

#include <stdlib.h>



int main() {

    printf("This program will terminate immediately with an abortion.\n");

    abort();

    printf("This message will not be printed.\n");

    return EXIT_SUCCESS;
}

