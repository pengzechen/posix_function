#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 互斥锁变量
pthread_mutex_t mutex;

// 互斥锁属性对象
pthread_mutexattr_t mutexattr;

// 共享资源变量
int shared_resource = 0;

// 线程函数，增加共享资源并释放互斥锁
void *thread_function(void *arg) {
    long thread_id = (long)arg;
    printf("Thread %ld started\n", thread_id);

    // 初始化互斥锁属性对象
    if (pthread_mutexattr_init(&mutexattr) != 0) {
        perror("pthread_mutexattr_init failed");
        return NULL;
    }

    // 设置互斥锁属性（此处设为默认属性）
    if (pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_DEFAULT) != 0) {
        perror("pthread_mutexattr_settype failed");
        return NULL;
    }

    // 初始化互斥锁
    if (pthread_mutex_init(&mutex, &mutexattr) != 0) {
        perror("pthread_mutex_init failed");
        return NULL;
    }

    // 获取互斥锁
    if (pthread_mutex_lock(&mutex) != 0) {
        perror("pthread_mutex_lock failed");
        return NULL;
    }

    // 增加共享资源
    shared_resource++;

    // 打印共享资源值
    printf("Thread %ld increased shared resource to %d\n", thread_id, shared_resource);

    // 释放互斥锁
    if (pthread_mutex_unlock(&mutex) != 0) {
        perror("pthread_mutex_unlock failed");
        return NULL;
    }

    // 销毁互斥锁属性对象
    if (pthread_mutexattr_destroy(&mutexattr) != 0) {
        perror("pthread_mutexattr_destroy failed");
        return NULL;
    }

    // 销毁互斥锁
    if (pthread_mutex_destroy(&mutex) != 0) {
        perror("pthread_mutex_destroy failed");
        return NULL;
    }

    printf("Thread %ld finished working\n", thread_id);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    long arg1 = 1, arg2 = 2;

    // 创建线程 1
    if (pthread_create(&thread1, NULL, thread_function, (void *)arg1) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // 创建线程 2
    if (pthread_create(&thread2, NULL, thread_function, (void *)arg2) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // 等待线程完成
    if (pthread_join(thread1, NULL) != 0) {
        perror("pthread_join failed");
        return 1;
    }
    if (pthread_join(thread2, NULL) != 0) {
        perror("pthread_join failed");
        return 1;
    }

    printf("Main thread completed successfully\n");
    return 0;
}
