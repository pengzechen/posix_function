#include <stdio.h>
#include <string.h> // ����string.h��ʹ��memset()����

int main() {
    // ����һ���ַ�����
    char buffer[20];

    // ʹ��memset()�������ڴ������Ϊ0����'\0'��
    memset(buffer, 0, sizeof(buffer));

    // ��ӡ���ú���ڴ������
    printf("���ú���ڴ�������ǣ�%s\n", buffer);

    return 0;
}
