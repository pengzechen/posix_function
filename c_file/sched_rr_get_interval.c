#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sched.h>

#include <sys/times.h>



int main() {


    struct sched_param param;

    pid_t policy = getpid();



    if (sched_getparam(0, &param) == -1 || sched_getscheduler(policy) == -1) {

        perror("sched_getparam or sched_getscheduler failed");

        return EXIT_FAILURE;

    }



    if (policy != SCHED_RR) {

        fprintf(stderr, "Process is not running with SCHED_RR policy.\n");

        return EXIT_FAILURE;

    }


    struct timespec ts;

    if (sched_rr_get_interval(0, &ts) == -1) {

        perror("sched_rr_get_interval failed");

        return EXIT_FAILURE;

    }

    long interval_ms = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;

    printf("The timer interval for SCHED_RR is: %ld milliseconds\n", interval_ms);


    return EXIT_SUCCESS;

}

