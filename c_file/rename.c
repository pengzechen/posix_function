#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <string.h>

#define PATH_MAX  200

int main() {

    // ����Դ�ļ���Ŀ���ļ���·��

    const char *source_filename = "demo_source_file.txt";

    const char *destination_filename = "demo_destination_file.txt";



    // ����Դ�ļ��ĸ������Ա���������������

    char source_path[PATH_MAX];

    char destination_path[PATH_MAX];

    snprintf(source_path, PATH_MAX, "%s/%s", getcwd(NULL, PATH_MAX), source_filename);

    snprintf(destination_path, PATH_MAX, "%s/%s", getcwd(NULL, PATH_MAX), destination_filename);



    // ����Դ�ļ�������������ڣ�

    FILE *source_file = fopen(source_path, "w");

    if (source_file == NULL) {

        perror("fopen() failed to create source file");

        return EXIT_FAILURE;

    }



    fprintf(source_file, "This is a test file for the rename() demo.\n");

    fclose(source_file);



    // �������ļ�

    int result = rename(source_path, destination_path);

    if (result == 0) {

        printf("File successfully renamed from %s to %s.\n", source_filename, destination_filename);

    } else {

        perror("rename() failed");

        unlink(source_path); // ɾ��ԭʼ�ļ������������ʧ��

        return EXIT_FAILURE;

    }



    // ɾ��ԭʼ�ļ�������������ɹ���

    result = unlink(source_path);

    if (result != 0) {

        perror("unlink() failed to delete source file");

        return EXIT_FAILURE;

    }



    // ���������˳�

    return EXIT_SUCCESS;

}

