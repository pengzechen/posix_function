#include <stdio.h>
#include <stdlib.h> // ����stdlib.h��ʹ��atoll()����

int main() {
    char str[] = "1234"; // ����һ���������ֵ��ַ���
    long long value;

    // ʹ��atoll()�������ַ���ת��Ϊ����������
    value = atoll(str);

    printf("ת����ĳ��������� %lld\n", value);

    return 0;
}
