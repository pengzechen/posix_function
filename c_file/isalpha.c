#include <stdio.h>

#include <ctype.h> 

int main() {

    char ch = 'A';

    if (isalpha(ch)) {

        printf("�ַ� %c ����ĸ��\n", ch);

    } else {

        printf("�ַ� %c ������ĸ��\n", ch);

    }

    return 0;

}

