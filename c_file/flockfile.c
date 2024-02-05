#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h>

#include <sys/stat.h>

#include <errno.h>

int main() {

    const char *filename = "example.txt";

    int fd;

    struct flock lock;



    // ���ļ�

    fd = open(filename, O_WRONLY | O_CREAT, 0644);

    if (fd == -1) {

        perror("Error opening file");

        return EXIT_FAILURE;

    }



    // ��ʼ�����ṹ

    memset(&lock, 0, sizeof(lock));

    lock.l_type = F_WRLCK; // д��

    lock.l_whence = SEEK_SET;

    lock.l_start = 0;

    lock.l_len = 0; // ���������ļ�



    // ��ȡ�ļ��������ĵ�ǰ״̬

    if (fcntl(fd, F_GETLK, &lock) == -1) {

        perror("Error getting lock status");

        close(fd);

        return EXIT_FAILURE;

    }



    // ����ļ��Ѿ�����������ȴ����ͷ�

    if (lock.l_type != F_UNLCK) {

        printf("File is already locked. Waiting for the lock to be released...\n");

        while (fcntl(fd, F_GETLK, &lock) == -1) {

            if (errno != EINTR) {

                perror("Error waiting for lock");

                close(fd);

                return EXIT_FAILURE;

            }

        }

    }



    // �����ļ�������

    flockfile(fd);



    // ��ʱ�ļ��ѱ����������԰�ȫ�ؽ���д����

    printf("File is locked. Writing to file...\n");

    // д�����ݵ��ļ�

    // ...



    // �����ļ�������

    funlockfile(fd);



    // �ر��ļ�������

    if (close(fd) == -1) {

        perror("Error closing file");

        return EXIT_FAILURE;

    }



    // ���������˳�

    return EXIT_SUCCESS;

}

