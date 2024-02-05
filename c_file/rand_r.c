#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用rand_r()函数

int main() {
    // 定义一个unsigned int类型的变量作为种子
    unsigned int seed = time(NULL);

    // 使用rand_r()生成一个伪随机整数
    unsigned int randomNumber = rand_r(&seed);

    // 打印生成的随机数
    printf("生成的随机数是：%u\n", randomNumber);

    return 0;
}
