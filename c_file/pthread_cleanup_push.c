#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

void cleanup(void *arg)
{
    printf("clean...\n");
}

void *My_thread(void *arg)
{
    printf("My thread\n");
    pthread_cleanup_push(cleanup,"123");
    pthread_exit(NULL);        //虽然在这里，线程已经结束了，但是下面的pop函数还是得写上。
    pthread_cleanup_pop(0);
}

int main()
{
    pthread_t tid;
    int t = pthread_create(&tid,NULL,My_thread,NULL);
    pthread_join(tid,NULL);
    return 0;
}