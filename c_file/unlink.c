#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>



int main() {

    // ʹ�� tmpnam() ����һ����ʱ�ļ���

    char *filename = mkstemp(NULL);

    if (filename == NULL) {

        perror("tmpnam() failed");

        return EXIT_FAILURE;

    }



    // ����ʱ�ļ�

    FILE *file = fopen(filename, "w");

    if (file == NULL) {

        perror("fopen() failed to open the file");

        free(filename);

        return EXIT_FAILURE;

    }



    // д��һЩ�ı�����ʱ�ļ�

    const char *text = "Hello, World!\n";

    if (fputs(text, file) == EOF) {

        perror("fputs() failed to write to the file");

        fclose(file);

        free(filename);

        return EXIT_FAILURE;

    }



    // �ر���ʱ�ļ�

    if (fclose(file) != 0) {

        perror("fclose() failed to close the file");

        free(filename);

        return EXIT_FAILURE;

    }



    // ʹ�� unlink() ����ɾ����ʱ�ļ�

    if (unlink(filename) != 0) {

        perror("unlink() failed to delete the file");

        free(filename);

        return EXIT_FAILURE;

    }



    // �ͷ���ʱ�ļ����ڴ�

    free(filename);



    printf("File %s deleted successfully.\n", filename);



    return EXIT_SUCCESS;

}

