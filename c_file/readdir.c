#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // ָ��Ҫ�򿪵�Ŀ¼����
    const char *directory_name = "demo_directory";

    // ��Ŀ¼
    DIR *dir;
    if ((dir = opendir(directory_name)) == NULL) {
        perror("opendir() failed");
        return EXIT_FAILURE;
    }

    // ��ȡĿ¼����
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // ��ӡĿ¼�������
        printf("%s\n", entry->d_name);
    }

    // �ر�Ŀ¼
    if (closedir(dir) == -1) {
        perror("closedir() failed");
        return EXIT_FAILURE;
    }

    // ���������˳�
    return EXIT_SUCCESS;
}
