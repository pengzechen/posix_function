#include <stdio.h>
#include <stdlib.h> // ����stdlib.h��ʹ��malloc()����

int main() {
    // ����һ��int���͵��ڴ��
    int *ptr = (int *)malloc(sizeof(int));

    // �������Ƿ�ɹ�
    if (ptr == NULL) {
        perror("�ڴ����ʧ��");
        return 1;
    }

    // ��������ڴ�鸳ֵ
    *ptr = 42;

    // ��ӡ������ڴ���ֵ
    printf("������ڴ���ֵ�ǣ�%d\n", *ptr);

    // �ͷŷ�����ڴ�
    free(ptr);

    return 0;
}
