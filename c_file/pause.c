#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

volatile sig_atomic_t stop; // ���ڴ洢�źŴ������е�״̬

// �źŴ�����
void handle_sigint(int sig) {
    stop = 1; // ����ֹͣ��־
}

int main() {
    // ע���źŴ�����
    signal(SIGINT, handle_sigint);

    printf("Press Ctrl+C to stop the program.\n");

    // ����һ��ѭ�����ȴ��ź�
    while (!stop) {
        pause(); // ��ִͣ�У��ȴ��ź�
    }

    printf("Program stopped by user.\n");

    return EXIT_SUCCESS;
}
