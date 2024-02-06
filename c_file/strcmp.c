#include <stdio.h>

#include <string.h>

int main() {

    char str1[] = "Hello";

    char str2[] = "World";

    char str3[] = "Hello";

    int result = strcmp(str1, str2);

    if (result < 0) {


        printf("str1 < str2\n");

    } else if (result > 0) {


        printf("str1 > str2\n");

    } else {


        printf("str1 == str2\n");

    }


    result = strcmp(str1, str3);


    if (result < 0) {


        printf("str1 < str3\n");

    } else if (result > 0) {


        printf("str1 > str3\n");

    } else {


        printf("str1 == str3\n");

    }



    return 0;

}

