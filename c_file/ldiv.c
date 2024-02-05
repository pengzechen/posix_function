#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用ldiv()函数

int main() {
    // 被除数和除数
    long int numerator = 1234567890;
    long int denominator = 12345;

    // 调用ldiv()进行长整数除法
    ldiv_t result;
    result = ldiv(numerator, denominator);

    // 打印商和余数
    printf("商是 %ld，余数是 %ld。\n", result.quot, result.rem);

    return 0;
}
