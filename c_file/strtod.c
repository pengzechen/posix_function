#include <stdio.h>
#include <stdlib.h>

int main() {
    // ����һ��������ֵ���ַ���
    char str[] = "123.456";

    // ʹ��strtod()�������ַ���ת��Ϊ˫���ȸ�����
    double value = strtod(str, NULL);

    // ��ӡת�����ֵ
    printf("ת�����˫���ȸ������ǣ�%f\n", value);

    return 0;
}
