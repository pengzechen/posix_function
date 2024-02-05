#include <stdio.h>

#include <time.h> // ����time.h��ʹ��localtime_r()����

#include <stdlib.h>

int main() {

    time_t now;

    now = time(NULL);

    struct tm *local_time;

    local_time = (struct tm *)malloc(sizeof(struct tm));

    if (local_time == NULL) {

        perror("�ڴ����ʧ��");

        return 1;

    }


    local_time = localtime_r(&now, local_time);


    if (local_time == NULL) {

        perror("localtime_r()ת��ʧ��");

        free(local_time);

        return 1;

    }


    printf("����ʱ���ǣ�%s\n", asctime(local_time));

    free(local_time);

    return 0;

}

