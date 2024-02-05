#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <string.h>

#include <errno.h>

#define PATH_MAX 300

int main() {

    // ����Ҫɾ����Ŀ¼��·��

    const char *directory_name = "demo_directory";

    char directory_path[PATH_MAX];



    // ��ȡ��ǰ����Ŀ¼

    char current_directory[PATH_MAX];

    if (getcwd(current_directory, PATH_MAX) == NULL) {

        perror("getcwd() failed");

        return EXIT_FAILURE;

    }



    // ����Ŀ¼������·��

    snprintf(directory_path, PATH_MAX, "%s/%s", current_directory, directory_name);



    // ����Ŀ¼������������ڣ�

    int result = mkdir(directory_path, 0755);

    if (result != 0) {

        if (errno != EEXIST) { // ���Ŀ¼�Ѿ����ڣ�����Ϊ����

            perror("mkdir() failed to create directory");

            return EXIT_FAILURE;

        }

    } else {

        printf("Directory %s created successfully.\n", directory_name);

    }



    // �ȴ�һ��ʱ�䣬�Ա�Ŀ¼���Ա�����ϵͳ����

    sleep(1);



    // ɾ��Ŀ¼

    result = rmdir(directory_path);

    if (result == 0) {

        printf("Directory %s successfully removed.\n", directory_name);

    } else {

        perror("rmdir() failed");

        return EXIT_FAILURE;

    }



    return EXIT_SUCCESS;

}

