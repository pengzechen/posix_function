#include <stdio.h>
#include <time.h>

int main() {
    // ��ȡ��ǰʱ��������
    char *timezone_name = tzname[0];

    // ��ӡ��ǰʱ��������
    printf("��ǰʱ�����ƣ�%s\n", timezone_name);

    return 0;
}
