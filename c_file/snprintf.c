#include <stdio.h>
#include <stdlib.h> // ����stdlib.h��ʹ��malloc()����

int main() {
    // ����һ���㹻��Ļ�����
    char buffer[30];

    // ʹ��snprintf()�򻺳�����д���ʽ�����ַ���
    snprintf(buffer, sizeof(buffer), "Hello, %s!", "World");

    // ��ӡ�������е�����
    printf("�������е������ǣ�%s\n", buffer);

    return 0;
}
