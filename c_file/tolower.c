#include <stdio.h>
#include <ctype.h> // ����tolower()����

int main() {
    // ����һ���ַ�
    char ch = 'A';

    // ʹ��tolower()�������ַ�ת��ΪСд��ĸ
    char lower_case = tolower(ch);

    // ��ӡת�����Сд��ĸ
    printf("ת�����Сд��ĸ�ǣ�%c\n", lower_case);

    return 0;
}
