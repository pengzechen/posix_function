#include <stdio.h>



int main() {

    char buffer[30];

    sprintf(buffer, "Hello, %s!", "World");


    printf("buffer: %s\n", buffer);

    return 0;

}

