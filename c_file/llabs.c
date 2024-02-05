#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用llabs()函数

int main() {
    // 测试长长整数值
    long long int num = -1234567890123456789LL;

    // 使用llabs()获取数值的绝对值
    long long int abs_num = llabs(num);

    // 打印绝对值
    printf("长长整数 %lld 的绝对值是 %lld。\n", num, abs_num);

    return 0;
}
