#include <stdio.h>
#include <stdlib.h> // ����stdlib.h��ʹ��free()����

int main() {
    // ����һЩ�ڴ�
    int *ptr = (int*)malloc(sizeof(int));

    if (ptr == NULL) {
        fprintf(stderr, "�ڴ����ʧ��\n");
        return 1;
    }

    // ʹ�÷�����ڴ�
    *ptr = 42;
    printf("������ڴ��е�ֵ��%d\n", *ptr);

    // �ͷ��ڴ�
    free(ptr);

    // �ٴγ��Է����ڴ���ȷ�����ѱ��ͷ�
    // �⽫��ӡ��һ��������Ϣ����Ϊ�ڴ��ѱ��ͷ�
    // printf("���Է������ͷŵ��ڴ棺%d\n", *ptr);

    return 0;
}
