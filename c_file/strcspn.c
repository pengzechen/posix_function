#include <stdio.h>

#include <string.h>

int main() {
    char str[] = "Hello, World!";

    char chars_to_ignore[] = "abc";

    int length = strcspn(str, chars_to_ignore);

    printf("����Ϊ��%d\n", length);
    
    return 0;

}

