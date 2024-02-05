#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // ʹ�� open ��һ���ļ�
    int fd = open("example.txt", O_RDONLY); // "O_RDONLY" ��ʾֻ��ģʽ

    if (fd == -1) {
        perror("open failed");
        return 1; // ���ļ�ʧ��
    }

    // �ļ��������ɹ��򿪣����Խ��ж�ȡ����
    printf("File opened successfully with file descriptor: %d\n", fd);

    // �ر��ļ�
    if (close(fd) != 0) {
        perror("close failed");
        return 1; // �ر��ļ�ʧ��
    }

    printf("File closed successfully.\n");

    // ���������˳�
    return 0;
}
