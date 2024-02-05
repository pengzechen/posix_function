#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

#include <sys/stat.h>

#include <sys/types.h>

int main() {

    const char *directory_name = "demo_directory";

    if (mkdir(directory_name, 0755) == 0) {

        printf("Directory '%s' created successfully.\n", directory_name);

    } else {

        perror("mkdir() failed");
    }

    return EXIT_SUCCESS;

}

