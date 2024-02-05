#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// ����������
pthread_mutex_t mutex;

// ���������Զ���
pthread_mutexattr_t mutexattr;

// ������Դ����
int shared_resource = 0;

// �̺߳��������ӹ�����Դ���ͷŻ�����
void *thread_function(void *arg) {
    long thread_id = (long)arg;
    printf("Thread %ld started\n", thread_id);

    // ��ʼ�����������Զ���
    if (pthread_mutexattr_init(&mutexattr) != 0) {
        perror("pthread_mutexattr_init failed");
        return NULL;
    }

    // ���û��������ԣ��˴���ΪĬ�����ԣ�
    if (pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_DEFAULT) != 0) {
        perror("pthread_mutexattr_settype failed");
        return NULL;
    }

    // ��ʼ��������
    if (pthread_mutex_init(&mutex, &mutexattr) != 0) {
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
    printf("Thread %ld increased shared resource to %d\n", thread_id, shared_resource);

    // �ͷŻ�����
    if (pthread_mutex_unlock(&mutex) != 0) {
        perror("pthread_mutex_unlock failed");
        return NULL;
    }

    // ���ٻ��������Զ���
    if (pthread_mutexattr_destroy(&mutexattr) != 0) {
        perror("pthread_mutexattr_destroy failed");
        return NULL;
    }

    // ���ٻ�����
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

    printf("Main thread completed successfully\n");
    return 0;
}
