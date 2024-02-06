#include <stdio.h>

#include <string.h>

int main() {

    char destination[] = "Hello";

    char source[] = ", World!";

    strncat(destination, source, 5);

    printf("���Ӻ���ַ����ǣ�%s\n", destination);
    
    return 0;

}

