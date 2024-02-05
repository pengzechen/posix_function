#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 线程函数，用于演示取消类型
void *thread_function(void *arg) {
    printf("Thread is running...\n");

    // 睡眠一段时间，以便主线程有足够的时间来取消它
    sleep(1);

    printf("Thread is about to be canceled...\n");
    return NULL;
}

int main() {
    pthread_t thread;
    int cancel_type;

    // 创建线程
    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // 获取当前线程的取消类型
    cancel_type = PTHREAD_CANCEL_DEFERRED;
    if (pthread_setcanceltype(cancel_type, NULL) != 0) {
        perror("pthread_setcanceltype failed");
        return 1;
    }

    // 等待线程运行一段时间
    sleep(1);

    // 设置线程的取消类型为异步取消
    cancel_type = PTHREAD_CANCEL_ASYNCHRONOUS;
    if (pthread_setcanceltype(cancel_type, NULL) != 0) {
        perror("pthread_setcanceltype failed");
        return 1;
    }

    // 异步取消线程
    pthread_cancel(thread);

    // 等待线程完成
    if (pthread_join(thread, NULL) != 0) {
        perror("pthread_join failed");
        return 1;
    }

    printf("Main thread completed successfully\n");
    return 0;
}
