#include <stdio.h>
#include <string.h> // ����string.h��ʹ��memchr()����

int main() {
    // ����һ���ַ�����
    char str[] = "Hello, World!";

    // Ҫ���ҵ��ַ�
    char to_find = 'W';

    // ʹ��memchr()�����ַ�'W'
    char *found = memchr(str, to_find, sizeof(str) - 1); // ע���ų���������һ��Ԫ��

    // ����Ƿ��ҵ��ַ�
    if (found != NULL) {
        // ��ӡ�ҵ��ַ��ĵ�ַ
        printf("�ַ�'%c'�������еĵ�ַ�ǣ�%p\n", to_find, found);
    } else {
        // ���û���ҵ��ַ�����ӡ��Ϣ
        printf("�ַ�'%c'δ���������ҵ���\n", to_find);
    }

    return 0;
}
