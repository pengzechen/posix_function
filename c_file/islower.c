#include <stdio.h>
#include <ctype.h> // ����ctype.h��ʹ��islower()����

int main() {
    // �����ַ�
    char ch = 'a';

    // ʹ��islower()����ַ��Ƿ���Ӣ��Сд��ĸ
    if (islower(ch)) {
        printf("�ַ� %c ��Ӣ��Сд��ĸ��\n", ch);
    } else {
        printf("�ַ� %c ����Ӣ��Сд��ĸ��\n", ch);
    }

    return 0;
}
