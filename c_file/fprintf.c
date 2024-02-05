#include <stdio.h>



int main() {

    // ʹ�� fprintf ��ӡ��Ϣ����׼���

    fprintf(stdout, "Hello, World! This is a demo of the fprintf function.\n");

    fprintf(stdout, "The current time is %s.\n", ctime((time(NULL))));



    // ���������˳�

    return 0;

}

