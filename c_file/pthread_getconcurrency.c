#include <stdio.h>

#include <pthread.h>

#include <signal.h>

#include <unistd.h>

#include <stdlib.h>

void *thread_function(void *arg) {

    printf("Thread started\n");

    printf("Thread finishing\n");

    return NULL;

}



int main() {

    pthread_t threads[10];

    int i, concurrency;


    for (i = 0; i < 10; i++) {

        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {

            perror("pthread_create failed");

            return 1;

        }

    }

    for (i = 0; i < 10; i++) {

        if (pthread_join(threads[i], NULL) != 0) {

            perror("pthread_join failed");

            return 1;

        }

    }

    if (pthread_getconcurrency(&concurrency) != 0) {

        perror("pthread_getconcurrency failed");

        return 1;

    }

    printf("Current concurrency level is: %d\n", concurrency);


    return 0;

}

