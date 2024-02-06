#include <stdio.h>

#include <pthread.h>

#include <unistd.h>


#include <stdlib.h>


void *thread_function(void *arg) {

    printf("Thread started. Argument: %ld\n", (long)arg);

    for (int i = 0; i < 5; i++) {

        printf("Thread is working...\n");

        sleep(1);

    }

    printf("Thread finished working.\n");

    return NULL;

}



int main() {

    pthread_t thread;

    long arg = 42;

    if (pthread_create(&thread, NULL, thread_function, (void *)arg) != 0) {

        perror("pthread_create failed");

        return 1;

    }

    pthread_detach(thread);

    printf("Main thread is exiting immediately. The detached thread will continue to run.\n");

    return 0;

}

