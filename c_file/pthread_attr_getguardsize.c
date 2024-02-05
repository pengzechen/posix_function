#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// �̺߳���
void *thread_function(void *arg) {
    printf("Thread started\n");
    // �����������̵߳�ִ�д���
    printf("Thread finishing\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_attr_t attr;
    size_t guardsize;

    // ��ʼ���߳�����
    if (pthread_attr_init(&attr) != 0) {
        perror("pthread_attr_init failed");
        return 1;
    }

    // ��ȡջ�ػ����ĳߴ�
    if (pthread_attr_getguardsize(&attr, &guardsize) != 0) {
        perror("pthread_attr_getguardsize failed");
        return 1;
    }

    // ��ӡջ�ػ����ĳߴ�
    printf("Guard size: %zu bytes\n", guardsize);

    // �����߳�ջ�Ĵ�С�������Ҫ��
    // ���磬����ջ��СΪ1MB
    size_t stacksize = 1024 * 1024;
    if (pthread_attr_setstacksize(&attr, stacksize) != 0) {
        perror("pthread_attr_setstacksize failed");
        return 1;
    }

    // �����߳�
    if (pthread_create(&thread, &attr, thread_function, NULL) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // �ȴ��߳����
    if (pthread_join(thread, NULL) != 0) {
        perror("pthread_join failed");
        return 1;
    }

    // �����߳�����
    if (pthread_attr_destroy(&attr) != 0) {
        perror("pthread_attr_destroy failed");
        return 1;
    }

    printf("Main thread completed successfully\n");
    return 0;
}
