#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// �̺߳������������߳���ִ��
void *thread_function(void *arg) {
    printf("Hello from the thread! arg = %ld\n", (long)arg);
    return NULL;
}

int main() {
    pthread_t thread; // �̱߳�ʶ��
    pthread_attr_t attr; // �߳����Զ���

    // �����߳����Զ���
    if (pthread_attr_init(&attr) != 0) {
        perror("pthread_attr_init failed");
        return 1;
    }

    // �����߳�Ϊ����״̬
    int detachstate;
    if (pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED) != 0) {
        perror("pthread_attr_setdetachstate failed");
        return 1;
    }

    // ��ȡ�̵߳ķ���״̬
    if (pthread_attr_getdetachstate(&attr, &detachstate) != 0) {
        perror("pthread_attr_getdetachstate failed");
        return 1;
    }

    // �����߳�
    void *result;
    if (pthread_create(&thread, &attr, thread_function, (void *)123) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // �ȴ��߳̽������ڱ����в���Ҫ����Ϊ�߳��Ƿ���ģ�
    // if (pthread_join(thread, &result) != 0) {
    //     perror("pthread_join failed");
    //     return 1;
    // }

    // �����߳����Զ���
    if (pthread_attr_destroy(&attr) != 0) {
        perror("pthread_attr_destroy failed");
        return 1;
    }

    printf("Thread detach state: %d\n", detachstate);
    return 0;
}
