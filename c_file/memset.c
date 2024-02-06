#include <stdio.h>

#include <string.h> 

int main() {

    char buffer[20];

    memset(buffer, 0, sizeof(buffer));

    printf("���ú���ڴ�������ǣ�%s\n", buffer);

    return 0;
}

