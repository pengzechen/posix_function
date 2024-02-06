#include <stdio.h>

#include <locale.h> // ����locale.h��ʹ��setlocale()��strcoll()

#include <string.h>

int main() {

    // ���ó���ʹ�õ���������

    setlocale(LC_ALL, "en_US.UTF-8"); // ���� locale Ϊ����Ӣ��



    // ���������ַ�������

    char str1[] = "Apple";

    char str2[] = "banana";



    // ʹ��strcoll()�����Ƚ�str1��str2

    int result = strcoll(str1, str2);



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



    return 0;

}

