#include <stdio.h>
#include <stdlib.h> // ����stdlib.h��ʹ��lldiv()����

int main() {
    // �������ͳ���
    long long int numerator = 1234567890123456789LL;
    long long int denominator = 12345;

    // ����lldiv()���г�����������
    lldiv_t result;
    result = lldiv(numerator, denominator);

    // ��ӡ�̺�����
    printf("���� %lld�������� %lld��\n", result.quot, result.rem);

    return 0;
}
