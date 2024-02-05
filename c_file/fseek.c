#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    long fileSize;
    char *data = "Hello, World!";
    size_t bytesWritten, bytesRead;

    // ���ļ�
    file = fopen(filename, "w+");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // ��ȡ�ļ���С
    fileSize = lseek(fileno(file), 0, SEEK_END);
    printf("Initial file size: %ld\n", fileSize);

    // ���ļ�ָ���ƶ����ļ�ĩβ
    if (ftruncate(fileno(file), fileSize + strlen(data) + 1) == -1) {
        perror("Error truncating file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // д������
    bytesWritten = fwrite(data, 1, strlen(data) + 1, file);
    if (bytesWritten != strlen(data) + 1) {
        perror("Error writing to file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // ���ļ�ָ���ƶ����ļ���ͷ
    if (fseek(file, 0, SEEK_SET) == -1) {
        perror("Error seeking to file beginning");
        fclose(file);
        return EXIT_FAILURE;
    }

    // ��ȡ����
    bytesRead = fread(data, 1, strlen(data) + 1, file);
    if (bytesRead != strlen(data) + 1) {
        perror("Error reading from file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // ��ӡ��ȡ������
    printf("Read data: %s\n", data);

    // �ر��ļ�
    fclose(file);

    // ���������˳�
    return EXIT_SUCCESS;
}
