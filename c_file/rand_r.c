#include <stdio.h>
#include <stdlib.h> // ����stdlib.h��ʹ��rand_r()����

int main() {
    // ����һ��unsigned int���͵ı�����Ϊ����
    unsigned int seed = time(NULL);

    // ʹ��rand_r()����һ��α�������
    unsigned int randomNumber = rand_r(&seed);

    // ��ӡ���ɵ������
    printf("���ɵ�������ǣ�%u\n", randomNumber);

    return 0;
}
