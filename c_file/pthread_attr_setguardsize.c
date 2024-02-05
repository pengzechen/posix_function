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
    pthread_t thread;
    pthread_attr_t attr;
    size_t guardsize = 64 * 1024; // 设置栈守护区的大小为64KB

    // 初始化线程属性
    if (pthread_attr_init(&attr) != 0) {
        perror("pthread_attr_init failed");
        return 1;
    }

    // 设置栈守护区的大小
    if (pthread_attr_setguardsize(&attr, guardsize) != 0) {
        perror("pthread_attr_setguardsize failed");
        return 1;
    }

    // 创建线程
    if (pthread_create(&thread, &attr, thread_function, NULL) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // 等待线程完成
    if (pthread_join(thread, NULL) != 0) {
        perror("pthread_join failed");
        return 1;
    }

    // 销毁线程属性
    if (pthread_attr_destroy(&attr) != 0) {
        perror("pthread_attr_destroy failed");
        return 1;
    }

    printf("Main thread completed successfully\n");
    return 0;
}
