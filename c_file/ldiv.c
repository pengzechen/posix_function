#include <stdio.h>
#include <stdlib.h> // ����stdlib.h��ʹ��ldiv()����

int main() {
    // �������ͳ���
    long int numerator = 1234567890;
    long int denominator = 12345;

    // ����ldiv()���г���������
    ldiv_t result;
    result = ldiv(numerator, denominator);

    // ��ӡ�̺�����
    printf("���� %ld�������� %ld��\n", result.quot, result.rem);

    return 0;
}
