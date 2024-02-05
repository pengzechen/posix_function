#include <stdio.h>

#include <time.h>

int main() {

    fprintf(stdout, "Hello, World! This is a demo of the fprintf function.\n");

    fprintf(stdout, "The current time is %s.\n", ctime(NULL));

    return 0;

}

