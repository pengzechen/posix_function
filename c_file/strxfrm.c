#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <locale.h>



int main() {

    char str1[] = "z";

    char str2[] = "a";

    setlocale(LC_ALL, "");

    size_t len1 = strlen(str1);

    size_t len2 = strlen(str2);

    char *transformed1 = alloca(len1 + 1);

    char *transformed2 = alloca(len2 + 1);



    strxfrm(transformed1, str1, len1);

    strxfrm(transformed2, str2, len2);

    printf("transformed1 %s\n", transformed1);

    printf("transformed2 %s\n", transformed2);


    int result = strcmp(transformed1, transformed2);

    printf("result %d\n", result);



    return 0;

}

