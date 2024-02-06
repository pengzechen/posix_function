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

    printf("Thread is about to exit.\n");

    pthread_exit(NULL);

    return NULL;

}



int main() {

    pthread_t thread;

    long arg = 42;

    if (pthread_create(&thread, NULL, thread_function, (void *)arg) != 0) {

        perror("pthread_create failed");

        return 1;

    }

    if (pthread_join(thread, NULL) != 0) {

        perror("pthread_join failed");

        return 1;

    }

    printf("Main thread completed successfully.\n");

    return 0;

}

