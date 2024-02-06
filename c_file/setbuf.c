#include <stdio.h>

#include <unistd.h>

int main() {

    setbuf(stdout, NULL);


    printf("This is the first line.\n");

    fflush(stdout); 

    sleep(1); 

    setbuf(stdout, (char *)NULL);


    printf("This is the second line.\n");

    fflush(stdout); 


    return 0;

}

