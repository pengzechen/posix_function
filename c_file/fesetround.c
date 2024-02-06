#include <stdio.h>

#include <fenv.h> 

int main() {

    fenv_t env;

    fesetround(FE_TONEAREST);

    fegetenv(&env);

    printf("��ǰ������ģʽ��FE_TONEAREST\n");

    fesetround(FE_UPWARD); 

    fegetenv(&env);

    printf("�µ�����ģʽ��FE_UPWARD\n");



    return 0;

}

