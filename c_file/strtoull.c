#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    // ����һ��������ֵ���ַ���
    char str[] = "12345";

    // ʹ��strtoull()�������ַ���ת��Ϊ�޷��ų�������
    unsigned long long value = strtoull(str, NULL, 10);

    // ��ӡת�����ֵ
    printf("ת������޷��ų��������ǣ�%llu\n", value);

    return 0;
}
