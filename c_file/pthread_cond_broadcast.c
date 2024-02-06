#include <stdio.h>

#include <pthread.h>

#include <unistd.h>

#include <stdlib.h>

#define NUM_PRODUCTS 10

int products[NUM_PRODUCTS];

int num_products = 0;


pthread_cond_t cond;

pthread_mutex_t mutex;

void *producer(void *arg) {

    int i;

    for (i = 0; i < NUM_PRODUCTS; i++) {

        products[i] = i;

        num_products++;

        pthread_mutex_lock(&mutex);

        pthread_cond_broadcast(&cond);

        pthread_mutex_unlock(&mutex);


        printf("Produced: %d\n", products[i]);

        sleep(rand() % 3); 
    }

    return NULL;

}


void *consumer(void *arg) {

    int i;

    for (i = 0; i < NUM_PRODUCTS; i++) {

        pthread_mutex_lock(&mutex);

        while (num_products == 0) {

            pthread_cond_wait(&cond, &mutex);

        }

        pthread_mutex_unlock(&mutex);

        printf("Consumed: %d\n", products[i]);

        num_products--;

    }

    return NULL;

}



int main() {

    pthread_t producer_thread, consumer_thread;

    if (pthread_cond_init(&cond, NULL) != 0) {

        perror("pthread_cond_init failed");

        return 1;

    }

    if (pthread_mutex_init(&mutex, NULL) != 0) {

        perror("pthread_mutex_init failed");

        return 1;

    }

    if (pthread_create(&producer_thread, NULL, producer, NULL) != 0) {

        perror("pthread_create failed for producer");

        return 1;

    }

    if (pthread_create(&consumer_thread, NULL, consumer, NULL) != 0) {

        perror("pthread_create failed for consumer");

        return 1;

    }


    pthread_join(producer_thread, NULL);

    pthread_join(consumer_thread, NULL);




    pthread_cond_destroy(&cond);


    pthread_mutex_destroy(&mutex);



    printf("Main thread completed successfully.\n");

    return 0;

}

