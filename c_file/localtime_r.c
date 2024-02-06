#include <stdio.h>

#include <time.h> 
#include <stdlib.h>

int main() {

    time_t now;

    now = time(NULL);

    struct tm *local_time;

    local_time = (struct tm *)malloc(sizeof(struct tm));

    if (local_time == NULL) {

        perror("local_time  error");

        return 1;

    }

    local_time = localtime_r(&now, local_time);


    if (local_time == NULL) {

        perror("localtime_r() error");

        free(local_time);

        return 1;

    }


    printf("time %s\n", asctime(local_time));

    free(local_time);

    return 0;

}

