#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    const char *filename = "example.txt";
    FILE *file;
    char buffer[11]; // �㹻��� "Hello, World!"
    size_t bytes_read;

    // ���ļ�
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // ��ȡ����
    bytes_read = fread(buffer, 1, sizeof(buffer), file);
    if (bytes_read == 0) {
        perror("Error reading from file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // ��ӡ��ȡ������
    printf("Read: %s\n", buffer);

    // ���ļ�λ��ָ�뵹�ص��ļ���ͷ
    rewind(file);

    // �ٴζ�ȡ��ͬ������
    bytes_read = fread(buffer, 1, sizeof(buffer), file);
    if (bytes_read == 0) {
        perror("Error reading from file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // ��ӡ�ٴζ�ȡ������
    printf("Rewound and read: %s\n", buffer);

    // �ر��ļ�
    fclose(file);

    // ���������˳�
    return EXIT_SUCCESS;
}
