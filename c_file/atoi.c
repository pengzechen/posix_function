#include <stdio.h>
#include <stdlib.h> // ����stdlib.h��ʹ��atoi()����

int main() {
    char str[] = "1234"; // ����һ���������ֵ��ַ���
    int value;

    // ʹ��atoi()�������ַ���ת��Ϊ����
    value = atoi(str);

    printf("ת����������� %d\n", value);

    return 0;
}
