#include <stdio.h>

#include <ctype.h> 

int main() {

    char ch = 'A';

    if (isprint(ch)) {

        printf("�ַ� %c �ǿɴ�ӡ�ַ���\n", ch);

    } else {

        printf("�ַ� %c ���ǿɴ�ӡ�ַ���\n", ch);

    }

    return 0;
}

