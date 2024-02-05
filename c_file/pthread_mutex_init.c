#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// ����������
pthread_mutex_t mutex;

// ������Դ����
int shared_resource = 0;

// �̺߳��������ӹ�����Դ���ͷŻ�����
void *thread_function(void *arg) {
    printf("Thread started. Argument: %ld\n", (long)arg);

    // ��ʼ��������
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        perror("pthread_mutex_init failed");
        return NULL;
    }

    // ��ȡ������
    if (pthread_mutex_lock(&mutex) != 0) {
        perror("pthread_mutex_lock failed");
        return NULL;
    }

    // ���ӹ�����Դ
    shared_resource++;

    // ��ӡ������Դֵ
    printf("Thread %ld increased shared resource to %d\n", (long)arg, shared_resource);

    // �ͷŻ�����
    if (pthread_mutex_unlock(&mutex) != 0) {
        perror("pthread_mutex_unlock failed");
        return NULL;
    }

    // ���ٻ�����
    if (pthread_mutex_destroy(&mutex) != 0) {
        perror("pthread_mutex_destroy failed");
        return NULL;
    }

    printf("Thread %ld finished working.\n", (long)arg);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    long arg1 = 1, arg2 = 2;

    // �����߳� 1
    if (pthread_create(&thread1, NULL, thread_function, (void *)arg1) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // �����߳� 2
    if (pthread_create(&thread2, NULL, thread_function, (void *)arg2) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // �ȴ��߳����
    if (pthread_join(thread1, NULL) != 0) {
        perror("pthread_join failed");
        return 1;
    }
    if (pthread_join(thread2, NULL) != 0) {
        perror("pthread_join failed");
        return 1;
    }

    printf("Main thread completed successfully.\n");
    return 0;
}