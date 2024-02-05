#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    char buffer[1024];
    size_t bytes_read;

    // ���ļ�
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen failed");
        return 1;
    }

    // ��ʼ�������־
    clearerr(file);

    // ��ȡ�ļ�����
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        // �����ȡ������
        printf("%s", buffer);
    }

    // ����ȡ�������Ƿ���ִ���
    if (ferror(file)) {
        perror("ferror detected");
        fclose(file); // ��ʹ�д���ҲӦ�ر��ļ���
        return 1;
    }

    // �ر��ļ�
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1;
    }

    printf("File read successfully.\n");
    return 0;
}
