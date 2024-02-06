#include <stdio.h>

#include <time.h> 

int main() {

    time_t now;

    now = time(NULL);

    struct tm *local_time;

    local_time = localtime(&now);

    printf("����ʱ���ǣ�%s\n", asctime(local_time));

    return 0;

}

