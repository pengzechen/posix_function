#include <stdio.h>
#include <math.h> // ����math.h��ʹ��abs()����
#include <stdlib.h>
int main() {
    double num = -10.5; // ����һ������
    double abs_result = abs(num); // ʹ��abs()�����������ֵ

    printf("ԭʼ��ֵ�� %f\n", num);
    printf("����ֵ�� %f\n", abs_result);

    return 0;
}
