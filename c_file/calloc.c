#include <stdio.h>

#include <stdlib.h> 

int main() {

    int n = 10; 
    int *array; 

    array = (int*)calloc(n, sizeof(int));

    if (array == NULL) {

        fprintf(stderr, "�ڴ����ʧ��\n");

        return 1;

    }

    printf("������ڴ��ַ�� %p\n", array);

    free(array);

    return 0;
}

