#include <stdio.h>
#include <ctype.h> // ����ctype.h��ʹ��isalpha()����

int main() {
    // �����ַ�
    char ch = 'A';

    // ʹ��isalpha()����ַ��Ƿ�����ĸ
    if (isalpha(ch)) {
        printf("�ַ� %c ����ĸ��\n", ch);
    } else {
        printf("�ַ� %c ������ĸ��\n", ch);
    }

    return 0;
}
