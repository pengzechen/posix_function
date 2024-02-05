#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h>

#include <sys/stat.h>



int main() {

    // ��һ���ļ�

    int fd = open("example.txt", O_RDONLY);

    if (fd == -1) {

        perror("open() failed");

        return EXIT_FAILURE;

    }

    struct stat file_stat;

    if (fstat(fd, &file_stat) == -1) {

        perror("fstat() failed");

        close(fd); // �ر��ļ�

        return EXIT_FAILURE;

    }


    printf("File size: %ld bytes\n", file_stat.st_size);

    printf("File type: %d\n", file_stat.st_mode);

    printf("Number of hard links: %d\n", file_stat.st_nlink);

    printf("Owner ID: %d\n", file_stat.st_uid);

    printf("Group ID: %d\n", file_stat.st_gid);

    printf("Last access time: %ld seconds since the Epoch\n", file_stat.st_atime);

    printf("Last modification time: %ld seconds since the Epoch\n", file_stat.st_mtime);

    printf("Last status change time: %ld seconds since the Epoch\n", file_stat.st_ctime);

    if (close(fd) == -1) {

        perror("close() failed");

        return EXIT_FAILURE;

    }


    return EXIT_SUCCESS;

}

