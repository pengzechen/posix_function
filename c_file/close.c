#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h>

#include <string.h>

int main() {

    const char *filename = "example.txt";

    int fd;

    ssize_t bytes_written;

    char *data = "Hello, World!";



    // ���ļ�������ļ��������򴴽���

    fd = open(filename, O_WRONLY | O_CREAT | O_EXCL, 0644);

    if (fd == -1) {

        perror("open failed");

        return 1;

    }



    // д�����ݵ��ļ�

    bytes_written = write(fd, data, strlen(data));

    if (bytes_written == -1) {

        perror("write failed");

        close(fd); // ��ʹд��ʧ�ܣ�ҲӦ�ر��ļ�������

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

