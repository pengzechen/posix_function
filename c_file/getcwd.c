#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // ��ȡ��ǰ����Ŀ¼
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() failed");
        return EXIT_FAILURE;
    }

    // ��ӡ��ǰ����Ŀ¼
    printf("Current working directory is: %s\n", cwd);

    // ���������˳�
    return EXIT_SUCCESS;
}
