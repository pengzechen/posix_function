#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PRODUCTS 10

// 共享资源：商品数组
int products[NUM_PRODUCTS];
int num_products = 0;

// 条件变量
pthread_cond_t cond;
pthread_mutex_t mutex;

// 生产者线程函数
void *producer(void *arg) {
    int i;
    for (i = 0; i < NUM_PRODUCTS; i++) {
        // 生产商品
        products[i] = i;
        num_products++;

        // 通知消费者线程有新商品
        pthread_mutex_lock(&mutex);
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);

        printf("Produced: %d\n", products[i]);
        sleep(rand() % 3); // 随机休眠一段时间
    }
    return NULL;
}

// 消费者线程函数
void *consumer(void *arg) {
    int i;
    for (i = 0; i < NUM_PRODUCTS; i++) {
        // 等待商品
        pthread_mutex_lock(&mutex);
        while (num_products == 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);

        // 消费商品
        printf("Consumed: %d\n", products[i]);
        num_products--;
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // 初始化条件变量
    if (pthread_cond_init(&cond, NULL) != 0) {
        perror("pthread_cond_init failed");
        return 1;
    }

    // 初始化互斥锁
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        perror("pthread_mutex_init failed");
        return 1;
    }

    // 创建生产者线程
    if (pthread_create(&producer_thread, NULL, producer, NULL) != 0) {
        perror("pthread_create failed for producer");
        return 1;
    }

    // 创建消费者线程
    if (pthread_create(&consumer_thread, NULL, consumer, NULL) != 0) {
        perror("pthread_create failed for consumer");
        return 1;
    }

    // 等待线程结束
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // 销毁条件变量
    pthread_cond_destroy(&cond);
    // 销毁互斥锁
    pthread_mutex_destroy(&mutex);

    printf("Main thread completed successfully.\n");
    return 0;
}
