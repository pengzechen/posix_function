#include <stdio.h>

#include <string.h>

int main() {

    char string[] = "Hello, World!";

    char chars[] = "abc";

    char *found = strpbrk(string, chars);

    if (found != NULL) {

        printf("�ҵ����ַ������еĵ�һ���ַ���'%c'\n", *found);

    } else {

        printf("û���ҵ��ַ������е��κ��ַ���\n");

    }

    return 0;

}

