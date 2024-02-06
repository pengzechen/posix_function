#include <stdio.h>

#include <pthread.h>

#include <unistd.h>

pthread_mutexattr_t mutexattr;


void *create_mutex_demo(void *arg) {

    pthread_mutex_t mutex;

    if (pthread_mutexattr_init(&mutexattr) != 0) {

        perror("pthread_mutexattr_init failed");

        return NULL;

    }

    if (pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_RECURSIVE) != 0) {

        perror("pthread_mutexattr_settype failed");

        return NULL;

    }

    if (pthread_mutex_init(&mutex, &mutexattr) != 0) {

        perror("pthread_mutex_init failed");

        return NULL;

    }

    int mutex_type;

    if (pthread_mutexattr_gettype(&mutexattr, &mutex_type) != 0) {

        perror("pthread_mutexattr_gettype failed");

        return NULL;

    }

    printf("Mutex type is: %d\n", mutex_type);

    if (pthread_mutex_destroy(&mutex) != 0) {

        perror("pthread_mutex_destroy failed");

        return NULL;

    }

    if (pthread_mutexattr_destroy(&mutexattr) != 0) {

        perror("pthread_mutexattr_destroy failed");

        return NULL;

    }



    return NULL;

}



int main() {

    pthread_t thread;

    if (pthread_create(&thread, NULL, create_mutex_demo, NULL) != 0) {

        perror("pthread_create failed");

        return 1;

    }

    if (pthread_join(thread, NULL) != 0) {

        perror("pthread_join failed");

        return 1;

    }

    printf("Main thread completed successfully\n");

    return 0;

}

