#include <stdio.h>

#include <string.h>

int main() {

    // ���������ַ�������

    char destination[] = "Hello";

    char source[] = "Hello, World!";



    // ʹ��strncpy()������source�ַ������Ƶ�destination�ַ����У�������5���ַ�

    strncpy(destination, source, 5);



    // ��ӡ���ƺ���ַ���

    printf("���ƺ���ַ����ǣ�%s\n", destination);



    return 0;

}

