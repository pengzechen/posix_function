#include <stdio.h>
#include <string.h> // ����string.h��ʹ��memcmp()����

int main() {
    // ���������ַ���
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World";

    // ʹ��memcmp()�Ƚ������ַ���
    int result = memcmp(str1, str2, sizeof(str1));

    // ���ȽϽ��
    if (result == 0) {
        // ��������ַ�����ȣ���ӡ��Ϣ
        printf("�ַ���'%s'��'%s'��ȡ�\n", str1, str2);
    } else if (result > 0) {
        // ���str1����str2����ӡ��Ϣ
        printf("�ַ���'%s'����'%s'��\n", str1, str2);
    } else {
        // ���str1С��str2����ӡ��Ϣ
        printf("�ַ���'%s'С��'%s'��\n", str1, str2);
    }

    return 0;
}
