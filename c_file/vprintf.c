#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    char *ptr;
    int length;
    long count;

    // ��ȡ�û�������ַ���
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin); // ʹ�� fgets �Ա����ȡ���з�

    // ȥ���ַ���ĩβ�Ļ��з�
    input[strcspn(input, "\n")] = '\0';

    // �����ַ�������
    length = strlen(input);

    // �����ַ����������հ��ַ���
    count = 0;
    for (ptr = input; *ptr; ptr++) {
        count++;
    }

    // ʹ�� vprintf ��ӡ�û�������ַ������ַ������ַ�������
    vprintf("You entered: %s\n", input);
    vprintf("The number of characters (including spaces) is: %ld\n", count);
    vprintf("The length of the string is: %d\n", length);

    // ���������˳�
    return 0;
}
