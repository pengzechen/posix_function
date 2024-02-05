#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *filename = "example.txt";
    int fd;
    FILE *file;
    char *data = "Hello, World!";
    ssize_t bytes_written;

    // ����һ�����ļ���������ļ�
    fd = open(filename, O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    // ���ļ�������ת��Ϊ�ļ���
    file = fdopen(fd, "w");
    if (file == NULL) {
        perror("fdopen failed");
        close(fd); // �ر��ļ�������
        return 1;
    }

    // ʹ���ļ���д������
    bytes_written = fputs(data, file);
    if (bytes_written == -1) {
        perror("fputs failed");
        fclose(file); // �ر��ļ���
        return 1;
    }

    // �ر��ļ���
    if (fclose(file) != 0) {
        perror("fclose failed");
        return 1;
    }

    // �ر��ļ�������
    if (close(fd) == -1) {
        perror("close failed");
        return 1;
    }

    printf("Data written to %s successfully.\n", filename);
    return 0;
}
