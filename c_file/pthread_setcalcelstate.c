#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 线程函数，用于演示取消状态
void *thread_function(void *arg) {
    printf("Thread is running...\n");

    // 睡眠一段时间，以便主线程有足够的时间来取消它
    sleep(1);

    printf("Thread is about to be canceled...\n");
    return NULL;
}

int main() {
    pthread_t thread;
    int cancel_state;

    // 创建线程
    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // 获取当前线程的取消状态
    cancel_state = PTHREAD_CANCEL_ENABLE;
    if (pthread_setcancelstate(cancel_state, NULL) != 0) {
        perror("pthread_setcancelstate failed");
        return 1;
    }

    // 等待线程运行一段时间
    sleep(1);

    // 设置线程的取消状态为取消 enable 状态
    cancel_state = PTHREAD_CANCEL_DISABLE;
    if (pthread_setcancelstate(cancel_state, NULL) != 0) {
        perror("pthread_setcancelstate failed");
        return 1;
    }

    // 取消线程
    if (pthread_cancel(thread) != 0) {
        perror("pthread_cancel failed");
        return 1;
    }

    // 等待线程完成
    if (pthread_join(thread, NULL) != 0) {
        perror("pthread_join failed");
        return 1;
    }

    printf("Main thread completed successfully\n");
    return 0;
}
