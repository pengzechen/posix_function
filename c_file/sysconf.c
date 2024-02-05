#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>


int main() {

    long int max_open_files = sysconf(_SC_OPEN_MAX);



    if (max_open_files == -1) {

        perror("sysconf() failed");

        return EXIT_FAILURE;

    }



    printf("The maximum number of open files is: %ld\n", max_open_files);



    return 0;

}

