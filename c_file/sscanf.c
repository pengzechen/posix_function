#include <stdio.h>

#include <stdlib.h> // ����stdlib.h��ʹ��malloc()����

#include <string.h>

int main() {

    char input[100];

    int num;

    float floatnum;



    // ��ʾ�û�����һ���ַ���

    printf("������һ�����������͸��������ַ�����");

    fgets(input, sizeof(input), stdin);



    // ȥ�������ַ����Ļ��з�

    input[strcspn(input, "\n")] = '\0';



    // ʹ��sscanf()���ַ����н����������͸�����

    sscanf(input, "%d %f", &num, &floatnum);



    // ��ӡ�������������͸�����

    printf("�����ǣ�%d\n", num);

    printf("�������ǣ�%f\n", floatnum);



    return 0;

}

