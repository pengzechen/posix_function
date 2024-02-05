#include <stdio.h>
#include <stdlib.h> // ����stdlib.h��ʹ��realloc()����

int main() {
    // ��ʼ��һ����̬������ڴ�飬��СΪ10��int����
    int *ptr = (int*)malloc(10 * sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "�ڴ����ʧ��\n");
        return 1;
    }

    // ��ʼ���ڴ���е�ֵ
    for (int i = 0; i < 10; i++) {
        ptr[i] = i;
    }

    // ��ӡԭʼ�ڴ�������
    printf("ԭʼ�ڴ�����ݣ�");
    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // ���·����ڴ��Ĵ�С��ʹ���Ϊԭ��������
    ptr = (int*)realloc(ptr, 20 * sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "�ڴ����·���ʧ��\n");
        free(ptr); // �ͷ�֮ǰ���ڴ��
        return 1;
    }

    // ��ӡ���·������ڴ������
    printf("���·������ڴ�����ݣ�");
    for (int i = 0; i < 20; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // �ͷŶ�̬������ڴ��
    free(ptr);

    return 0;
}
