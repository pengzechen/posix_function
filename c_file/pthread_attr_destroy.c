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

    // 设置线程属性，例如设置线程栈大小
    if (pthread_attr_setstacksize(&attr, 1024 * 1024) != 0) {
        perror("pthread_attr_setstacksize failed");
        return 1;
    }

    // 创建线程
    void *result;
    if (pthread_create(&thread, &attr, thread_function, (void *)123) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // 等待线程结束
    if (pthread_join(thread, &result) != 0) {
        perror("pthread_join failed");
        return 1;
    }

    // 销毁线程属性对象
    if (pthread_attr_destroy(&attr) != 0) {
        perror("pthread_attr_destroy failed");
        return 1;
    }

    printf("Thread returned: %s\n", (char *)result);
    return 0;
}
