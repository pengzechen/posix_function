#include <stdio.h>

#include <pthread.h>

#include <unistd.h>


pthread_mutex_t mutex;

pthread_mutexattr_t mutexattr;


int shared_resource = 0;


void *thread_function(void *arg) {

    long thread_id = (long)arg;

    printf("Thread %ld started\n", thread_id);

    if (pthread_mutexattr_init(&mutexattr) != 0) {

        perror("pthread_mutexattr_init failed");

        return NULL;

    }

    if (pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_DEFAULT) != 0) {

        perror("pthread_mutexattr_settype failed");

        return NULL;

    }

    if (pthread_mutex_init(&mutex, &mutexattr) != 0) {

        perror("pthread_mutex_init failed");

        return NULL;

    }

    if (pthread_mutex_lock(&mutex) != 0) {

        perror("pthread_mutex_lock failed");

        return NULL;

    }

    shared_resource++;

    printf("Thread %ld increased shared resource to %d\n", thread_id, shared_resource);

    if (pthread_mutex_unlock(&mutex) != 0) {

        perror("pthread_mutex_unlock failed");

        return NULL;

    }

    if (pthread_mutex_destroy(&mutex) != 0) {

        perror("pthread_mutex_destroy failed");

        return NULL;

    }


    if (pthread_mutexattr_destroy(&mutexattr) != 0) {

        perror("pthread_mutexattr_destroy failed");

        return NULL;

    }



    printf("Thread %ld finished working\n", thread_id);

    return NULL;

}



int main() {

    pthread_t thread1, thread2;

    long arg1 = 1, arg2 = 2;

    if (pthread_create(&thread1, NULL, thread_function, (void *)arg1) != 0) {

        perror("pthread_create failed");

        return 1;

    }

    if (pthread_create(&thread2, NULL, thread_function, (void *)arg2) != 0) {

        perror("pthread_create failed");

        return 1;

    }

    if (pthread_join(thread1, NULL) != 0) {

        perror("pthread_join failed");

        return 1;

    }

    if (pthread_join(thread2, NULL) != 0) {

        perror("pthread_join failed");

        return 1;

    }



    printf("Main thread completed successfully\n");

    return 0;

}

