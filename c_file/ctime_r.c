#include <stdio.h>

#include <time.h> // ����time.h��ʹ��ctime_r()����



int main() {

    struct tm *current_time;

    char buffer[26]; // �㹻������ʱ���ַ���



    // ��ȡ��ǰʱ��

    time_t now;

    time(&now);



    // ʹ��ctime_r()��ʱ��ת��Ϊ�ַ���

    current_time = ctime_r(&now, buffer);



    if (current_time != NULL) {

        // ��ӡ��ǰʱ������ں�ʱ��

        printf("��ǰʱ�䣺 %s", current_time);

    } else {

        fprintf(stderr, "��ȡ��ǰʱ��ʧ��\n");

    }



    return 0;

}

