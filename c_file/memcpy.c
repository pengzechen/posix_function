#include <stdio.h>
#include <string.h> // ����string.h��ʹ��memcpy()����

int main() {
    // ����һ���ַ�������ΪԴ
    char src[] = "Hello, World!";

    // ����һ���ַ�������ΪĿ�ĵ�
    char dest[20]; // ȷ����������㹻�������ɸ��Ƶ�����

    // ʹ��memcpy()�����ַ���
    memcpy(dest, src, sizeof(src));

    // ��ӡ���ƺ��Ŀ�ĵ��ַ���
    printf("���ƺ���ַ����ǣ�%s\n", dest);

    return 0;
}
