#include <stdio.h>
#include <ctype.h> // ����ctype.h��ʹ��isupper()����

int main() {
    // �����ַ�
    char ch = 'A';

    // ʹ��isupper()����ַ��Ƿ���Ӣ�Ĵ�д��ĸ
    if (isupper(ch)) {
        printf("�ַ� %c ��Ӣ�Ĵ�д��ĸ��\n", ch);
    } else {
        printf("�ַ� %c ����Ӣ�Ĵ�д��ĸ��\n", ch);
    }

    return 0;
}
