#include <stdio.h>

#include <stdlib.h> // ����stdlib.h��ʹ��srand()����

#include <time.h>

int main() {

    srand((unsigned int)time(NULL));


    for (int i = 0; i < 10; i++) {

        printf("%d ", rand());

    }


    printf("\n");

    return 0;

}

