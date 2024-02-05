#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用rand()函数

int main() {
    // 生成一个伪随机整数
    int randomNumber = rand();

    // 打印生成的随机数
    printf("生成的随机数是：%d\n", randomNumber);

    return 0;
}
