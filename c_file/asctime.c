#include <stdio.h>
#include <time.h> // ����time.h��ʹ��asctime()����

int main() {
    time_t now;
    struct tm *local;

    // ��ȡ��ǰʱ��
    time(&now);
    // ��ʱ��ת��Ϊtm�ṹ
    local = localtime(&now);

    // ʹ��asctime()��tm�ṹת��Ϊ�ַ���
    char *time_str = asctime(local);

    printf("��ǰʱ�䣨�ַ�����ʽ���� %s\n", time_str);

    return 0;
}
