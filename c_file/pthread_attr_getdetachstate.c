#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 线程函数，将在新线程中执行
void *thread_function(void *arg) {
    printf("Hello from the thread! arg = %ld\n", (long)arg);
    return NULL;
}

int main() {
    pthread_t thread; // 线程标识符
    pthread_attr_t attr; // 线程属性对象

    // 创建线程属性对象
    if (pthread_attr_init(&attr) != 0) {
        perror("pthread_attr_init failed");
        return 1;
    }

    // 设置线程为分离状态
    int detachstate;
    if (pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED) != 0) {
        perror("pthread_attr_setdetachstate failed");
        return 1;
    }

    // 获取线程的分离状态
    if (pthread_attr_getdetachstate(&attr, &detachstate) != 0) {
        perror("pthread_attr_getdetachstate failed");
        return 1;
    }

    // 创建线程
    void *result;
    if (pthread_create(&thread, &attr, thread_function, (void *)123) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // 等待线程结束（在本例中不需要，因为线程是分离的）
    // if (pthread_join(thread, &result) != 0) {
    //     perror("pthread_join failed");
    //     return 1;
    // }

    // 销毁线程属性对象
    if (pthread_attr_destroy(&attr) != 0) {
        perror("pthread_attr_destroy failed");
        return 1;
    }

    printf("Thread detach state: %d\n", detachstate);
    return 0;
}
