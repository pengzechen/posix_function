#include <stdio.h>
#include <ctype.h> // ����ctype.h��ʹ��iscntrl()����

int main() {
    // �����ַ�
    char ch = '\n'; // ���з�

    // ʹ��iscntrl()����ַ��Ƿ��ǿ����ַ�
    if (iscntrl(ch)) {
        printf("�ַ� %c �ǿ����ַ���\n", ch);
    } else {
        printf("�ַ� %c ���ǿ����ַ���\n", ch);
    }

    return 0;
}
