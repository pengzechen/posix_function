#include <stdio.h>

#include <pthread.h>

#include <unistd.h>

#include <stdlib.h>


void *print_numbers(void *arg) {

    int *num = (int*)arg;

    for (int i = 0; i < 5; i++) {

        printf("Number: %d\n", *num);

        sleep(1);
    }

    return NULL;

}


void *print_letters(void *arg) {

    for (int i = 0; i < 5; i++) {

        printf("Letter: %c\n", 'A' + i);

        sleep(1); 

    }

    return NULL;

}



int main() {

    pthread_t thread1, thread2;


    if (pthread_create(&thread1, NULL, print_numbers, (void *)1) != 0) {

        perror("pthread_create failed for numbers");

        return 1;

    }


    if (pthread_create(&thread2, NULL, print_letters, (void *)0) != 0) {

        perror("pthread_create failed for letters");

        return 1;

    }


    pthread_join(thread1, NULL);

    pthread_join(thread2, NULL);



    printf("Main thread completed successfully.\n");

    return 0;

}

