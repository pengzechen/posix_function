#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h> // ���ڶ��� uintmax_t

int main() {
    const char *filename = "example.txt";
    FILE *file;
    off_t pos;
    char *data = "Hello, World!";

    // ���ļ�
    file = fopen(filename, "w+");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // д������
    fputs(data, file);

    // ��ȡ��ǰ�ļ�λ��
    pos = ftello(file);
    if (pos == -1) {
        perror("Error getting file position");
        fclose(file);
        return EXIT_FAILURE;
    }

    // ��ӡ��ǰ�ļ�λ��
    printf("Current file position: %ju\n", (uintmax_t)pos);

    // �ر��ļ�
    fclose(file);

    // ���������˳�
    return EXIT_SUCCESS;
}
