#include <stdio.h>

#include <signal.h>

#include <unistd.h>

#include <stdlib.h>


// �źŴ�������

void handle_sigint(int sig) {

    printf("Caught signal %d (SIGINT)\n", sig);

}



int main() {

    // ע���źŴ�������

    if (signal(SIGINT, handle_sigint) == SIG_ERR) {

        perror("signal() registration failed");

        return EXIT_FAILURE;

    }



    printf("Press Ctrl+C to catch the SIGINT signal.\n");



    // ���������ڵ����У�ֱ�����յ��ź�

    while (1) {

        pause(); // ��ִͣ�У��ȴ��ź�

    }



    return EXIT_SUCCESS;

}

