#include <stdio.h>
#include <ctype.h> // ����ctype.h��ʹ��isprint()����

int main() {
    // �����ַ�
    char ch = 'A';

    // ʹ��isprint()����ַ��Ƿ��ǿɴ�ӡ�ַ�
    if (isprint(ch)) {
        printf("�ַ� %c �ǿɴ�ӡ�ַ���\n", ch);
    } else {
        printf("�ַ� %c ���ǿɴ�ӡ�ַ���\n", ch);
    }

    return 0;
}
