#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // ʹ�� tmpnam() ����һ����ʱ�ļ���
    char *filename = tmpnam(NULL);
    if (filename == NULL) {
        perror("tmpnam() failed");
        return EXIT_FAILURE;
    }

    // ����ʱ�ļ�
    FILE *file = fopen(filename, "w+");
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

    // �ض�λ�ļ�ָ�뵽�ļ���ͷ
    if (fseek(file, 0, SEEK_SET) != 0) {
        perror("fseek() failed to rewind the file");
        fclose(file);
        free(filename);
        return EXIT_FAILURE;
    }

    // ��ȡ����ӡ�ļ�����
    char buffer[256];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    // �ر���ʱ�ļ�
    if (fclose(file) != 0) {
        perror("fclose() failed to close the file");
        free(filename);
        return EXIT_FAILURE;
    }

    // ɾ����ʱ�ļ�
    if (remove(filename) != 0) {
        perror("remove() failed to delete the file");
        free(filename);
        return EXIT_FAILURE;
    }

    // �ͷ���ʱ�ļ����ڴ�
    free(filename);

    return EXIT_SUCCESS;
}
