#include <stdio.h>
#include <ctype.h> // ����ctype.h��ʹ��isalnum()����

int main() {
    // �����ַ�
    char ch = 'a';

    // ʹ��isalnum()����ַ��Ƿ�����ĸ������
    if (isalnum(ch)) {
        printf("�ַ� %c ����ĸ�����֡�\n", ch);
    } else {
        printf("�ַ� %c ������ĸ�����֡�\n", ch);
    }

    return 0;
}
