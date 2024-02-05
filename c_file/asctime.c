#include <stdio.h>

#include <time.h>

int main() {

    time_t now;

    struct tm *local;

    time(&now);

    local = localtime(&now);

    char *time_str = asctime(local);

    printf("当前时间（字符串形式）： %s\n", time_str);

    return 0;

}

