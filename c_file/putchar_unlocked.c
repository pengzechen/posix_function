#include <stdio.h>

int main() {
    // ��ӡ�ַ�����׼���
    for (char character = 'A'; character <= 'Z'; ++character) {
        putchar_unlocked(character);
    }

    // ��ӡ���з�
    putchar_unlocked('\n');

    // ���������˳�
    return 0;
}
