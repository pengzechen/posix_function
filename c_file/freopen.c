#include <stdio.h>



int main() {


    freopen("output.txt", "w", stdout); 

    printf("Hello, World! This is a demo of the freopen function.\n");

    fclose(stdout);

    return 0;

}

