#include <stdio.h>

#include <string.h>

int main() {

    char src[] = "Hello, World!";

    char dest[20] = "Hello, C!";

    memmove(dest, src, sizeof(src));


    printf("dest: %s\n", dest);

    return 0;

}

