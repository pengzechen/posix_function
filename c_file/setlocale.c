#include <stdio.h>

#include <locale.h> // ����locale.h��ʹ��setlocale()����

#include <time.h>

int main() {

    setlocale(LC_ALL, "fr_FR.UTF-8");

    printf("��ǰ�����ǣ�%s\n", strftime(NULL, 0, "%Y-%m-%d", localtime(NULL)));

    return 0;

}

