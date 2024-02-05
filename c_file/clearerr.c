#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    int ch;

    // ��ʾ�û������ַ���
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // ����Ƿ����������
    if (feof(stdin)) {
        printf("End of file reached.\n");
    } else if (ferror(stdin)) {
        perror("Read error");
    } else {
        // ��ӡ������ַ���
        printf("You entered: %s", input);
    }

    // ������еĴ����־
    clearerr(stdin);

    // ��ȡһ���ַ�
    ch = getchar();

    // ����Ƿ��д���
    if (feof(stdin)) {
        printf("End of file reached after clearerr().\n");
    } else if (ferror(stdin)) {
        perror("Read error after clearerr().");
    } else {
        // ��ӡ��ȡ���ַ�
        printf("Read character: %c\n", ch);
    }

    return 0;
}
