#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// �̺߳�����ִ��һЩ����Ȼ���˳�
void *thread_function(void *arg) {
    printf("Thread started. Argument: %ld\n", (long)arg);

    // ģ��һЩ����
    for (int i = 0; i < 5; i++) {
        printf("Thread is working...\n");
        sleep(1);
    }

    printf("Thread is finished working.\n");
    return NULL;
}

int main() {
    pthread_t thread;
    long arg = 42;

    // �����߳�
    if (pthread_create(&thread, NULL, thread_function, (void *)arg) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // �ȴ��߳����
    if (pthread_join(thread, NULL) != 0) {
        perror("pthread_join failed");
        return 1;
    }

    printf("Main thread completed successfully.\n");
    return 0;
}