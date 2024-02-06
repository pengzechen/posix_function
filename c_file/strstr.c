#include <stdio.h>

#include <string.h>



int main() {

    char str1[] = "Hello, World!";

    char str2[] = "World";

    char *found = strstr(str1, str2);

    if (found != NULL) {

        printf("�ҵ����ַ���'%s'�������ַ���'%s'�е�λ���ǣ�%ld\n", str2, str1, found - str1);

    } else {

        printf("û���ҵ��ַ���'%s'��\n", str2);

    }

    return 0;

}

