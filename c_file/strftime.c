#include <stdio.h>

#include <time.h>



int main() {

    time_t now;

    struct tm *local;



    time(&now); 

    local = localtime(&now); 

    char time_buffer[20];

    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", local);

    printf("��ǰʱ���ǣ�%s\n", time_buffer);

    return 0;

}

