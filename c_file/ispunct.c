#include <stdio.h>
#include <ctype.h> // ����ctype.h��ʹ��ispunct()����

int main() {
    // �����ַ�
    char ch = '.';

    // ʹ��ispunct()����ַ��Ƿ��Ǳ�����
    if (ispunct(ch)) {
        printf("�ַ� %c �Ǳ����š�\n", ch);
    } else {
        printf("�ַ� %c ���Ǳ����š�\n", ch);
    }

    return 0;
}
