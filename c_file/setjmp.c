#include <stdio.h>

#include <setjmp.h>


jmp_buf main_buffer;


void do_longjmp(void) {

    printf("start do_longjmp\n");

    longjmp(main_buffer, 1);

    printf(" do_longjmp end\n");

}



int main() {


    if (!setjmp(main_buffer)) {

        printf(" do_longjmp \n");
        do_longjmp();

        printf(" main  longjmp \n");

    } else {

        printf(" main \n");

    }



    return 0;

}

