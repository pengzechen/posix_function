#include <stdio.h>

#include <time.h>

#include <unistd.h> // ����setuid()����

#include <stdlib.h>

int main() {

    setenv("TZ", "CST", 1);

    tzset();

    char *timezone_name = tzname[0];

    printf("timezone_name: %s\n", timezone_name);

    return 0;

}

