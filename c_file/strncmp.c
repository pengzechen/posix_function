#include <stdio.h>

#include <string.h>

int main() {

    // ���������ַ�������

    char string1[] = "Hello";

    char string2[] = "Hello";

    char string3[] = "World";



    // ʹ��strncmp()�����Ƚ�string1��string2��ǰ5���ַ�

    int result = strncmp(string1, string2, 5);



    // ��ӡ�ȽϽ��

    if (result == 0) {

        printf("�ַ�����ͬ��\n");

    } else if (result < 0) {

        printf("string1 < string2��\n");

    } else {

        printf("string1 > string2��\n");

    }



    // ʹ��strncmp()�����Ƚ�string1��string3��ǰ5���ַ�

    result = strncmp(string1, string3, 5);



    // ��ӡ�ȽϽ��

    if (result == 0) {

        printf("�ַ�����ͬ��\n");

    } else if (result < 0) {

        printf("string1 < string3��\n");

    } else {

        printf("string1 > string3��\n");

    }



    return 0;

}

