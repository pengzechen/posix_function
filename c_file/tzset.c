#include <stdio.h>
#include <time.h>
#include <unistd.h> // ����setuid()����

int main() {
    // ���õ�ǰʱ��Ϊ�й���׼ʱ�䣨CST��
    setenv("TZ", "CST", 1);
    tzset();

    // ��ȡ��ǰʱ��������
    char *timezone_name = tzname[0];

    // ��ӡ��ǰʱ��������
    printf("��ǰʱ�����ƣ�%s\n", timezone_name);

    return 0;
}
