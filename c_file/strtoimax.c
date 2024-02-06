#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>

#include <string.h>

#include <inttypes.h>

int main() {

    // ����һ��������ֵ���ַ���

    char str[] = "2147483647"; // ����һ�� INT_MAX ��ֵ



    // ʹ��strtoimax()�������ַ���ת��Ϊintmax_t���͵��������

    intmax_t value = strtoimax(str, NULL, 10);



    // ��ӡת�����ֵ

    printf("ת�����intmax_t���������ǣ�%jd\n", value);



    return 0;

}

