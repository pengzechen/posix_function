#include <stdio.h>

#include <pthread.h>

#include <unistd.h>

void *thread_function(void *arg) {

    printf("Thread is running...\n");

    sleep(1);

    printf("Thread is about to be canceled...\n");

    return NULL;

}



int main() {

    pthread_t thread;

    int cancel_state;

    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {

        perror("pthread_create failed");

        return 1;

    }

    cancel_state = PTHREAD_CANCEL_ENABLE;

    if (pthread_setcancelstate(cancel_state, NULL) != 0) {

        perror("pthread_setcancelstate failed");

        return 1;

    }


    sleep(1);

    cancel_state = PTHREAD_CANCEL_DISABLE;

    if (pthread_setcancelstate(cancel_state, NULL) != 0) {

        perror("pthread_setcancelstate failed");

        return 1;

    }

    if (pthread_cancel(thread) != 0) {

        perror("pthread_cancel failed");

        return 1;

    }

    if (pthread_join(thread, NULL) != 0) {

        perror("pthread_join failed");

        return 1;

    }

    printf("Main thread completed successfully\n");

    return 0;

}

