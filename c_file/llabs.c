#include <stdio.h>
#include <stdlib.h> // ����stdlib.h��ʹ��llabs()����

int main() {
    // ���Գ�������ֵ
    long long int num = -1234567890123456789LL;

    // ʹ��llabs()��ȡ��ֵ�ľ���ֵ
    long long int abs_num = llabs(num);

    // ��ӡ����ֵ
    printf("�������� %lld �ľ���ֵ�� %lld��\n", num, abs_num);

    return 0;
}
