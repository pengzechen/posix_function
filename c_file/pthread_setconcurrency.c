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
    pthread_t threads[10];
    int i, concurrency;

    // �����߳̿�Ĳ�������Ϊ5
    if (pthread_setconcurrency(5) != 0) {
        perror("pthread_setconcurrency failed");
        return 1;
    }

    // ��������߳�
    for (i = 0; i < 10; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            perror("pthread_create failed");
            return 1;
        }
    }

    // �ȴ������߳����
    for (i = 0; i < 10; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join failed");
            return 1;
        }
    }

    // ��ȡ��ǰ�Ĳ�������
    if (pthread_getconcurrency(&concurrency) != 0) {
        perror("pthread_getconcurrency failed");
        return 1;
    }

    // ��ӡ��������
    printf("Current concurrency level is: %d\n", concurrency);

    return 0;
}
