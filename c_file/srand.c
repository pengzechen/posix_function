#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用srand()函数

int main() {
    // 设置随机数种子
    srand((unsigned int)time(NULL));

    // 生成并打印10个随机数
    for (int i = 0; i < 10; i++) {
        printf("%d ", rand());
    }

    printf("\n");

    return 0;
}
