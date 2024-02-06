#include <stdio.h>

#include <setjmp.h>

jmp_buf my_buffer;


void my_function(void) {

    printf("start my_function\n");

    longjmp(my_buffer, 1);

    printf("end my_function \n");

}



int main() {


    if (!setjmp(my_buffer)) {

        printf("setjmp my_function ֮ǰ\n");

        my_function();

        printf("from main call longjmp\n");

    } else {

        printf(" main \n");

    }



    return 0;

}

