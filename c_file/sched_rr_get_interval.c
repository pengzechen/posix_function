#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sched.h>

#include <sys/times.h>



int main() {

    // 获取当前进程的调度参数

    struct sched_param param;

    pid_t policy = getpid();



    // 获取调度策略和参数

    if (sched_getparam(0, &param) == -1 || sched_getscheduler(policy) == -1) {

        perror("sched_getparam or sched_getscheduler failed");

        return EXIT_FAILURE;

    }



    // 检查进程是否已经设置为实时调度策略

    if (policy != SCHED_RR) {

        fprintf(stderr, "Process is not running with SCHED_RR policy.\n");

        return EXIT_FAILURE;

    }



    // 获取定时器间隔

    struct timespec ts;

    if (sched_rr_get_interval(0, &ts) == -1) {

        perror("sched_rr_get_interval failed");

        return EXIT_FAILURE;

    }



    // 将定时器间隔转换为毫秒

    long interval_ms = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;



    // 打印定时器间隔

    printf("The timer interval for SCHED_RR is: %ld milliseconds\n", interval_ms);



    return EXIT_SUCCESS;

}

