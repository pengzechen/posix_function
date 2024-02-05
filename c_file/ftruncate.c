#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    const char *filename = "example.txt";
    int fd;
    ssize_t bytes_written;
    char *data = "Hello, World!";
    off_t new_size;

    // ���ļ�������������򴴽�
    fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // д������
    bytes_written = write(fd, data, strlen(data));
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd);
        return EXIT_FAILURE;
    }

    // ��ȡ�ļ���С
    new_size = lseek(fd, 0, SEEK_END);
    if (new_size == -1) {
        perror("Error seeking file");
        close(fd);
        return EXIT_FAILURE;
    }

    // ��ӡԭʼ�ļ���С
    printf("Original file size: %ld bytes\n", new_size);

    // �ض��ļ����´�С
    new_size = 10; // �ض��ļ���10�ֽ�
    if (ftruncate(fd, new_size) == -1) {
        perror("Error truncating file");
        close(fd);
        return EXIT_FAILURE;
    }

    // �ٴλ�ȡ�ļ���С
    new_size = lseek(fd, 0, SEEK_END);
    if (new_size == -1) {
        perror("Error seeking file");
        close(fd);
        return EXIT_FAILURE;
    }

    // ��ӡ�µ��ļ���С
    printf("New file size: %ld bytes\n", new_size);

    // �ر��ļ�
    close(fd);

    // ���������˳�
    return EXIT_SUCCESS;
}
