#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>
#include <string.h>
#include <sys/types.h>   
#include <sys/stat.h>   
#include <fcntl.h>

int main() {

    const char *filename = "example.txt";

    mode_t mode = S_IRUSR | S_IWUSR; // �����ļ�Ȩ��Ϊ�û���д



    // ʹ�� creat() ��������ļ�

    int fd = creat(filename, mode);

    if (fd == -1) {

        perror("creat() failed");

        return EXIT_FAILURE;

    }



    // д��һ���ı����ļ�

    const char *text = "Hello, World!\n";

    ssize_t bytes_written = write(fd, text, strlen(text));

    if (bytes_written == -1) {

        perror("write() failed");

        close(fd); // �ر��ļ�

        return EXIT_FAILURE;

    }



    // �ر��ļ�

    if (close(fd) == -1) {

        perror("close() failed");

        return EXIT_FAILURE;

    }



    // ���������˳�

    return EXIT_SUCCESS;

}

