#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

#include <unistd.h>
#include <string.h>
#include <sys/types.h>   
#include <sys/stat.h>   
#include <fcntl.h>

int main() {

    const char *text = "Hello, World!\n";

    int fd;



    // �����ļ�

    fd = open("example.txt", O_WRONLY | O_CREAT | O_EXCL, 0644);

    if (fd == -1) {

        perror("Error opening file");

        return EXIT_FAILURE;

    }



    // ����׼����ض������Ǵ������ļ�������

    if (dup2(fd, STDOUT_FILENO) == -1) {

        perror("Error duplicating file descriptor");

        close(fd);

        return EXIT_FAILURE;

    }



    // ���ڱ�׼���ָ�����ļ������� fd

    // д�����ݵ��µı�׼��������ļ������� fd ָ����ļ���

    write(STDOUT_FILENO, text, strlen(text));



    // �ر��ļ�������

    close(fd);



    // ���������˳�

    return EXIT_SUCCESS;

}

