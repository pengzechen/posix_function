#include <stdio.h>

#include <ctype.h> 

int main() {

    char ch = '.';

    if (ispunct(ch)) {

        printf("�ַ� %c �Ǳ����š�\n", ch);

    } else {

        printf("�ַ� %c ���Ǳ����š�\n", ch);

    }

    return 0;

}

