#include <stdio.h>
#include <time.h> // ����time.h��ʹ��localtime()����

int main() {
    // ��ȡ��ǰʱ���time_tֵ
    time_t now;
    now = time(NULL);

    // ��time_tֵת��Ϊ����ʱ���struct tmָ��
    struct tm *local_time;
    local_time = localtime(&now);

    // ��ӡ����ʱ��
    printf("����ʱ���ǣ�%s\n", asctime(local_time));

    return 0;
}
