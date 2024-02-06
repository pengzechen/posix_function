#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <string.h>

#include <errno.h>

#include <unistd.h>

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>


#define PATH_MAX 4096

int main() {


    const char *directory_name = "demo_directory";

    char directory_path[PATH_MAX];



    char current_directory[PATH_MAX];

    if (getcwd(current_directory, PATH_MAX) == NULL) {

        perror("getcwd() failed");

        return EXIT_FAILURE;

    }


    snprintf(directory_path, PATH_MAX+128, "%s/%s", current_directory, directory_name);


    int result = mkdir(directory_path, 0755);

    if (result != 0) {

        if (errno != EEXIST) { // ���Ŀ¼�Ѿ����ڣ�����Ϊ����

            perror("mkdir() failed to create directory");

            return EXIT_FAILURE;

        }

    } else {

        printf("Directory %s created successfully.\n", directory_name);

    }


    sleep(1);

    result = rmdir(directory_path);

    if (result == 0) {

        printf("Directory %s successfully removed.\n", directory_name);

    } else {

        perror("rmdir() failed");

        return EXIT_FAILURE;

    }



    return EXIT_SUCCESS;

}

