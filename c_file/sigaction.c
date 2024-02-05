#include <stdio.h>

#include <stdlib.h>

#include <signal.h>

#include <unistd.h>

#include <string.h>

// �źŴ�������

void handle_sigint(int sig) {

    printf("Caught signal %d (SIGINT)\n", sig);

}



int main() {

    // �����źŴ����ṹ��

    struct sigaction sa;

    

    // ��ʼ���źŴ����ṹ��

    memset(&sa, 0, sizeof(sa));

    

    // �����źŴ�������

    sa.sa_handler = handle_sigint;

    

    // ���� SA_RESTART ��־���Ա㱻�ź��жϵ�ϵͳ���ÿ�������

    sa.sa_flags = SA_RESTART;

    

    // ע���źŴ�������

    if (sigaction(SIGINT, &sa, NULL) == -1) {

        perror("sigaction() failed");

        return EXIT_FAILURE;

    }



    printf("Press Ctrl+C to catch a signal.\n");



    // ���������ڵ����У�ֱ�����յ� SIGINT �ź�

    while (1) {

        pause(); // ��ִͣ�У��ȴ��ź�

    }



    return EXIT_SUCCESS;

}

