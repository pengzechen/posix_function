#include <stdio.h>
#include <stdarg.h> // ����vsnprintf()����

int main() {
    char buffer[100]; // ����һ���㹻��Ļ�����

    // ʹ��vsnprintf��ʽ���ַ���
    vsnprintf(buffer, sizeof(buffer), "Hello, %s!", "World");

    // ��ӡ���
    printf("%s\n", buffer);

    return 0;
}
