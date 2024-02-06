#include <stdio.h>

#include <string.h>

int main() {

    char destination[] = "Hello";

    char source[] = "Hello, World!";

    strncpy(destination, source, 5);


    printf("���ƺ���ַ����ǣ�%s\n", destination);

    return 0;

}

