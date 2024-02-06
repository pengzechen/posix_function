#include <stdio.h>

#include <ctype.h> 

int main() {
    char ch = ' ';

    if (isblank(ch)) {

        printf("�ַ� %c �ǿհ��ַ���\n", ch);

    } else {

        printf("�ַ� %c ���ǿհ��ַ���\n", ch);

    }

    return 0;
}

