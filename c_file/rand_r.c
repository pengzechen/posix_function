#include <stdio.h>

#include <stdlib.h> // ����stdlib.h��ʹ��rand_r()����

#include <time.h>

int main() {

    unsigned int seed = time(NULL);

    unsigned int randomNumber = rand_r(&seed);


    printf("radom number: %u\n", randomNumber);

    return 0;
}

