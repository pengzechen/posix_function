#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    // ����һ��������ֵ���ַ���
    char str[] = "12345";

    // ʹ��strtoll()�������ַ���ת��Ϊ��������
    long long value = strtoll(str, NULL, 10);

    // ��ӡת�����ֵ
    printf("ת����ĳ��������ǣ�%lld\n", value);

    return 0;
}
