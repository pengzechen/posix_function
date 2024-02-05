#include <stdio.h>

int main() {
    int num;
    FILE *file;
    const char *filename = "input.txt";

    // ���ļ�
    file = fopen(filename, "r"); // "r" ��ʾֻ��ģʽ
    if (file == NULL) {
        perror("fopen failed");
        return 1; // ���ļ�ʧ��
    }

    // ���ļ��ж�ȡ����
    while (fscanf(file, "%d", &num) == 1) {
        printf("Read integer: %d\n", num);
    }

    // �ر��ļ�
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1; // �ر��ļ�ʧ��
    }

    printf("Reading from file completed successfully.\n");
    return 0; // ���������˳�
}
