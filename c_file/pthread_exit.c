#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 线程函数，执行一些任务然后退出
void *thread_function(void *arg) {
    printf("Thread started. Argument: %ld\n", (long)arg);

    // 模拟一些工作
    for (int i = 0; i < 5; i++) {
        printf("Thread is working...\n");
        sleep(1);
    }

    // 通知主线程线程即将退出
    printf("Thread is about to exit.\n");

    // 退出线程
    pthread_exit(NULL);
    return NULL; // 这个返回值不会被使用
}

int main() {
    pthread_t thread;
    long arg = 42;

    // 创建线程
    if (pthread_create(&thread, NULL, thread_function, (void *)arg) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // 等待线程完成
    if (pthread_join(thread, NULL) != 0) {
        perror("pthread_join failed");
        return 1;
    }

    printf("Main thread completed successfully.\n");
    return 0;
}
