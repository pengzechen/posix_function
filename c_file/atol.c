#include <stdio.h>
#include <stdlib.h> // ����stdlib.h��ʹ��atol()����

int main() {
    char str[] = "1234"; // ����һ���������ֵ��ַ���
    long value;

    // ʹ��atol()�������ַ���ת��Ϊ��������
    value = atol(str);

    printf("ת����ĳ������� %ld\n", value);

    return 0;
}
