#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    int character;

    // ���ļ�
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // ��ȡ�ļ�ֱ�������ļ�������
    while ((character = getc_unlocked(file)) != EOF) {
        // ��ӡ��ȡ���ַ�
        putchar(character);
    }

    // ����ļ������ر�ʧ�ܣ���ӡ������Ϣ
    if (fclose(file) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    // ���������˳�
    return EXIT_SUCCESS;
}
