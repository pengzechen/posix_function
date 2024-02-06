#include <stdio.h>

#include <stdlib.h> 

int main() {

    int *ptr = (int*)malloc(10 * sizeof(int));

    if (ptr == NULL) {

        fprintf(stderr, "�ڴ����ʧ��\n");

        return 1;

    }


    for (int i = 0; i < 10; i++) {

        ptr[i] = i;

    }


    printf("ԭʼ�ڴ�����ݣ�");

    for (int i = 0; i < 10; i++) {

        printf("%d ", ptr[i]);

    }

    printf("\n");


    ptr = (int*)realloc(ptr, 20 * sizeof(int));

    if (ptr == NULL) {

        fprintf(stderr, "�ڴ����·���ʧ��\n");

        free(ptr); 

        return 1;

    }

    printf("���·������ڴ�����ݣ�");

    for (int i = 0; i < 20; i++) {

        printf("%d ", ptr[i]);

    }

    printf("\n");

    free(ptr);

    return 0;

}

