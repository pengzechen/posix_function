#include <stdio.h>

#include <time.h> 

int main() {

    char *current_time = ctime(NULL);

    if (current_time != NULL) {

        printf("current time: %s", current_time);

    } else {

        fprintf(stderr, "error\n");

    }

    return 0;

}

