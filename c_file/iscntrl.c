#include <stdio.h>

#include <ctype.h> 
int main() {

    char ch = '\n'; 

    if (iscntrl(ch)) {

        printf("�ַ� %c �ǿ����ַ���\n", ch);

    } else {

        printf("�ַ� %c ���ǿ����ַ���\n", ch);

    }

    return 0;

}

