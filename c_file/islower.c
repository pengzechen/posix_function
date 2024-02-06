#include <stdio.h>

#include <ctype.h> 

int main() {

    char ch = 'a';

    if (islower(ch)) {

        printf("�ַ� %c ��Ӣ��Сд��ĸ��\n", ch);

    } else {

        printf("�ַ� %c ����Ӣ��Сд��ĸ��\n", ch);

    }

    return 0;
}

