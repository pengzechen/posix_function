#include <stdio.h>

int main() {
    // ����һ���㹻��Ļ�����
    char buffer[30];

    // ʹ��sprintf()�򻺳�����д���ʽ�����ַ���
    sprintf(buffer, "Hello, %s!", "World");

    // ��ӡ�������е�����
    printf("�������е������ǣ�%s\n", buffer);

    return 0;
}
