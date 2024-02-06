#include <stdio.h>

#include <string.h>



int main() {

    char str1[] = "Hello, World!";

    char str2[] = "Hello";

    size_t len = strspn(str1, str2);

    printf("strspn() returned: %zu\n", len);

    return 0;

}

