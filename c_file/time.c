#include <stdio.h>

#include <time.h>



int main() {

    time_t now;

    now = time(NULL);

    struct tm *local;

    local = localtime(&now);


    printf("��ǰ�����ں�ʱ���ǣ�%d-%d-%d %d:%d:%d\n",

           local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,

           local->tm_hour, local->tm_min, local->tm_sec);



    return 0;

}

