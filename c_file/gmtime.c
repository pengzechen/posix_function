#include <stdio.h>

#include <time.h> 

int main() {

    time_t now;

    struct tm *gmt;

    time(&now);

    gmt = gmtime(&now);

    if (gmt == NULL) {

        perror("gmtime() ʧ��");

        return 1;

    }

    printf("GMTʱ�䣺%d-%d-%d %d:%d:%d\n",

           gmt->tm_year + 1900, gmt->tm_mon + 1, gmt->tm_mday,

           gmt->tm_hour, gmt->tm_min, gmt->tm_sec);



    return 0;

}

