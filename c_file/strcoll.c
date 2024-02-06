#include <stdio.h>

#include <locale.h>
#include <string.h>

int main() {


    setlocale(LC_ALL, "en_US.UTF-8"); 

    char str1[] = "Apple";

    char str2[] = "banana";


    int result = strcoll(str1, str2);


    if (result < 0) {


        printf("str1 < str2\n");

    } else if (result > 0) {

        printf("str1 > str2\n");

    } else {

        printf("str1 == str2\n");

    }



    return 0;

}

