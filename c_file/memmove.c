#include <stdio.h>
#include <string.h> // ����string.h��ʹ��memmove()����

int main() {
    // ����һ���ַ�������ΪԴ
    char src[] = "Hello, World!";

    // ����һ���ַ�������ΪĿ�ĵأ������㹻������src�е��ַ���
    char dest[20] = "Hello, C!";

    // ʹ��memmove()�����ַ�������ʹsrc��dest���ص�Ҳ�������
    memmove(dest, src, sizeof(src));

    // ��ӡ���ƺ��Ŀ�ĵ��ַ���
    printf("���ƺ���ַ����ǣ�%s\n", dest);

    return 0;
}
