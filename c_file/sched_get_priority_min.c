#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sched.h>



int main() {


    int priority_min = sched_get_priority_min(SCHED_FIFO);

    if (priority_min == -1) {

        perror("sched_get_priority_min() failed");

        return EXIT_FAILURE;

    }


    printf("The minimum priority available for SCHED_FIFO is: %d\n", priority_min);


    return EXIT_SUCCESS;

}

