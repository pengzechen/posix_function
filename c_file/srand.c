#include <stdio.h>
#include <stdlib.h> // ����stdlib.h��ʹ��srand()����

int main() {
    // �������������
    srand((unsigned int)time(NULL));

    // ���ɲ���ӡ10�������
    for (int i = 0; i < 10; i++) {
        printf("%d ", rand());
    }

    printf("\n");

    return 0;
}
