#include <stdio.h>

int main() {
    // ����һ���ַ���
    char str[] = "Hello, World!";

    // Ҫ���ҵ��ַ�
    char to_find = 'o';

    // ʹ��strchr()��������to_find�ַ���str�ַ����е�һ�γ��ֵ�λ��
    char *found = strchr(str, to_find);

    // ����Ƿ��ҵ����ַ�
    if (found != NULL) {
        // ��ӡ�ҵ����ַ�����λ��
        printf("�ַ�'%c'���ַ����е�λ���ǣ�%d\n", to_find, found - str);
    } else {
        // ���û���ҵ��ַ�����ӡ��Ϣ
        printf("�ַ�'%c'���ַ�����û���ҵ���\n", to_find);
    }

    return 0;
}
