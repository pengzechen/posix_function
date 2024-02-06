#include <stdio.h>

#include <time.h>
int main() {

    struct tm timeinfo;

    timeinfo.tm_year = 2023 - 1900; 
    timeinfo.tm_mon = 3 - 1;       
    timeinfo.tm_mday = 13;         
    timeinfo.tm_hour = 10;         
    timeinfo.tm_min = 30;         
    timeinfo.tm_sec = 0;           
    time_t now = mktime(&timeinfo);

    printf("now: %ld\n", now);

    return 0;

}

