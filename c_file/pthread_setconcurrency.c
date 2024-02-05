#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 线程函数
void *thread_function(void *arg) {
    printf("Thread started\n");
    // 这里可以添加线程的执行代码
    printf("Thread finishing\n");
    return NULL;
}

int main() {
    pthread_t threads[10];
    int i, concurrency;

    // 设置线程库的并发级别为5
    if (pthread_setconcurrency(5) != 0) {
        perror("pthread_setconcurrency failed");
        return 1;
    }

    // 创建多个线程
    for (i = 0; i < 10; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            perror("pthread_create failed");
            return 1;
        }
    }

    // 等待所有线程完成
    for (i = 0; i < 10; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join failed");
            return 1;
        }
    }

    // 获取当前的并发级别
    if (pthread_getconcurrency(&concurrency) != 0) {
        perror("pthread_getconcurrency failed");
        return 1;
    }

    // 打印并发级别
    printf("Current concurrency level is: %d\n", concurrency);

    return 0;
}
