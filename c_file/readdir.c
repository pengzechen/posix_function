#include <stdio.h>

#include <dirent.h>

#include <unistd.h>

#include <stdlib.h>



int main() {

    const char *directory_name = "demo_directory";

    DIR *dir;

    if ((dir = opendir(directory_name)) == NULL) {

        perror("opendir() failed");

        return EXIT_FAILURE;

    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {

        printf("%s\n", entry->d_name);

    }

    if (closedir(dir) == -1) {

        perror("closedir() failed");

        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;

}

