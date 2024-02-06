#include <stdio.h>

#include <setjmp.h>

jmp_buf my_buffer;


void my_function(void) {

    printf("���� my_function\n");

    longjmp(my_buffer, 1);

    printf("���� my_function �еĴ��룬�����ᱻִ��\n");

}



int main() {


    if (!setjmp(my_buffer)) {

        printf("��һ�ε��� my_function ֮ǰ\n");

        my_function();

        printf("���� main �����еĴ��룬���� longjmp ֮�󲻻ᱻִ��\n");

    } else {

        printf("�ص� main ����\n");

    }



    return 0;

}

