#include <stdio.h>
#include <ctype.h> // ����ctype.h��ʹ��isgraph()����

int main() {
    // �����ַ�
    char ch = 'A';

    // ʹ��isgraph()����ַ��Ƿ���ͼ���ַ�
    if (isgraph(ch)) {
        printf("�ַ� %c ��ͼ���ַ���\n", ch);
    } else {
        printf("�ַ� %c ����ͼ���ַ���\n", ch);
    }

    return 0;
}
