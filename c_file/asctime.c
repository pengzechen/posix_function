#include <stdio.h>

#include <time.h>

int main() {

    time_t now;

    struct tm *local;

    time(&now);

    local = localtime(&now);

    char *time_str = asctime(local);

    printf("time_str: %s\n", time_str);

    return 0;
}

