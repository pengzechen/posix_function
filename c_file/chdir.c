#include <unistd.h>

#include <stdio.h>

#define PATH_MAX 500

int main() {

    const char *new_directory = "/path/to/new/directory";

    if (chdir(new_directory) == 0) {

        char current_directory[PATH_MAX];

        if (getcwd(current_directory, sizeof(current_directory)) != NULL) {

            printf("Changed directory to: %s\n", current_directory);

        } else {

            perror("getcwd() failed");

        }

    } else {

        perror("chdir() failed");

    }

    return 0;
}

