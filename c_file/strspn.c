#include <stdio.h>
#include <string.h>

int main() {
    // ���������ַ���
    char str1[] = "Hello, World!";
    char str2[] = "Hello";

    // ʹ��strspn()��������str1������εĳ��ȣ��ö���str2�е��ַ����
    size_t len = strspn(str1, str2);

    // ��ӡ���
    printf("strspn() returned: %zu\n", len);

    return 0;
}
