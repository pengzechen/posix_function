#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // ָ��Ҫ������Ŀ¼����
    const char *directory_name = "demo_directory";

    // ʹ�� mkdir() ��������Ŀ¼
    if (mkdir(directory_name, 0755) == 0) {
        // Ŀ¼�����ɹ�
        printf("Directory '%s' created successfully.\n", directory_name);
    } else {
        // Ŀ¼����ʧ��
        perror("mkdir() failed");
    }

    // ���������˳�
    return EXIT_SUCCESS;
}
