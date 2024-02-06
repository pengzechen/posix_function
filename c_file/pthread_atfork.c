#include <stdio.h>

#include <pthread.h>

#include <unistd.h>

#include <stdlib.h>

#include <sys/types.h>   
#include <sys/wait.h>


void *global_ptr = NULL;



void before_fork(void) {

    printf("Before fork: Global pointer is %p\n", global_ptr);

    global_ptr = malloc(100);

    if (global_ptr) {

        printf("Allocated memory: %p\n", global_ptr);

    } else {

        perror("Memory allocation failed");

    }

}



void after_fork_parent(void) {

    printf("After fork (parent): Global pointer is %p\n", global_ptr);

    free(global_ptr); 

    global_ptr = NULL;

}

void after_fork_child(void) {

    printf("After fork (child): Global pointer is %p\n", global_ptr);

    free(global_ptr); 

    global_ptr = NULL;

}



int main() {

    if (pthread_atfork(before_fork, after_fork_parent, after_fork_child) != 0) {

        perror("pthread_atfork registration failed");

        return 1;

    }

    printf("Calling fork()\n");

    pid_t pid = fork(); 

    if (pid < 0) {

        perror("fork failed");

        return 1;

    } else if (pid == 0) {

        printf("Child process\n");

    } else {

        printf("Parent process\n");

        wait(NULL); 

    }

    return 0;

}

