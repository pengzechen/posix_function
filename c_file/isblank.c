#include <stdio.h>
#include <ctype.h> // ����ctype.h��ʹ��isblank()����

int main() {
    // �����ַ�
    char ch = ' ';

    // ʹ��isblank()����ַ��Ƿ��ǿհ��ַ�
    if (isblank(ch)) {
        printf("�ַ� %c �ǿհ��ַ���\n", ch);
    } else {
        printf("�ַ� %c ���ǿհ��ַ���\n", ch);
    }

    return 0;
}
