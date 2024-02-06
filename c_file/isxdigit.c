#include <stdio.h>

#include <ctype.h> 

int main() {

    char ch = 'A';

    if (isxdigit(ch)) {

        printf("�ַ� %c ��ʮ���������֡�\n", ch);

    } else {

        printf("�ַ� %c ����ʮ���������֡�\n", ch);

    }

    return 0;

}

