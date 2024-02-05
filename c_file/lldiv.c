#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用lldiv()函数

int main() {
    // 被除数和除数
    long long int numerator = 1234567890123456789LL;
    long long int denominator = 12345;

    // 调用lldiv()进行长长整数除法
    lldiv_t result;
    result = lldiv(numerator, denominator);

    // 打印商和余数
    printf("商是 %lld，余数是 %lld。\n", result.quot, result.rem);

    return 0;
}
