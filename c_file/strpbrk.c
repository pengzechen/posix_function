#include <stdio.h>

int main() {
    // ����һ���ַ���
    char string[] = "Hello, World!";

    // ����һ���ַ�����
    char chars[] = "abc";

    // ʹ��strpbrk()���������ַ������ַ����ϵĵ�һ���ַ�
    char *found = strpbrk(string, chars);

    // ����Ƿ��ҵ��ַ�
    if (found != NULL) {
        printf("�ҵ����ַ������еĵ�һ���ַ���'%c'\n", *found);
    } else {
        printf("û���ҵ��ַ������е��κ��ַ���\n");
    }

    return 0;
}
