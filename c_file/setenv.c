#include <stdio.h>

#include <stdlib.h>



int main() {


    if (setenv("MY_VAR", "my_value", 1) != 0) {

        perror("setenv() failed");

        return EXIT_FAILURE;

    }



    printf("Environment variable MY_VAR set. Now you can access it in other processes.\n");



    return 0;

}

