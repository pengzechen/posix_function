#include <stdio.h>
#include <locale.h> // ����locale.h��ʹ��setlocale()����

int main() {
    // ������������Ϊ������﷨����
    setlocale(LC_ALL, "fr_FR.UTF-8");

    // ��ӡ��ǰ����
    printf("��ǰ�����ǣ�%s\n", strftime(NULL, 0, "%Y-%m-%d", localtime(NULL)));

    return 0;
}
