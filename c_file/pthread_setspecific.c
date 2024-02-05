#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 线程特定的数据键
pthread_key_t key;

// 线程函数，用于演示 pthread_setspecific()
void *thread_function(void *arg) {
    int *value = (int *)arg;

    // 存储特定的值到线程特定的数据槽中
    if (pthread_setspecific(key, value) != 0) {
        perror("pthread_setspecific failed");
        return NULL;
    }

    // 检索线程特定的数据槽中的值
    int *retrieved_value = (int *)pthread_getspecific(key);
    if (retrieved_value == NULL) {
        perror("pthread_getspecific failed");
        return NULL;
    }

    printf("Thread ID: %lu, Retrieved value: %d\n", (unsigned long)pthread_self(), *retrieved_value);
    return NULL;
}

int main() {
    int value1 = 1, value2 = 2, value3 = 3;
    pthread_t thread1, thread2, thread3;

    // 创建线程特定的数据键
    if (pthread_key_create(&key, NULL) != 0) {
        perror("pthread_key_create failed");
        return 1;
    }

    // 创建线程 1
    if (pthread_create(&thread1, NULL, thread_function, (void *)&value1) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // 创建线程 2
    if (pthread_create(&thread2, NULL, thread_function, (void *)&value2) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // 创建线程 3
    if (pthread_create(&thread3, NULL, thread_function, (void *)&value3) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // 等待所有线程完成
    if (pthread_join(thread1, NULL) != 0) {
        perror("pthread_join failed");
        return 1;
    }
    if (pthread_join(thread2, NULL) != 0) {
        perror("pthread_join failed");
        return 1;
    }
    if (pthread_join(thread3, NULL) != 0) {
        perror("pthread_join failed");
        return 1;
    }

    // 删除线程特定的数据键
    if (pthread_key_delete(key) != 0) {
        perror("pthread_key_delete failed");
        return 1;
    }

    printf("Main thread completed successfully\n");
    return 0;
}
