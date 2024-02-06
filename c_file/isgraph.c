#include <stdio.h>

#include <ctype.h> 

int main() {

    char ch = 'A';

    if (isgraph(ch)) {

        printf("�ַ� %c ��ͼ���ַ���\n", ch);

    } else {

        printf("�ַ� %c ����ͼ���ַ���\n", ch);

    }

    return 0;
}

