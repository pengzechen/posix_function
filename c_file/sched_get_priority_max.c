#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sched.h>



int main() {

    int priority_max = sched_get_priority_max(SCHED_FIFO);

    if (priority_max == -1) {

        perror("sched_get_priority_max() failed");

        return EXIT_FAILURE;

    }


    printf("The maximum priority available for SCHED_FIFO is: %d\n", priority_max);

    return EXIT_SUCCESS;

}

