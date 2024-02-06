#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main() {

    // ���������ַ�������

    char source[] = "Hello, World!";

    char destination[20]; // ȷ��destination�㹻���Դ洢source�ַ���



    // ʹ��strcpy()������source�ַ������Ƶ�destination�ַ�����

    strcpy(destination, source);



    // ��ӡ���ƺ��destination�ַ���

    printf("%s\n", destination);



    return 0;

}

