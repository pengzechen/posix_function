#include <stdio.h>

#include <setjmp.h>


jmp_buf main_buffer;


void do_longjmp(void) {

    printf("���� do_longjmp ����\n");

    longjmp(main_buffer, 1);

    printf("���� do_longjmp �еĴ��룬�����ᱻִ��\n");

}



int main() {


    if (!setjmp(main_buffer)) {

        printf("��һ�ε��� do_longjmp ֮ǰ\n");
        do_longjmp();

        printf("���� main �����еĴ��룬���� longjmp ֮�󲻻ᱻִ��\n");

    } else {

        printf("�ص� main ����\n");

    }



    return 0;

}

