#include <stdio.h>

#include <time.h> 

int main() {

    struct tm specified_time = {0}; 
    double time_difference; 

    specified_time.tm_year = 2023 - 1900; 
    specified_time.tm_mon = 5 - 1; 
    specified_time.tm_mday = 15;

    specified_time.tm_hour = 10;

    specified_time.tm_min = 30;

    specified_time.tm_sec = 0;

    time_t specified_timestamp = mktime(&specified_time);



    if (specified_timestamp == -1) {

        fprintf(stderr, "error\n");

        return 1;

    }

    time_t current_timestamp = time(NULL);

    time_difference = difftime(current_timestamp, specified_timestamp);

    printf("time difference%f\n", time_difference);

    return 0;

}

