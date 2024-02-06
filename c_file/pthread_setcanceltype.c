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

    int cancel_type;

    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {

        perror("pthread_create failed");

        return 1;

    }

    cancel_type = PTHREAD_CANCEL_DEFERRED;

    if (pthread_setcanceltype(cancel_type, NULL) != 0) {

        perror("pthread_setcanceltype failed");

        return 1;

    }

    sleep(1);

    cancel_type = PTHREAD_CANCEL_ASYNCHRONOUS;

    if (pthread_setcanceltype(cancel_type, NULL) != 0) {

        perror("pthread_setcanceltype failed");

        return 1;

    }

    pthread_cancel(thread);


    if (pthread_join(thread, NULL) != 0) {

        perror("pthread_join failed");

        return 1;

    }



    printf("Main thread completed successfully\n");

    return 0;

}

