#include <stdio.h>

#include <stdlib.h>

int main() {

    int *ptr = (int *)malloc(sizeof(int));

    if (ptr == NULL) {

        perror("�ڴ����ʧ��");

        return 1;

    }

    *ptr = 42;

    printf("������ڴ���ֵ�ǣ�%d\n", *ptr);

    free(ptr);

    return 0;

}

