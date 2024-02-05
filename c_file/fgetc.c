#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    int character;

    // ���ļ�
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen failed");
        return 1;
    }

    // ��ȡ�ļ�����
    while ((character = fgetc(file)) != EOF) {
        // �����ȡ���ַ�
        putchar(character);
    }

    // ����Ƿ񵽴��ļ�ĩβ
    if (feof(file)) {
        printf("Reached end of file.\n");
    }

    // �ر��ļ�
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1;
    }

    printf("File read successfully.\n");
    return 0;
}
