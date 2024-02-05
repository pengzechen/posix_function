#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

// #include <unistd.h>
#include <string.h>
// #include <sys/types.h>   
// #include <sys/stat.h>   
#include <fcntl.h>

int main() {

    const char *text = "Hello, World!\n";

    ssize_t bytes_written;



    // ���ļ�������ļ��������򴴽���

    int fd = open("example.txt", O_WRONLY | O_CREAT | O_EXCL, 0644);

    if (fd == -1) {

        perror("Error opening file");

        return EXIT_FAILURE;

    }



    // д�����ݵ��ļ�

    bytes_written = write(fd, text, strlen(text));

    if (bytes_written == -1) {

        perror("Error writing to file");

        close(fd);

        return EXIT_FAILURE;

    }



    // ȷ��д����ֽ�����Ԥ�����

    if (bytes_written != strlen(text)) {

        fprintf(stderr, "Write failed: only %ld bytes were written\n", bytes_written);

        close(fd);

        return EXIT_FAILURE;

    }



    // �ر��ļ�������

    close(fd);



    // ���������˳�

    return EXIT_SUCCESS;

}

