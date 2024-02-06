#include <stdio.h>

#include <stdlib.h> 


int main() {

    char buffer[30];

    snprintf(buffer, sizeof(buffer), "Hello, %s!", "World");

    printf("�������е������ǣ�%s\n", buffer);

    return 0;

}

