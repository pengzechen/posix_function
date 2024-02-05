#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    int file_descriptor;

    // ���ļ�
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen failed");
        return 1;
    }

    // ��ȡ�ļ����ļ�������
    file_descriptor = fileno(file);
    if (file_descriptor == -1) {
        perror("fileno failed");
        fclose(file); // �ر��ļ���
        return 1;
    }

    // ��ӡ�ļ�������
    printf("File descriptor: %d\n", file_descriptor);

    // �ر��ļ�
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1;
    }

    printf("File operations completed successfully.\n");
    return 0;
}
