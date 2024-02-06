#include <stdio.h>

#include <string.h>

int main() {

    // ���������ַ�������

    char str[] = "Hello, World!";

    char chars_to_ignore[] = "abc";



    // ʹ��strcspn()��������str�в�����chars_to_ignore���ַ���ǰ׺�ĳ���

    int length = strcspn(str, chars_to_ignore);



    // ��ӡ������ĳ���

    printf("����Ϊ��%d\n", length);



    return 0;

}

