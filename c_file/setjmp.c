#include <stdio.h>
#include <setjmp.h>

// ����һ������ת�Ļ�����
jmp_buf main_buffer;

// ����һ��������������ʾsetjmp��longjmp
void do_longjmp(void) {
    printf("���� do_longjmp ����\n");
    // ʹ�� longjmp ���ص� setjmp ���õĵط�
    longjmp(main_buffer, 1);
    printf("���� do_longjmp �еĴ��룬�����ᱻִ��\n");
}

int main() {
    // ����һ����Ծ��
    if (!setjmp(main_buffer)) {
        printf("��һ�ε��� do_longjmp ֮ǰ\n");
        // ���� do_longjmp������ʹ�� longjmp ��ת����
        do_longjmp();
        printf("���� main �����еĴ��룬���� longjmp ֮�󲻻ᱻִ��\n");
    } else {
        printf("�ص� main ����\n");
    }

    return 0;
}
