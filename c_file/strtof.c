#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int main() {

    // ����һ��������ֵ���ַ���

    char str[] = "3.14159";



    // ʹ��strtof()�������ַ���ת��Ϊ�����ȸ�����

    float value = strtof(str, NULL);



    // ��ӡת�����ֵ

    printf("ת����ĵ����ȸ������ǣ�%f\n", value);



    return 0;

}

