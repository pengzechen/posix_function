#include <stdio.h>
#include <ctype.h> // ����ctype.h��ʹ��isxdigit()����

int main() {
    // �����ַ�
    char ch = 'A';

    // ʹ��isxdigit()����ַ��Ƿ���ʮ����������
    if (isxdigit(ch)) {
        printf("�ַ� %c ��ʮ���������֡�\n", ch);
    } else {
        printf("�ַ� %c ����ʮ���������֡�\n", ch);
    }

    return 0;
}
