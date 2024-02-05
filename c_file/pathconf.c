#include <unistd.h>

#include <stdio.h>

#include <stdlib.h>

int main() {

    // ��ȡ·����������

    long path_max = pathconf(".", _PC_PATH_MAX);

    if (path_max == -1) {

        perror("pathconf() failed");

        return EXIT_FAILURE;

    }



    // ��ӡ·����������

    printf("The maximum path length is: %ld\n", path_max);



    // ���������˳�

    return EXIT_SUCCESS;

}

