#include <stdio.h>

#include <string.h>


int main() {

    char str1[] = "Hello, World!";

    char str2[] = "Hello, World";


    int result = memcmp(str1, str2, sizeof(str1));

    if (result == 0) {

        printf("'%s''%s'\n", str1, str2);

    } else if (result > 0) {

        printf("'%s''%s'\n", str1, str2);

    } else {

        printf("'%s''%s'\n", str1, str2);

    }

    return 0;

}

