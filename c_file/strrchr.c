#include <stdio.h>

int main() {
    // ����һ���ַ���
    char string[] = "Hello, World!";

    // ʹ��strrchr()���������ַ��������һ�����ֵ��ַ�'a'
    char *found = strrchr(string, 'a');

    // ����Ƿ��ҵ��ַ�
    if (found != NULL) {
        printf("�ҵ����ַ�'%c'�������ַ����е�λ���ǣ�%d\n", *found, found - string);
    } else {
        printf("û���ҵ��ַ�'a'��\n");
    }

    return 0;
}
