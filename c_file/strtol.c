#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    // ����һ��������ֵ���ַ���
    char str[] = "12345";

    // ʹ��strtol()�������ַ���ת��Ϊ��������
    long value = strtol(str, NULL, 10);

    // ��ӡת�����ֵ
    printf("ת����ĳ��������ǣ�%ld\n", value);

    return 0;
}
