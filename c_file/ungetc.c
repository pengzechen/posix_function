#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

int main() {

    char buffer[100];

    int c;



    // ��ȡ�û�������ַ���

    printf("Enter a string: ");

    fgets(buffer, sizeof(buffer), stdin);



    // ��ȡ����ӡ���һ���ַ�

    c = buffer[strlen(buffer) - 1]; // ���һ���ַ�

    printf("The last character you entered is: %c\n", c);



    // ʹ�� ungetc �����һ���ַ��ƻ�������

    if (ungetc(c, stdin) == EOF) {

        perror("ungetc failed");

        exit(EXIT_FAILURE);

    }



    // �ٴζ�ȡ�û�������ַ���

    printf("Enter another string: ");

    fgets(buffer, sizeof(buffer), stdin);



    // ��ȡ����ӡ����������һ���ַ�

    c = buffer[strlen(buffer) - 1]; // ����������һ���ַ�

    printf("The last character you entered is now: %c\n", c);



    // ���������˳�

    return 0;

}

