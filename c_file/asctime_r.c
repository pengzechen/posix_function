#include <stdio.h>

#include <time.h> 

#include <stdlib.h>

#include <time.h>

int main() {

    time_t now;

    struct tm local;

    char time_buffer[26]; 

    time(&now);

    local = *localtime(&now);

    if (asctime_r(&local, time_buffer) == NULL) {

        perror("asctime_r");

        return 1;

    }

    printf("��ǰʱ�䣨�ַ�����ʽ���� %s\n", time_buffer);

    return 0;

}

