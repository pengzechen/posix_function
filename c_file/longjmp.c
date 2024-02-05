#include <stdio.h>
#include <setjmp.h>

// ����һ������ת�Ļ�����
jmp_buf my_buffer;

// ����һ��������������ʾlongjmp
void my_function(void) {
    printf("���� my_function\n");
    // ʹ�� longjmp ���ص� setjmp ���õĵط�
    longjmp(my_buffer, 1);
    printf("���� my_function �еĴ��룬�����ᱻִ��\n");
}

int main() {
    // ����һ����Ծ��
    if (!setjmp(my_buffer)) {
        printf("��һ�ε��� my_function ֮ǰ\n");
        // ���� my_function������ʹ�� longjmp ��ת����
        my_function();
        printf("���� main �����еĴ��룬���� longjmp ֮�󲻻ᱻִ��\n");
    } else {
        printf("�ص� main ����\n");
    }

    return 0;
}
