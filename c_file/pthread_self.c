#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// �̺߳�������ӡ��ǰ�̵߳ı�ʶ��
void *thread_function(void *arg) {
    printf("Thread ID: %lu\n", (unsigned long)pthread_self());
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // �����߳� 1
    if (pthread_create(&thread1, NULL, thread_function, NULL) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // �����߳� 2
    if (pthread_create(&thread2, NULL, thread_function, NULL) != 0) {
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
