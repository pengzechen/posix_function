#include <stdio.h>

int main() {
    // ʹ�� getchar ��ȡ��׼�����һ���ַ�
    char ch;

    printf("Please enter a character: ");
    ch = getchar(); // �� stdin ��ȡһ���ַ�

    // ��ӡ��ȡ���ַ�
    printf("You entered: %c\n", ch);

    // ���������˳�
    return 0;
}
