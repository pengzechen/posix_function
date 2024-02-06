#include <stdio.h>

#include <time.h>



int main() {

    char *timezone_name = tzname[0];

    printf("timezone_name %s\n", timezone_name);

    return 0;

}

