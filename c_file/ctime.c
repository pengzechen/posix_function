#include <stdio.h>
#include <time.h> // ����time.h��ʹ��ctime()����

int main() {
    char *current_time = ctime(NULL);

    if (current_time != NULL) {
        // ��ӡ��ǰʱ������ں�ʱ��
        printf("��ǰʱ�䣺 %s", current_time);
    } else {
        fprintf(stderr, "��ȡ��ǰʱ��ʧ��\n");
    }

    return 0;
}
