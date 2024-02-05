#include <signal.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <errno.h>


volatile sig_atomic_t goon = 1;
 
static void * worker (void *arg){
    while(goon){
        printf("worker is running , tid:%ld\n" , pthread_self());
        sleep(5);
    }
    puts("worker is done");
}
 
static void * sig_handler_thread(void *arg){
    sigset_t * mask = (sigset_t *)arg;
    int sig = 0;
    pthread_t tid = pthread_self();
    while(1){
        if ( sigwait(mask,&sig)  != 0 ){
            printf("sigwait error : %s\n" , strerror(errno));
            continue;
        }
        printf("thread :%ld got signal : %d\n" , tid,sig);
        if(SIGINT == sig){
            goon = 0;
            break;
        }
    }
}
 
int main(int argc, char**argv)
{
    sigset_t mask;
    sigfillset(&mask);
    pthread_sigmask(SIG_BLOCK,&mask, NULL);
    pthread_t tid1, tid2;
    pthread_create(&tid1,0,sig_handler_thread,&mask);
    pthread_create(&tid2,0,worker,NULL);
 
    int sig = 0;
    while(goon){
        alarm(1);
        sleep(1);
    }
 
    pthread_join(tid2,0);
    pthread_join(tid1, NULL);
    puts("end");
    return 0;
}
