#include <stdio.h>

#include <ctype.h> 

int main() {

    char ch = '5';

    if (isdigit(ch)) {

        printf("�ַ� %c ��ʮ�������֡�\n", ch);

    } else {

        printf("�ַ� %c ����ʮ�������֡�\n", ch);

    }

    return 0;
}

