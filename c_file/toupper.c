#include <stdio.h>
#include <ctype.h> // ����toupper()����

int main() {
    // ����һ���ַ�
    char ch = 'a';

    // ʹ��toupper()�������ַ�ת��Ϊ��д��ĸ
    char upper_case = toupper(ch);

    // ��ӡת����Ĵ�д��ĸ
    printf("ת����Ĵ�д��ĸ�ǣ�%c\n", upper_case);

    return 0;
}
