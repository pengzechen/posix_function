#include <stdio.h>

#include <pthread.h>

#include <unistd.h>


pthread_mutexattr_t mutexattr;

pthread_mutex_t mutex;

void *recursive_mutex_demo(void *arg) {

    int count = *(int *)arg;

    printf("Thread %ld starting\n", (long)pthread_self());


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

    for (int i = 0; i < count; i++) {

        if (pthread_mutex_lock(&mutex) != 0) {

            perror("pthread_mutex_lock failed");

            return NULL;

        }

        printf("Thread %ld locking recursively %d times\n", (long)pthread_self(), i + 1);

        if (pthread_mutex_unlock(&mutex) != 0) {

            perror("pthread_mutex_unlock failed");

            return NULL;

        }

    }

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

    pthread_t thread1, thread2;

    int count = 5;


    if (pthread_create(&thread1, NULL, recursive_mutex_demo, &count) != 0) {

        perror("pthread_create failed for thread 1");

        return 1;

    }


    if (pthread_create(&thread2, NULL, recursive_mutex_demo, &count) != 0) {

        perror("pthread_create failed for thread 2");

        return 1;

    }

    if (pthread_join(thread1, NULL) != 0) {

        perror("pthread_join failed for thread 1");

        return 1;

    }



    if (pthread_join(thread2, NULL) != 0) {

        perror("pthread_join failed for thread 2");

        return 1;

    }



    printf("Main thread completed successfully\n");

    return 0;

}

