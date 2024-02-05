#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main() {
    // 获取系统中可用的最低调度优先级
    int priority_min = sched_get_priority_min(SCHED_FIFO);
    if (priority_min == -1) {
        perror("sched_get_priority_min() failed");
        return EXIT_FAILURE;
    }

    // 打印最低调度优先级
    printf("The minimum priority available for SCHED_FIFO is: %d\n", priority_min);

    return EXIT_SUCCESS;
}
