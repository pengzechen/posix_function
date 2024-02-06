#include <stdio.h>

#include <string.h>

int main() {

    // ���������ַ�������

    char str1[] = "Hello, ";

    char str2[] = "World!";



    // ʹ��strcat()������str2���ӵ�str1����

    strcat(str1, str2);



    // ��ӡ���Ӻ���ַ���

    printf("%s\n", str1);



    return 0;

}

