#include <stdio.h>
#include <stdlib.h> // ����stdlib.h��ʹ��atof()����

int main() {
    char str[] = "123.456"; // ����һ���������ֵ��ַ���
    double value;

    // ʹ��atof()�������ַ���ת��Ϊ������
    value = atof(str);

    printf("ת����ĸ������� %f\n", value);

    return 0;
}
