#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    // ����һ��������ֵ���ַ���
    char str[] = "12345";

    // ʹ��strtoumax()�������ַ���ת��Ϊ�޷��ų�������
    unsigned long value = strtoumax(str, NULL, 10);

    // ��ӡת�����ֵ
    printf("ת������޷��ų��������ǣ�%lu\n", value);

    return 0;
}
