#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>


volatile sig_atomic_t stop; // ���ڴ洢�źŴ��������е�״̬


void handle_sigint(int sig) {

    stop = 1; // ����ֹͣ��־

}



int main() {

    signal(SIGINT, handle_sigint);



    printf("Press Ctrl+C to stop the program.\n");

    while (!stop) {

        pause(); // ��ִͣ�У��ȴ��ź�

    }

    printf("Program stopped by user.\n");

    return EXIT_SUCCESS;

}

