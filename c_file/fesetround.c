#include <stdio.h>
#include <fenv.h> // ����fenv.h��ʹ��fesetround()����

int main() {
    fenv_t env;

    // ��ȡ��ǰ������ģʽ
    fesetround(FE_TONEAREST); // ���赱ǰ����ģʽ��FE_TONEAREST
    fegetenv(&env);
    printf("��ǰ������ģʽ��FE_TONEAREST\n");

    // �����µ�����ģʽ
    fesetround(FE_UPWARD); // ��������ģʽΪFE_UPWARD

    // ��֤�µ�����ģʽ�Ƿ���Ч
    fegetenv(&env);
    printf("�µ�����ģʽ��FE_UPWARD\n");

    return 0;
}
