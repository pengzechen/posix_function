#include <stdio.h>

#include <ctype.h> 

int main() {

    char ch = 'A';

    if (isupper(ch)) {

        printf("�ַ� %c ��Ӣ�Ĵ�д��ĸ��\n", ch);

    } else {

        printf("�ַ� %c ����Ӣ�Ĵ�д��ĸ��\n", ch);

    }

    return 0;

}

