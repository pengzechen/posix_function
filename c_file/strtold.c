#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    // ����һ��������ֵ���ַ���
    char str[] = "12345.6789";

    // ʹ��strtold()�������ַ���ת��Ϊ��˫���ȸ�����
    long double value = strtold(str, NULL);

    // ��ӡת�����ֵ
    printf("ת����ĳ�˫���ȸ������ǣ�%Lf\n", value);

    return 0;
}
