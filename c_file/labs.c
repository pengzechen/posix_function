#include <stdio.h>
#include <stdlib.h> // ����stdlib.h��ʹ��labs()����

int main() {
    // ������ֵ
    long int num = -12345;

    // ʹ��labs()��ȡ��ֵ�ľ���ֵ
    long int abs_num = labs(num);

    // ��ӡ����ֵ
    printf("��ֵ %ld �ľ���ֵ�� %ld��\n", num, abs_num);

    return 0;
}
