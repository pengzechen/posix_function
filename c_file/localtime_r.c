#include <stdio.h>
#include <time.h> // ����time.h��ʹ��localtime_r()����

int main() {
    // ��ȡ��ǰʱ���time_tֵ
    time_t now;
    now = time(NULL);

    // �����ڴ�����struct tm�ṹ��
    struct tm *local_time;
    local_time = (struct tm *)malloc(sizeof(struct tm));
    if (local_time == NULL) {
        perror("�ڴ����ʧ��");
        return 1;
    }

    // ��time_tֵת��Ϊ����ʱ���struct tmָ��
    local_time = localtime_r(&now, local_time);

    // ���ת���Ƿ�ɹ�
    if (local_time == NULL) {
        perror("localtime_r()ת��ʧ��");
        free(local_time);
        return 1;
    }

    // ��ӡ����ʱ��
    printf("����ʱ���ǣ�%s\n", asctime(local_time));

    // �ͷŷ�����ڴ�
    free(local_time);

    return 0;
}
