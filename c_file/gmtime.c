#include <stdio.h>
#include <time.h> // ����time.h��ʹ��gmtime()����

int main() {
    time_t now;
    struct tm *gmt;

    // ��ȡ��ǰʱ��
    time(&now);

    // ����ǰʱ��ת��ΪGMTʱ��
    gmt = gmtime(&now);

    if (gmt == NULL) {
        perror("gmtime() ʧ��");
        return 1;
    }

    // ��ӡGMTʱ��
    printf("GMTʱ�䣺%d-%d-%d %d:%d:%d\n",
           gmt->tm_year + 1900, gmt->tm_mon + 1, gmt->tm_mday,
           gmt->tm_hour, gmt->tm_min, gmt->tm_sec);

    return 0;
}
