#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用labs()函数

int main() {
    // 测试数值
    long int num = -12345;

    // 使用labs()获取数值的绝对值
    long int abs_num = labs(num);

    // 打印绝对值
    printf("数值 %ld 的绝对值是 %ld。\n", num, abs_num);

    return 0;
}
