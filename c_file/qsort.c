#include <stdio.h>
#include <stdlib.h> // ����stdlib.h��ʹ��qsort()����

// �ȽϺ���������qsort()
int compare(const void *a, const void *b) {
    const int *x = (const int *)a;
    const int *y = (const int *)b;

    // ���xС��y������-1
    if (*x < *y) {
        return -1;
    }
    // ���x����y������0
    if (*x == *y) {
        return 0;
    }
    // ���x����y������1
    return 1;
}

int main() {
    // ����һ����������
    int array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int n = sizeof(array) / sizeof(array[0]);

    // ʹ��qsort()�������������
    qsort(array, n, sizeof(int), compare);

    // ��ӡ����������
    printf("�����������ǣ�");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
