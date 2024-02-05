#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    char buffer[1024];
    size_t bytes_written;

    // ���ļ�
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("fopen failed");
        return 1;
    }

    // д���ļ�����
    snprintf(buffer, sizeof(buffer), "Hello, World!");
    bytes_written = fputs(buffer, file);
    if (bytes_written == -1) {
        perror("fputs failed");
        fclose(file); // �ر��ļ���
        return 1;
    }

    // ˢ���������ȷ�����ݱ�д���ļ�
    fflush(file);

    // д������ļ�����
    snprintf(buffer, sizeof(buffer), "This is another line.");
    bytes_written = fputs(buffer, file);
    if (bytes_written == -1) {
        perror("fputs failed");
        fclose(file); // �ر��ļ���
        return 1;
    }

    // �ٴ�ˢ���������ȷ���������ݱ�д���ļ�
    fflush(file);

    // �ر��ļ�
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1;
    }

    printf("Data written to %s successfully.\n", filename);
    return 0;
}
