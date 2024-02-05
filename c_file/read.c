#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // ����һ���ַ��������洢�û�������ַ���
    char buffer[100];

    // ʹ�� read ��ȡ��׼������ַ���
    ssize_t bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1); // ��һ��λ�ø� '\0'

    if (bytesRead == -1) {
        perror("read failed");
        exit(EXIT_FAILURE); // ��ȡʧ��
    }

    // ȷ���ַ����� null �ַ���β
    buffer[bytesRead] = '\0';

    // ��ӡ�û�������ַ���
    printf("You entered: %s\n", buffer);

    // ���������˳�
    return 0;
}
