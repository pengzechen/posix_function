#include <stdio.h>

#include <time.h> // ����time.h��ʹ��gmtime_r()����



int main() {

    const time_t now = time(NULL); // ��ȡ��ǰʱ��

    struct tm * gmt;


    gmt = gmtime_r(&now, gmt);

    if (gmt == NULL) {

        perror("gmtime_r() ʧ��");

        return 1;

    }


    printf("%d-%d-%d %d:%d:%d\n",

           gmt->tm_year + 1900, gmt->tm_mon + 1, gmt->tm_mday,

           gmt->tm_hour, gmt->tm_min, gmt->tm_sec);



    return 0;

}

