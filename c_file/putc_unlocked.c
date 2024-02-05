#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    int character;

    // ���ļ�
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // д���ַ����ļ�
    for (character = 'A'; character <= 'Z'; ++character) {
        putc_unlocked(character, file);
    }

    // д���ļ�������
    putc_unlocked('\n', file);

    // ����ļ������ر�ʧ�ܣ���ӡ������Ϣ
    if (fclose(file) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    // ���������˳�
    return EXIT_SUCCESS;
}
