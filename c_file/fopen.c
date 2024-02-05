#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    const char *filename = "example.txt";
    const char *mode = "r"; // "r" ��ʾֻ��ģʽ

    // ���ļ�
    file = fopen(filename, mode);
    if (file == NULL) {
        perror("fopen failed");
        return 1; // ���ļ�ʧ��
    }

    // �ļ��ɹ��򿪣����Խ��ж�ȡ��д������
    // ...

    // �ر��ļ�
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1; // �ر��ļ�ʧ��
    }

    printf("File operations completed successfully.\n");
    return 0; // ���������˳�
}
