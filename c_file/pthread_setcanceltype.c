#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// �̺߳�����������ʾȡ������
void *thread_function(void *arg) {
    printf("Thread is running...\n");

    // ˯��һ��ʱ�䣬�Ա����߳����㹻��ʱ����ȡ����
    sleep(1);

    printf("Thread is about to be canceled...\n");
    return NULL;
}

int main() {
    pthread_t thread;
    int cancel_type;

    // �����߳�
    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // ��ȡ��ǰ�̵߳�ȡ������
    cancel_type = PTHREAD_CANCEL_DEFERRED;
    if (pthread_setcanceltype(cancel_type, NULL) != 0) {
        perror("pthread_setcanceltype failed");
        return 1;
    }

    // �ȴ��߳�����һ��ʱ��
    sleep(1);

    // �����̵߳�ȡ������Ϊ�첽ȡ��
    cancel_type = PTHREAD_CANCEL_ASYNCHRONOUS;
    if (pthread_setcanceltype(cancel_type, NULL) != 0) {
        perror("pthread_setcanceltype failed");
        return 1;
    }

    // �첽ȡ���߳�
    pthread_cancel(thread);

    // �ȴ��߳����
    if (pthread_join(thread, NULL) != 0) {
        perror("pthread_join failed");
        return 1;
    }

    printf("Main thread completed successfully\n");
    return 0;
}
