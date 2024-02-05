#include <unistd.h>

#include <stdio.h>

#define PATH_MAX 500

int main() {

    const char *new_directory = "/path/to/new/directory";



    // 改变当前工作目录

    if (chdir(new_directory) == 0) {

        // 成功改变目录，打印新的当前工作目录

        char current_directory[PATH_MAX];

        if (getcwd(current_directory, sizeof(current_directory)) != NULL) {

            printf("Changed directory to: %s\n", current_directory);

        } else {

            perror("getcwd() failed");

        }

    } else {

        // 改变目录失败，打印错误信息

        perror("chdir() failed");

    }



    return 0;

}

