#include <stdio.h>

int main() {
    // ���������ַ�������
    char destination[] = "Hello";
    char source[] = ", World!";

    // ʹ��strncat()������source�ַ�����ǰ5���ַ����ӵ�destination�ַ�����ĩβ
    strncat(destination, source, 5);

    // ��ӡ���Ӻ���ַ���
    printf("���Ӻ���ַ����ǣ�%s\n", destination);

    return 0;
}
