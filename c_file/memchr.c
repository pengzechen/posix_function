#include <stdio.h>

#include <string.h> 


int main() {

    char str[] = "Hello, World!";

    char to_find = 'W';

    char *found = memchr(str, to_find, sizeof(str) - 1); 

    if (found != NULL) {

        printf("�ַ�'%c'�������еĵ�ַ�ǣ�%p\n", to_find, found);

    } else {

        printf("�ַ�'%c'δ���������ҵ���\n", to_find);

    }

    return 0;

}

