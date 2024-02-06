#include <stdio.h>

#include <string.h>

int main() {

    // ���������ַ�������

    char str1[] = "Hello";

    char str2[] = "World";

    char str3[] = "Hello";



    // ʹ��strcmp()�����Ƚ�str1��str2

    int result = strcmp(str1, str2);



    // ���ȽϽ��

    if (result < 0) {

        // str1С��str2

        printf("str1 < str2\n");

    } else if (result > 0) {

        // str1����str2

        printf("str1 > str2\n");

    } else {

        // str1����str2

        printf("str1 == str2\n");

    }



    // ʹ��strcmp()�����Ƚ�str1��str3

    result = strcmp(str1, str3);



    // ���ȽϽ��

    if (result < 0) {

        // str1С��str3

        printf("str1 < str3\n");

    } else if (result > 0) {

        // str1����str3

        printf("str1 > str3\n");

    } else {

        // str1����str3

        printf("str1 == str3\n");

    }



    return 0;

}

