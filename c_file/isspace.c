#include <stdio.h>
#include <ctype.h> // ����ctype.h��ʹ��isspace()����

int main() {
    // �����ַ�
    char ch = ' ';

    // ʹ��isspace()����ַ��Ƿ��ǿհ��ַ�
    if (isspace(ch)) {
        printf("�ַ� %c �ǿհ��ַ���\n", ch);
    } else {
        printf("�ַ� %c ���ǿհ��ַ���\n", ch);
    }

    return 0;
}
