#include <stdio.h>
#include <ctype.h> // ����ctype.h��ʹ��isdigit()����

int main() {
    // �����ַ�
    char ch = '5';

    // ʹ��isdigit()����ַ��Ƿ���ʮ��������
    if (isdigit(ch)) {
        printf("�ַ� %c ��ʮ�������֡�\n", ch);
    } else {
        printf("�ַ� %c ����ʮ�������֡�\n", ch);
    }

    return 0;
}
