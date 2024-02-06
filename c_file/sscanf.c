#include <stdio.h>

#include <stdlib.h> 
#include <string.h>

int main() {

    char input[100];

    int num;

    float floatnum;

    printf("������һ�����������͸��������ַ�����");

    fgets(input, sizeof(input), stdin);


    input[strcspn(input, "\n")] = '\0';


    sscanf(input, "%d %f", &num, &floatnum);


    printf("�����ǣ�%d\n", num);

    printf("�������ǣ�%f\n", floatnum);



    return 0;

}

