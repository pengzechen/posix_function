#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// ����һ��ȫ�ֱ�����������fork�¼����޸�
void *global_ptr = NULL;

// ��fork֮ǰ���õĺ���
void before_fork(void) {
    printf("Before fork: Global pointer is %p\n", global_ptr);
    global_ptr = malloc(100); // �����ڴ�
    if (global_ptr) {
        printf("Allocated memory: %p\n", global_ptr);
    } else {
        perror("Memory allocation failed");
    }
}

// �ڸ�����fork֮���ӽ���exit֮ǰ���õĺ���
void after_fork_parent(void) {
    printf("After fork (parent): Global pointer is %p\n", global_ptr);
    free(global_ptr); // �ͷ��ڴ�
    global_ptr = NULL;
}

// ���ӽ���fork֮��exit֮ǰ���õĺ���
void after_fork_child(void) {
    printf("After fork (child): Global pointer is %p\n", global_ptr);
    free(global_ptr); // �ͷ��ڴ�
    global_ptr = NULL;
}

int main() {
    // ע��fork֮ǰ��֮���Լ��ӽ���exit֮ǰ�Ļص�����
    if (pthread_atfork(before_fork, after_fork_parent, after_fork_child) != 0) {
        perror("pthread_atfork registration failed");
        return 1;
    }

    printf("Calling fork()\n");
    pid_t pid = fork(); // ����fork

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child process\n");
        // �ӽ���ִ�еĲ���
    } else {
        printf("Parent process\n");
        // ������ִ�еĲ���
        wait(NULL); // �ȴ��ӽ��̽���
    }

    return 0;
}
