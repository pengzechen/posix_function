#include <stdio.h>
#include <time.h> // ����time.h��ʹ��asctime_r()����
#include <stdlib.h>#include <time.h>
int main() {
    time_t now;
    struct tm local;
    char time_buffer[26]; // �㹻���asctime_r()�����

    // ��ȡ��ǰʱ��
    time(&now);
    // ��ʱ��ת��Ϊtm�ṹ
    local = *localtime(&now);

    // ʹ��asctime_r()��tm�ṹת��Ϊ�ַ��������洢���û��ṩ�Ļ�������
    if (asctime_r(&local, time_buffer) == NULL) {
        perror("asctime_r");
        return 1;
    }

    printf("��ǰʱ�䣨�ַ�����ʽ���� %s\n", time_buffer);

    return 0;
}
