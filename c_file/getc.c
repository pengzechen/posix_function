#include <stdio.h>

int main() {
    // ʹ�� getc ��ȡ��׼�����һ���ַ�
    int ch;

    printf("Please enter a character: ");
    ch = getc(stdin); // �� stdin ��ȡһ���ַ�

    // ��ӡ��ȡ���ַ�
    printf("You entered: %c\n", ch);

    // ���������˳�
    return 0;
}
