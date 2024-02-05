#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 定义一个全局变量，用于在fork事件中修改
void *global_ptr = NULL;

// 在fork之前调用的函数
void before_fork(void) {
    printf("Before fork: Global pointer is %p\n", global_ptr);
    global_ptr = malloc(100); // 分配内存
    if (global_ptr) {
        printf("Allocated memory: %p\n", global_ptr);
    } else {
        perror("Memory allocation failed");
    }
}

// 在父进程fork之后、子进程exit之前调用的函数
void after_fork_parent(void) {
    printf("After fork (parent): Global pointer is %p\n", global_ptr);
    free(global_ptr); // 释放内存
    global_ptr = NULL;
}

// 在子进程fork之后、exit之前调用的函数
void after_fork_child(void) {
    printf("After fork (child): Global pointer is %p\n", global_ptr);
    free(global_ptr); // 释放内存
    global_ptr = NULL;
}

int main() {
    // 注册fork之前、之后以及子进程exit之前的回调函数
    if (pthread_atfork(before_fork, after_fork_parent, after_fork_child) != 0) {
        perror("pthread_atfork registration failed");
        return 1;
    }

    printf("Calling fork()\n");
    pid_t pid = fork(); // 调用fork

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child process\n");
        // 子进程执行的操作
    } else {
        printf("Parent process\n");
        // 父进程执行的操作
        wait(NULL); // 等待子进程结束
    }

    return 0;
}
