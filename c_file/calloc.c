#include <stdio.h>
#include <stdlib.h> // ����stdlib.h��ʹ��calloc()����

int main() {
    int n = 10; // ����Ҫ�����Ԫ������
    int *array; // ����ָ��������ڴ洢������ڴ��ַ

    // ʹ��calloc()�����ڴ�
    array = (int*)calloc(n, sizeof(int));

    if (array == NULL) {
        fprintf(stderr, "�ڴ����ʧ��\n");
        return 1;
    }

    // ��ӡ������ڴ��ַ
    printf("������ڴ��ַ�� %p\n", array);

    // �ͷŷ�����ڴ�
    free(array);

    return 0;
}
