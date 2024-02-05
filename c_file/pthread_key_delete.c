#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 线程函数，执行一些任务并存储线程 ID
void *thread_function(void *arg) {
    printf("Thread started. Argument: %ld\n", (long)arg);

    // 获取线程特定的数据键
    pthread_key_t key;
    if (pthread_key_create(&key, NULL) != 0) {
        perror("pthread_key_create failed");
        return NULL;
    }

    // 存储线程 ID
    long thread_id = (long)pthread_self();
    if (pthread_setspecific(key, (void *)thread_id) != 0) {
        perror("pthread_setspecific failed");
        return NULL;
    }

    // 模拟一些工作
    for (int i = 0; i < 5; i++) {
        printf("Thread is working...\n");
        sleep(1);
    }

    // 获取并打印线程特定的数据
    long *thread_id_ptr = (long *)pthread_getspecific(key);
    printf("Thread finished working. Thread ID: %ld\n", *thread_id_ptr);

    // 删除数据键
    pthread_key_delete(key);
    return NULL;
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
