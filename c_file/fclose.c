#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    const char *filename = "example.txt";
    char *data = "Hello, World!";

    // ���ļ�
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("fopen failed");
        return 1;
    }

    // д�����ݵ��ļ�
    if (fputs(data, file) == EOF) {
        perror("fputs failed");
        fclose(file); // ��ʹд��ʧ�ܣ�ҲӦ�ر��ļ���
        return 1;
    }

    // �ر��ļ���
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1;
    }

    printf("Data written to %s successfully.\n", filename);
    return 0;
}
