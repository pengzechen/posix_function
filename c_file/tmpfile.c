#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // ʹ�� tmpfile() ����һ����ʱ�ļ�
    FILE *file = tmpfile();
    if (file == NULL) {
        perror("tmpfile() failed");
        return EXIT_FAILURE;
    }

    // д��һЩ�ı�����ʱ�ļ�
    const char *text = "Hello, World!\n";
    if (fputs(text, file) == EOF) {
        perror("fputs() failed to write to the file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // �ض�λ��ʱ�ļ�ָ�뵽�ļ���ͷ
    if (fseek(file, 0, SEEK_SET) != 0) {
        perror("fseek() failed to rewind the file");
        fclose(file);
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
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
