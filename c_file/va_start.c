#include <stdio.h>
#include <stdarg.h> // ����va_arg()��va_start()����

int sum_of_numbers(int count, ...) {
    va_list args; // �������������б�
    va_start(args, count); // ��ʼ�����������б�

    int sum = 0;
    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int); // ��ȡ��һ������
        sum += num;
    }

    va_end(args); // ������������б�
    return sum;
}

int main() {
    int result = sum_of_numbers(3, 1, 2, 3); // ���ú��������ݲ���
    printf("The sum is: %d\n", result); // ��ӡ���
    return 0;
}
