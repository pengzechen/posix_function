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

    // �����߳����ԣ����������߳�ջ��С
    if (pthread_attr_setstacksize(&attr, 1024 * 1024) != 0) {
        perror("pthread_attr_setstacksize failed");
        return 1;
    }

    // �����߳�
    void *result;
    if (pthread_create(&thread, &attr, thread_function, (void *)123) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // �ȴ��߳̽���
    if (pthread_join(thread, &result) != 0) {
        perror("pthread_join failed");
        return 1;
    }

    // �����߳����Զ���
    if (pthread_attr_destroy(&attr) != 0) {
        perror("pthread_attr_destroy failed");
        return 1;
    }

    printf("Thread returned: %s\n", (char *)result);
    return 0;
}
