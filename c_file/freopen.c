#include <stdio.h>

int main() {
    // ʹ�� freopen �ض����׼����� output.txt �ļ�
    freopen("output.txt", "w", stdout); // �� stdout �ض��� output.txt �ļ�

    // ���� stdout ������� output.txt �ļ���������Ļ
    printf("Hello, World! This is a demo of the freopen function.\n");

    // �ر� output.txt �ļ���
    fclose(stdout);

    // ���������˳�
    return 0;
}
